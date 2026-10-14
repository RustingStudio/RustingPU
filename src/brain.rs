//! RustingBrain dense networks on the RPU (feature `brain`).
//!
//! The RPU does only the int8 matmul. The host quantizes each batch of activations with one
//! scale, dequantizes (`acc * w_scale[row] * x_scale`), adds the bias and applies the
//! activation. The host int8 path runs the same steps with `quant::matmul_nt_i8`, so both
//! paths give bit-identical outputs. The weights go into RPU memory once, on the first
//! `predict_batch`; each batch then writes only its activations.
use crate::quant::{self, QuantRows};
use crate::{ResidentB, Rpu, RpuError};
use rusting_brain::{Activation, Network};

struct Layer {
    weights: QuantRows,
    biases: Vec<f32>,
    activation: Activation,
}

/// A dense network with its weights quantized once, per output row.
pub struct RpuMlp {
    layers: Vec<Layer>,
    /// Each layer's weights in the memory of one RPU, from beat 0.
    resident: Vec<ResidentB>,
}

impl RpuMlp {
    pub fn from_network(network: &Network) -> Self {
        let layers = network
            .layers()
            .iter()
            .map(|layer| {
                let w = &layer.weights;
                assert_eq!(layer.biases.data.len(), w.rows, "one bias per output");
                Layer {
                    weights: quant::quantize_rows(&w.data, w.rows, w.cols),
                    biases: layer.biases.data.clone(),
                    activation: layer.activation,
                }
            })
            .collect();
        Self {
            layers,
            resident: Vec::new(),
        }
    }

    /// Outputs of the host int8 reference, one `Vec` per input.
    pub fn predict_batch_host(&self, inputs: &[Vec<f32>]) -> Vec<Vec<f32>> {
        self.forward(inputs, |l, a, m| {
            let w = &self.layers[l].weights;
            Ok(quant::matmul_nt_i8(a, &w.data, m, w.rows, w.cols))
        })
        .expect("the host matmul cannot fail")
    }

    /// Outputs with every matmul on the RPU, one `Vec` per input.
    /// The first call uploads the weights; a call with another RPU uploads them again.
    pub fn predict_batch(
        &mut self,
        rpu: &mut Rpu,
        inputs: &[Vec<f32>],
    ) -> Result<Vec<Vec<f32>>, RpuError> {
        if self.resident.first().is_none_or(|b| b.id != rpu.id) {
            let mut base = 0;
            self.resident = self
                .layers
                .iter()
                .map(|layer| {
                    let w = &layer.weights;
                    let b = rpu.upload_b(base, &w.data, w.rows, w.cols);
                    base = b.end();
                    b
                })
                .collect();
        }
        let resident = self.resident.clone();
        let scratch = resident.last().map_or(0, ResidentB::end);
        self.forward(inputs, |l, a, m| {
            rpu.matmul_resident(a, m, &resident[l], scratch)
        })
    }

    fn forward(
        &self,
        inputs: &[Vec<f32>],
        mut matmul: impl FnMut(usize, &[i8], usize) -> Result<Vec<i32>, RpuError>,
    ) -> Result<Vec<Vec<f32>>, RpuError> {
        let m = inputs.len();
        let mut x: Vec<f32> = inputs.concat();
        for (l, layer) in self.layers.iter().enumerate() {
            let (n, k) = (layer.weights.rows, layer.weights.cols);
            assert_eq!(x.len(), m * k, "input width must match the layer");
            let (xq, x_scale) = quant::quantize_tensor(&x);
            let acc = matmul(l, &xq, m)?;
            x = quant::dequantize(&acc, m, n, x_scale, &layer.weights.scales);
            for row in x.chunks_exact_mut(n) {
                for (v, b) in row.iter_mut().zip(&layer.biases) {
                    *v += b;
                }
                layer.activation.apply_to_slice(row);
            }
        }
        let width = x.len() / m.max(1);
        Ok(x.chunks_exact(width.max(1)).map(<[f32]>::to_vec).collect())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn argmax(v: &[f32]) -> usize {
        (0..v.len()).fold(0, |best, i| if v[i] > v[best] { i } else { best })
    }

    #[test]
    fn mlp_784_128_10_rpu_matches_host_int8() {
        let network = Network::builder()
            .input_size(784)
            .dense(128, Activation::Relu)
            .dense(10, Activation::Softmax)
            .seed(0x5eed)
            .build();
        let mut rng = quant::XorShift(0x0b5e_55ed_0064_0784);
        let inputs: Vec<Vec<f32>> = (0..64)
            .map(|_| (0..784).map(|_| rng.f32_sym().abs()).collect())
            .collect();
        let mut mlp = RpuMlp::from_network(&network);
        let mut rpu = Rpu::new().expect("RPU model");

        let host = mlp.predict_batch_host(&inputs);
        let rpu_out = mlp.predict_batch(&mut rpu, &inputs).expect("RPU run");
        assert_eq!(rpu_out, host, "RPU and host int8 must be bit-identical");

        // Later batches reuse the resident weights; another RPU gets its own upload.
        let more: Vec<Vec<f32>> = (0..20)
            .map(|_| (0..784).map(|_| rng.f32_sym().abs()).collect())
            .collect();
        let written = rpu.host_words_written();
        assert_eq!(
            mlp.predict_batch(&mut rpu, &more).unwrap(),
            mlp.predict_batch_host(&more)
        );
        // Layer 1 weights alone are 128 x 784 bytes; 20 inputs are far less.
        let weight_words = 128 * 784 / 8;
        assert!(
            rpu.host_words_written() - written < weight_words,
            "weights were rewritten"
        );
        let mut other = Rpu::new().expect("RPU model");
        assert_eq!(
            mlp.predict_batch(&mut other, &more).unwrap(),
            mlp.predict_batch_host(&more)
        );

        // The int8 path must still follow the f32 network.
        let float = network.predict_batch(&inputs).expect("f32 run");
        let agree = (0..64)
            .filter(|&i| argmax(&host[i]) == argmax(&float[i]))
            .count();
        let max_diff = host
            .iter()
            .flatten()
            .zip(float.iter().flatten())
            .fold(0.0f32, |d, (a, b)| d.max((a - b).abs()));
        println!("int8 vs f32: argmax agree {agree}/64, max |p diff| {max_diff}");
        assert!(agree >= 60, "int8 argmax agrees with f32 on {agree}/64");
        assert!(
            max_diff < 0.02,
            "int8 probabilities differ from f32 by {max_diff}"
        );
    }
}
