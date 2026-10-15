//! RustingBrain dense networks on the RPU (feature `brain`).
//!
//! The host quantizes the input batch with one scale. A layer without a calibrated output
//! scale runs only the int8 matmul on the RPU; the host reads C, dequantizes
//! (`acc * w_scale[row] * x_scale`), adds the bias, applies the activation and quantizes
//! again. After [`RpuMlp::calibrate`], each ReLU or linear layer except the last one is
//! fused: the RPU adds the bias, applies ReLU and requantizes to the static output scale,
//! and the int8 output stays in RPU memory as the next layer's A. The host int8 path runs
//! the same steps with `quant::matmul_nt_i8` and [`Requant::apply`], so both paths give
//! bit-identical outputs. The weights go into RPU memory once, on the first
//! `predict_batch`. [`RpuMlp::predict_batches`] starts the next batch while the last GEMM
//! of a batch runs.
use crate::quant::{self, QuantRows, Requant};
use crate::{
    panel_beats, ResidentA, ResidentB, ResidentC, Rpu, RpuError, C_BEATS, LOAD_BEATS, TILE,
};
use rusting_brain::{Activation, Network};

struct Layer {
    weights: QuantRows,
    biases: Vec<f32>,
    activation: Activation,
    /// The static output scale of a fused layer, set by [`RpuMlp::calibrate`].
    out_scale: Option<f32>,
}

/// A dense network with its weights quantized once, per output row.
pub struct RpuMlp {
    layers: Vec<Layer>,
    /// Each layer's weights in the memory of one RPU, from beat 0.
    resident: Vec<ResidentB>,
}

/// Where the int8 GEMMs of [`RpuMlp::forward`] run. `Act` is an `m x k` int8 activation,
/// `Acc` an int32 matmul that may still run.
trait Backend {
    type Act;
    type Acc;
    /// Batch `b` begins: its activations may go elsewhere than those of batch `b - 1`.
    fn batch(&mut self, _b: usize) {}
    fn upload(&mut self, x: Vec<i8>, m: usize, k: usize) -> Self::Act;
    fn matmul(&mut self, l: usize, x: &Self::Act) -> Result<Self::Acc, RpuError>;
    fn finish(&mut self, acc: Self::Acc) -> Result<Vec<i32>, RpuError>;
    fn requant(
        &mut self,
        l: usize,
        x: &Self::Act,
        params: &[Requant],
    ) -> Result<Self::Act, RpuError>;
}

struct Host<'a>(&'a [Layer]);

impl Backend for Host<'_> {
    type Act = (Vec<i8>, usize);
    type Acc = Vec<i32>;

    fn upload(&mut self, x: Vec<i8>, m: usize, _k: usize) -> Self::Act {
        (x, m)
    }

    fn matmul(&mut self, l: usize, (x, m): &Self::Act) -> Result<Vec<i32>, RpuError> {
        let w = &self.0[l].weights;
        Ok(quant::matmul_nt_i8(x, &w.data, *m, w.rows, w.cols))
    }

    fn finish(&mut self, acc: Vec<i32>) -> Result<Vec<i32>, RpuError> {
        Ok(acc)
    }

    fn requant(
        &mut self,
        l: usize,
        x: &Self::Act,
        params: &[Requant],
    ) -> Result<Self::Act, RpuError> {
        let acc = self.matmul(l, x)?;
        let y = acc
            .chunks_exact(params.len())
            .flat_map(|row| row.iter().zip(params).map(|(&v, q)| q.apply(v)))
            .collect();
        Ok((y, x.1))
    }
}

/// The activations of batch `b` go to RPU memory from beat `slots[b % 2]` on, each GEMM
/// output right after its input, so one batch may start while the last GEMM of the batch
/// before runs.
struct OnRpu<'a> {
    rpu: &'a mut Rpu,
    weights: &'a [ResidentB],
    slots: [u32; 2],
    next: u32,
}

impl Backend for OnRpu<'_> {
    type Act = ResidentA;
    type Acc = ResidentC;

    fn batch(&mut self, b: usize) {
        self.next = self.slots[b % 2];
    }

    fn upload(&mut self, x: Vec<i8>, m: usize, k: usize) -> ResidentA {
        let a = self.rpu.upload_a(self.next, &x, m, k);
        self.next = a.end();
        a
    }

    fn matmul(&mut self, l: usize, x: &ResidentA) -> Result<ResidentC, RpuError> {
        self.rpu.start_gemm_i32(x, &self.weights[l], x.end())
    }

    fn finish(&mut self, acc: ResidentC) -> Result<Vec<i32>, RpuError> {
        self.rpu.read_i32(&acc)
    }

    fn requant(
        &mut self,
        l: usize,
        x: &ResidentA,
        params: &[Requant],
    ) -> Result<ResidentA, RpuError> {
        let y = self
            .rpu
            .gemm_requant(x, &self.weights[l], params, x.end())?;
        self.next = y.end();
        Ok(y)
    }
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
                    out_scale: None,
                }
            })
            .collect();
        Self {
            layers,
            resident: Vec::new(),
        }
    }

    /// Fixes the output scale of every ReLU or linear layer except the last one to
    /// `absmax / 127` of its outputs on `inputs` (in the unfused host int8 path), and fuses
    /// those layers from then on. Larger outputs later saturate at 127.
    pub fn calibrate(&mut self, inputs: &[Vec<f32>]) {
        for layer in &mut self.layers {
            layer.out_scale = None;
        }
        let mut absmax = vec![0.0f32; self.layers.len()];
        self.forward(
            &mut Host(&self.layers),
            inputs,
            inputs.len(),
            &mut |l, y| {
                absmax[l] = y.iter().fold(absmax[l], |a, v| a.max(v.abs()));
            },
        )
        .expect("the host matmul cannot fail");
        let last = self.layers.len().saturating_sub(1);
        for (l, layer) in self.layers.iter_mut().enumerate().take(last) {
            if matches!(layer.activation, Activation::Relu | Activation::Linear) {
                layer.out_scale = Some(absmax[l] / 127.0);
            }
        }
    }

    /// Outputs of the host int8 reference, one `Vec` per input.
    pub fn predict_batch_host(&self, inputs: &[Vec<f32>]) -> Vec<Vec<f32>> {
        self.forward(
            &mut Host(&self.layers),
            inputs,
            inputs.len(),
            &mut |_, _| {},
        )
        .expect("the host matmul cannot fail")
    }

    /// Outputs with every matmul on the RPU, one `Vec` per input.
    /// The first call uploads the weights; a call with another RPU uploads them again.
    pub fn predict_batch(
        &mut self,
        rpu: &mut Rpu,
        inputs: &[Vec<f32>],
    ) -> Result<Vec<Vec<f32>>, RpuError> {
        self.predict_batches(rpu, inputs, inputs.len())
    }

    /// [`RpuMlp::predict_batch`] on each `batch` inputs in turn, each quantized with its
    /// own scale. A batch starts while the last GEMM of the batch before runs.
    pub fn predict_batches(
        &mut self,
        rpu: &mut Rpu,
        inputs: &[Vec<f32>],
        batch: usize,
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
        let batch = batch.max(1);
        let slot0 = self.resident.last().map_or(0, ResidentB::end);
        let slot1 =
            (slot0 + self.batch_beats(batch.min(inputs.len()))).next_multiple_of(LOAD_BEATS as u32);
        let mut backend = OnRpu {
            rpu,
            weights: &self.resident,
            slots: [slot0, slot1],
            next: slot0,
        };
        self.forward(&mut backend, inputs, batch, &mut |_, _| {})
    }

    /// RPU memory beats that the activations and C of `m` inputs take at most.
    fn batch_beats(&self, m: usize) -> u32 {
        let mt = m.div_ceil(TILE) as u32;
        let last = self.layers.len() - 1;
        self.layers
            .iter()
            .enumerate()
            .map(|(l, layer)| {
                let w = &layer.weights;
                let c = if l == last || layer.out_scale.is_none() {
                    w.rows.div_ceil(TILE) as u32 * C_BEATS
                } else {
                    0
                };
                mt * (panel_beats(w.cols) + c)
            })
            .sum()
    }

    /// Runs `inputs` in batches of `batch`, each quantized with its own scale. The host
    /// prepares batch b + 1 and starts its first GEMM before it reads the last layer of
    /// batch b. `observe(l, y)` sees the float output of each unfused layer.
    fn forward<B: Backend>(
        &self,
        backend: &mut B,
        inputs: &[Vec<f32>],
        batch: usize,
        observe: &mut impl FnMut(usize, &[f32]),
    ) -> Result<Vec<Vec<f32>>, RpuError> {
        let last = self.layers.len() - 1;
        assert!(
            self.layers[last].out_scale.is_none(),
            "the last layer must not be fused"
        );
        let mut batches = inputs.chunks(batch.max(1)).enumerate();
        let cols = self.layers[0].weights.cols;
        let upload = |backend: &mut B, (b, x): (usize, &[Vec<f32>])| {
            assert!(
                x.iter().all(|v| v.len() == cols),
                "input width must match the layer"
            );
            backend.batch(b);
            Staged::upload(backend, &x.concat(), x.len())
        };
        let Some(first) = batches.next() else {
            return Ok(Vec::new());
        };
        let first = upload(backend, first);
        let mut staged = self.hidden(backend, first, observe)?;
        let mut out = Vec::with_capacity(inputs.len());
        loop {
            let next = batches.next().map(|x| upload(backend, x));
            let acc = backend.matmul(last, &staged.a)?;
            let next = next.map(|s| self.hidden(backend, s, observe)).transpose()?;
            let y = self.output(backend, last, acc, &staged, observe)?;
            out.extend(
                y.chunks_exact(self.layers[last].weights.rows)
                    .map(<[f32]>::to_vec),
            );
            match next {
                Some(s) => staged = s,
                None => return Ok(out),
            }
        }
    }

    /// Runs every layer but the last one.
    fn hidden<B: Backend>(
        &self,
        backend: &mut B,
        mut s: Staged<B::Act>,
        observe: &mut impl FnMut(usize, &[f32]),
    ) -> Result<Staged<B::Act>, RpuError> {
        for (l, layer) in self.layers[..self.layers.len() - 1].iter().enumerate() {
            let w = &layer.weights;
            if let Some(y_scale) = layer.out_scale {
                let relu = layer.activation == Activation::Relu;
                let params: Vec<Requant> = (0..w.rows)
                    .map(|j| Requant::new(s.scale * w.scales[j], layer.biases[j], y_scale, relu))
                    .collect();
                s.a = backend.requant(l, &s.a, &params)?;
                s.scale = y_scale;
            } else {
                let acc = backend.matmul(l, &s.a)?;
                let y = self.output(backend, l, acc, &s, observe)?;
                s = Staged::upload(backend, &y, s.m);
            }
        }
        Ok(s)
    }

    /// The float output of unfused layer `l`: dequantized, biased, activated.
    fn output<B: Backend>(
        &self,
        backend: &mut B,
        l: usize,
        acc: B::Acc,
        s: &Staged<B::Act>,
        observe: &mut impl FnMut(usize, &[f32]),
    ) -> Result<Vec<f32>, RpuError> {
        let layer = &self.layers[l];
        let w = &layer.weights;
        let acc = backend.finish(acc)?;
        let mut y = quant::dequantize(&acc, s.m, w.rows, s.scale, &w.scales);
        for row in y.chunks_exact_mut(w.rows) {
            for (v, b) in row.iter_mut().zip(&layer.biases) {
                *v += b;
            }
            layer.activation.apply_to_slice(row);
        }
        observe(l, &y);
        Ok(y)
    }
}

/// The int8 input `a` (`m` rows) of the next layer and its scale.
struct Staged<A> {
    a: A,
    m: usize,
    scale: f32,
}

impl<A> Staged<A> {
    fn upload<B: Backend<Act = A>>(backend: &mut B, x: &[f32], m: usize) -> Self {
        let (xq, scale) = quant::quantize_tensor(x);
        let k = x.len() / m;
        Staged {
            a: backend.upload(xq, m, k),
            m,
            scale,
        }
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

    /// Batches pipelined on one RPU give what the host gives on each batch, with hidden
    /// layers on the host or fused, and a short last batch.
    #[test]
    fn predict_batches_matches_the_host_batch_by_batch() {
        let network = Network::builder()
            .input_size(100)
            .dense(40, Activation::Relu)
            .dense(30, Activation::Linear)
            .dense(10, Activation::Linear)
            .seed(0xba7c)
            .build();
        let mut rng = quant::XorShift(0xba7c_0000_0000_0020);
        let inputs: Vec<Vec<f32>> = (0..3 * crate::TILE + 5)
            .map(|_| (0..100).map(|_| 4.0 * rng.f32_sym()).collect())
            .collect();
        let mut mlp = RpuMlp::from_network(&network);
        let mut rpu = Rpu::new().expect("RPU model");
        for calibrated in [false, true] {
            if calibrated {
                mlp.calibrate(&inputs);
            }
            let batch = crate::TILE + 1;
            let host: Vec<Vec<f32>> = inputs
                .chunks(batch)
                .flat_map(|c| mlp.predict_batch_host(c))
                .collect();
            let rpu_out = mlp.predict_batches(&mut rpu, &inputs, batch).unwrap();
            assert_eq!(rpu_out, host, "calibrated {calibrated}");
        }
    }

    #[test]
    fn calibrated_mlp_keeps_hidden_activations_on_the_rpu() {
        let network = Network::builder()
            .input_size(100)
            .dense(40, Activation::Relu)
            .dense(30, Activation::Linear)
            .dense(10, Activation::Linear)
            .seed(0xca1)
            .build();
        let mut rng = quant::XorShift(0xca1b_0000_0000_0001);
        let mut batch = |m: usize| -> Vec<Vec<f32>> {
            (0..m)
                .map(|_| (0..100).map(|_| 4.0 * rng.f32_sym()).collect())
                .collect()
        };
        let (calib, inputs) = (batch(50), batch(2 * crate::TILE + 3));
        let mut mlp = RpuMlp::from_network(&network);
        mlp.calibrate(&calib);
        let fused: Vec<bool> = mlp.layers.iter().map(|l| l.out_scale.is_some()).collect();
        assert_eq!(fused, [true, true, false]);

        let mut rpu = Rpu::new().expect("RPU model");
        mlp.predict_batch(&mut rpu, &inputs).expect("RPU run");
        let read = rpu.host_words_read();
        let host = mlp.predict_batch_host(&inputs);
        assert_eq!(mlp.predict_batch(&mut rpu, &inputs).unwrap(), host);
        // Only the last layer's C rows come back, and of each row the beats of 10 columns.
        let row_beats: usize = (0..10usize.div_ceil(crate::TILE))
            .map(|j| crate::c_row_beats(crate::TILE.min(10 - j * crate::TILE)))
            .sum();
        let c_words = (inputs.len() * row_beats) as u64 * u64::from(crate::BEAT_WORDS);
        assert_eq!(rpu.host_words_read() - read, c_words);

        let float = network.predict_batch(&inputs).expect("f32 run");
        let agree = (0..inputs.len())
            .filter(|&i| argmax(&host[i]) == argmax(&float[i]))
            .count();
        assert!(agree * 10 >= inputs.len() * 9, "argmax agrees on {agree}");

        // Calibrated on the inputs themselves, the static scales are the per-batch scales of
        // the unfused path, so both paths must agree up to the rounding of the hidden
        // activations (measured: equal). Random biases, since the network has none. Inputs
        // past the calibration range saturate; that error is the cost of static scales.
        let biased = || {
            let mut rng = quant::XorShift(7);
            let mut mlp = RpuMlp::from_network(&network);
            for b in mlp.layers.iter_mut().flat_map(|l| &mut l.biases) {
                *b = rng.f32_sym();
            }
            mlp
        };
        let (mut fused, unfused) = (biased(), biased());
        fused.calibrate(&inputs);
        let (f, u) = (
            fused.predict_batch_host(&inputs),
            unfused.predict_batch_host(&inputs),
        );
        let absmax = u.iter().flatten().fold(0.0f32, |a, v| a.max(v.abs()));
        let diff = f
            .iter()
            .flatten()
            .zip(u.iter().flatten())
            .fold(0.0f32, |d, (a, b)| d.max((a - b).abs()));
        assert!(
            diff <= 0.01 * absmax,
            "fused and unfused differ by {diff} of {absmax}"
        );
    }
}
