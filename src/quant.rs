//! Host int8 reference: the quantization rules and the exact int8 GEMM the RPU must match.
//!
//! Weights get one symmetric scale per row, the same rule as RustingBrain `quantized.rs`:
//! `scale = absmax / 127`, `q = round(w / scale)` clamped to [-127, 127]. Activations get one
//! symmetric scale for the whole batch. The GEMM is NT: `C[i][j] = sum_k A[i][k] * B[j][k]`,
//! so a `[out, in]` weight matrix is used as B without a transpose.

/// A row-major `[rows, cols]` int8 matrix with one scale per row.
#[derive(Debug, Clone, PartialEq)]
pub struct QuantRows {
    pub rows: usize,
    pub cols: usize,
    pub data: Vec<i8>,
    pub scales: Vec<f32>,
}

/// The RustingBrain rule for one value. A zero scale (all-zero input) gives zero.
fn quantize_one(value: f32, inverse: f32) -> i8 {
    (value * inverse).round().clamp(-127.0, 127.0) as i8
}

fn absmax_scale(values: &[f32]) -> (f32, f32) {
    let absmax = values.iter().fold(0.0f32, |acc, v| acc.max(v.abs()));
    let scale = absmax / 127.0;
    let inverse = if scale > 0.0 { 1.0 / scale } else { 0.0 };
    (scale, inverse)
}

/// Per-row symmetric int8 quantization of a row-major `[rows, cols]` matrix.
pub fn quantize_rows(data: &[f32], rows: usize, cols: usize) -> QuantRows {
    assert_eq!(data.len(), rows * cols, "data length must be rows * cols");
    let mut out = Vec::with_capacity(data.len());
    let mut scales = Vec::with_capacity(rows);
    for row in data.chunks_exact(cols.max(1)).take(rows) {
        let (scale, inverse) = absmax_scale(row);
        scales.push(scale);
        out.extend(row.iter().map(|&v| quantize_one(v, inverse)));
    }
    QuantRows {
        rows,
        cols,
        data: out,
        scales,
    }
}

/// One symmetric int8 scale for all values, e.g. one batch of activations.
pub fn quantize_tensor(data: &[f32]) -> (Vec<i8>, f32) {
    let (scale, inverse) = absmax_scale(data);
    (
        data.iter().map(|&v| quantize_one(v, inverse)).collect(),
        scale,
    )
}

/// `C[m, n] = A[m, k] * B[n, k]^T` in exact int32. Overflow cannot happen for k <= 2^17 with
/// symmetric int8 inputs (|a*b| <= 127^2).
pub fn matmul_nt_i8(a: &[i8], b: &[i8], m: usize, n: usize, k: usize) -> Vec<i32> {
    assert_eq!(a.len(), m * k, "A must be m * k");
    assert_eq!(b.len(), n * k, "B must be n * k");
    let mut c = vec![0i32; m * n];
    for i in 0..m {
        let a_row = &a[i * k..(i + 1) * k];
        for j in 0..n {
            let b_row = &b[j * k..(j + 1) * k];
            c[i * n + j] = a_row
                .iter()
                .zip(b_row)
                .map(|(&x, &y)| i32::from(x) * i32::from(y))
                .sum();
        }
    }
    c
}

/// `out[i][j] = acc[i][j] * b_scales[j] * a_scale`, the float result of an NT GEMM.
pub fn dequantize(acc: &[i32], m: usize, n: usize, a_scale: f32, b_scales: &[f32]) -> Vec<f32> {
    assert_eq!(acc.len(), m * n, "acc must be m * n");
    assert_eq!(b_scales.len(), n, "one scale per column of C");
    acc.chunks_exact(n.max(1))
        .take(m)
        .flat_map(|row| {
            row.iter()
                .zip(b_scales)
                .map(move |(&v, &s)| v as f32 * s * a_scale)
        })
        .collect()
}

/// Tiny seeded xorshift64 for tests, so no `rand` dependency is needed.
#[cfg(test)]
pub(crate) struct XorShift(pub u64);

#[cfg(test)]
impl XorShift {
    pub fn next_u64(&mut self) -> u64 {
        self.0 ^= self.0 << 13;
        self.0 ^= self.0 >> 7;
        self.0 ^= self.0 << 17;
        self.0
    }

    /// Uniform in [-127, 127], with the edge values -127, 0 and 127 forced often.
    pub fn i8_sym(&mut self) -> i8 {
        match self.next_u64() % 16 {
            0 => -127,
            1 => 127,
            2 => 0,
            _ => ((self.next_u64() % 255) as i16 - 127) as i8,
        }
    }

    /// Uniform in [-1, 1).
    pub fn f32_sym(&mut self) -> f32 {
        (self.next_u64() >> 40) as f32 / (1u64 << 23) as f32 - 1.0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn matmul_nt_i8_equals_naive_i64() {
        let mut rng = XorShift(0x9e37_79b9_7f4a_7c15);
        for &(m, n, k) in &[(1, 1, 1), (8, 8, 8), (3, 5, 7), (8, 16, 784), (9, 10, 1024)] {
            let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
            let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
            let c = matmul_nt_i8(&a, &b, m, n, k);
            for i in 0..m {
                for j in 0..n {
                    let naive: i64 = (0..k)
                        .map(|p| i64::from(a[i * k + p]) * i64::from(b[j * k + p]))
                        .sum();
                    assert_eq!(
                        i64::from(c[i * n + j]),
                        naive,
                        "({m},{n},{k}) at [{i}][{j}]"
                    );
                }
            }
        }
    }

    #[test]
    fn all_minus_127_does_not_overflow_at_k_1024() {
        let a = vec![-127i8; 1024];
        let b = vec![-127i8; 1024];
        assert_eq!(matmul_nt_i8(&a, &b, 1, 1, 1024), vec![127 * 127 * 1024]);
    }

    #[test]
    fn quantize_rows_roundtrip_error_is_at_most_half_a_step() {
        let mut rng = XorShift(42);
        let (rows, cols) = (16, 100);
        let data: Vec<f32> = (0..rows * cols).map(|_| rng.f32_sym() * 3.0).collect();
        let q = quantize_rows(&data, rows, cols);
        for r in 0..rows {
            let scale = q.scales[r];
            for c in 0..cols {
                let back = f32::from(q.data[r * cols + c]) * scale;
                let err = (back - data[r * cols + c]).abs();
                assert!(
                    err <= scale * 0.5 * (1.0 + 1e-5),
                    "row {r} col {c}: {err} > {scale}/2"
                );
            }
        }
    }

    #[test]
    fn quantize_tensor_roundtrip_error_is_at_most_half_a_step() {
        let mut rng = XorShift(7);
        let data: Vec<f32> = (0..1000).map(|_| rng.f32_sym() * 0.25).collect();
        let (q, scale) = quantize_tensor(&data);
        assert!(q.iter().any(|&v| v.abs() == 127));
        for (&v, &x) in q.iter().zip(&data) {
            assert!((f32::from(v) * scale - x).abs() <= scale * 0.5 * (1.0 + 1e-5));
        }
    }

    #[test]
    fn zero_rows_get_zero_scale() {
        let q = quantize_rows(&[0.0; 4], 2, 2);
        assert_eq!(q.scales, vec![0.0, 0.0]);
        assert_eq!(q.data, vec![0; 4]);
    }

    #[test]
    fn dequantize_scales_by_row_of_b_and_batch_scale() {
        let out = dequantize(&[2, -3, 4, 5], 2, 2, 0.5, &[1.0, 10.0]);
        assert_eq!(out, vec![1.0, -15.0, 2.0, 25.0]);
    }
}
