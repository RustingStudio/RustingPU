pub const TILE: usize = 8;
pub const DIM: usize = TILE;
pub type Matrix = [[f32; TILE]; TILE];
pub type Bf16Matrix = [[BFloat16; TILE]; TILE];
pub type Bf16Tile = [BFloat16; TILE * TILE];

use std::fmt;
use std::ptr::NonNull;

const REG_CONTROL: u16 = 0x0000;
const REG_STATUS: u16 = 0x0001;
const REG_A_BASE: u16 = 0x0002;
const REG_B_BASE: u16 = 0x0003;
const REG_C_BASE: u16 = 0x0004;

const EXT_BASE_BANK0: u16 = 0x1000;
const EXT_BASE_BANK1: u16 = 0x2000;

const TILE_WORDS: u16 = (TILE * TILE) as u16;
const CONTROL_START: u16 = 0b0001;
const CONTROL_BANK1: u16 = 0b0010;
const CONTROL_PRELOAD: u16 = 0b0100;
const STATUS_LOAD_BUSY: u16 = 0b0100;
const STATUS_COMPUTE_BUSY: u16 = 0b1000;

mod sys {
    #[repr(C)]
    pub struct Rpu(std::ffi::c_void);

    extern "C" {
        pub fn rpu_new() -> *mut Rpu;
        pub fn rpu_free(r: *mut Rpu);
        pub fn rpu_reset(r: *mut Rpu);
        pub fn rpu_tick(r: *mut Rpu);
        pub fn rpu_cycles(r: *mut Rpu) -> u32;
        pub fn rpu_write(r: *mut Rpu, addr: u16, value: u16);
        pub fn rpu_read(r: *mut Rpu, addr: u16) -> u16;
        pub fn rpu_busy(r: *mut Rpu) -> u8;
        pub fn rpu_done(r: *mut Rpu) -> u8;
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct BFloat16(u16);

impl BFloat16 {
    pub const ZERO: Self = Self(0);

    pub const fn from_bits(bits: u16) -> Self {
        Self(bits)
    }

    pub const fn to_bits(self) -> u16 {
        self.0
    }

    pub fn from_f32(value: f32) -> Result<Self, RpuError> {
        if !value.is_finite() {
            return Err(RpuError::NonFiniteInput(value));
        }

        let bits = value.to_bits();
        let lsb = (bits >> 16) & 1;
        let rounding_bias = 0x7fff + lsb;
        let bf16 = ((bits.wrapping_add(rounding_bias)) >> 16) as u16;
        let exp = (bf16 >> 7) & 0xff;
        let fraction = bf16 & 0x7f;

        if exp == 0 && fraction != 0 {
            return Err(RpuError::UnsupportedSubnormal(value));
        }

        Ok(Self(bf16))
    }

    pub fn to_f32(self) -> f32 {
        f32::from_bits((self.0 as u32) << 16)
    }
}

#[derive(Debug, Clone, PartialEq)]
pub enum RpuError {
    AllocationFailed,
    NonFiniteInput(f32),
    UnsupportedSubnormal(f32),
    Timeout { max_cycles: usize },
}

impl fmt::Display for RpuError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::AllocationFailed => write!(f, "failed to allocate RPU model"),
            Self::NonFiniteInput(value) => {
                write!(
                    f,
                    "RPU BF16 model does not support non-finite input {value}"
                )
            }
            Self::UnsupportedSubnormal(value) => {
                write!(f, "RPU BF16 model does not support subnormal input {value}")
            }
            Self::Timeout { max_cycles } => {
                write!(f, "RPU did not finish within {max_cycles} cycles")
            }
        }
    }
}

impl std::error::Error for RpuError {}

pub struct Rpu {
    inner: NonNull<sys::Rpu>,
}

pub struct DynMatrix {
    pub rows: usize,
    pub cols: usize,
    pub data: Vec<f32>,
}

struct TileJob {
    tile_row: usize,
    tile_col: usize,
    a: Bf16Tile,
    b: Bf16Tile,
}

impl fmt::Display for DynMatrix {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for r in 0..self.rows {
            write!(f, "[ ")?;
            for c in 0..self.cols {
                write!(f, "{:>8.3} ", self.data[r * self.cols + c])?;
            }
            writeln!(f, "]")?;
        }
        Ok(())
    }
}

impl Rpu {
    const MAX_WAIT_CYCLES: usize = 4096;

    pub fn new() -> Result<Self, RpuError> {
        let inner = NonNull::new(unsafe { sys::rpu_new() }).ok_or(RpuError::AllocationFailed)?;
        let mut rpu = Self { inner };
        rpu.reset();
        Ok(rpu)
    }

    pub fn reset(&mut self) {
        unsafe { sys::rpu_reset(self.inner.as_ptr()) };
    }

    pub fn cycles(&self) -> u32 {
        unsafe { sys::rpu_cycles(self.inner.as_ptr()) }
    }

    pub fn multiply(&mut self, a: Matrix, b: Matrix) -> Result<Matrix, RpuError> {
        let a = Self::encode_matrix(a)?;
        let b = Self::encode_matrix(b)?;
        let c = self.multiply_bf16(a, b)?;
        Ok(Self::decode_matrix(c))
    }

    pub fn multiply_bf16(&mut self, a: Bf16Matrix, b: Bf16Matrix) -> Result<Bf16Matrix, RpuError> {
        let a_tile = Self::flatten_tile(a);
        let b_tile = Self::flatten_tile(b);
        let c_tile = self.run_tile(a_tile, b_tile)?;
        Ok(Self::unflatten_tile(c_tile))
    }

    pub fn multiply_dyn(&mut self, a: &DynMatrix, b: &DynMatrix) -> Result<DynMatrix, RpuError> {
        assert_eq!(a.cols, b.rows, "A.cols must equal B.rows");

        let m_tiles = a.rows.div_ceil(TILE);
        let k_tiles = a.cols.div_ceil(TILE);
        let n_tiles = b.cols.div_ceil(TILE);

        let c_stride = n_tiles * TILE;
        let mut c_data = vec![0.0_f32; m_tiles * TILE * c_stride];
        let mut jobs = Vec::new();

        for ti in 0..m_tiles {
            for tk in 0..k_tiles {
                let mut a_tile_bf16 = [BFloat16::ZERO; TILE * TILE];
                Self::fill_tile(&a.data, a.rows, a.cols, ti, tk, &mut a_tile_bf16);

                for tj in 0..n_tiles {
                    let mut b_tile_bf16 = [BFloat16::ZERO; TILE * TILE];
                    Self::fill_tile(&b.data, b.rows, b.cols, tk, tj, &mut b_tile_bf16);
                    jobs.push(TileJob {
                        tile_row: ti,
                        tile_col: tj,
                        a: a_tile_bf16,
                        b: b_tile_bf16,
                    });
                }
            }
        }

        self.run_tile_jobs_pipelined(&jobs, &mut c_data, c_stride, a.rows, b.cols)?;

        let mut result = vec![0.0_f32; a.rows * b.cols];
        for r in 0..a.rows {
            for c in 0..b.cols {
                result[r * b.cols + c] = c_data[r * (n_tiles * TILE) + c];
            }
        }

        Ok(DynMatrix {
            rows: a.rows,
            cols: b.cols,
            data: result,
        })
    }

    fn fill_tile(
        src: &[f32],
        src_rows: usize,
        src_cols: usize,
        tile_row: usize,
        tile_col: usize,
        out: &mut [BFloat16; TILE * TILE],
    ) {
        for r in 0..TILE {
            for c in 0..TILE {
                let global_r = tile_row * TILE + r;
                let global_c = tile_col * TILE + c;
                if global_r < src_rows && global_c < src_cols {
                    let val = BFloat16::from_f32(src[global_r * src_cols + global_c]).unwrap();
                    out[r * TILE + c] = val;
                } else {
                    out[r * TILE + c] = BFloat16::ZERO;
                }
            }
        }
    }
    pub fn run_tile(&mut self, a: Bf16Tile, b: Bf16Tile) -> Result<Bf16Tile, RpuError> {
        let c_base = 2 * TILE_WORDS;

        self.preload_tile(0, a, b)?;
        self.start_preloaded_tile(0, c_base);
        self.wait_until_done(Self::MAX_WAIT_CYCLES)?;
        Ok(self.read_tile_output(0, c_base))
    }

    pub fn preload_tile(&mut self, bank: usize, a: Bf16Tile, b: Bf16Tile) -> Result<(), RpuError> {
        let a_base = 0;
        let b_base = TILE_WORDS;
        let c_base = 2 * TILE_WORDS;

        self.write_tile_inputs(bank, a_base, b_base, &a, &b);
        self.configure_bases(a_base, b_base, c_base);
        self.write_control(bank, CONTROL_PRELOAD);
        self.tick();
        self.wait_until_load_idle(Self::MAX_WAIT_CYCLES)
    }

    fn start_preloaded_tile(&mut self, bank: usize, c_base: u16) {
        let a_base = 0;
        let b_base = TILE_WORDS;

        self.configure_bases(a_base, b_base, c_base);
        self.write_control(bank, CONTROL_START);
        self.tick();
    }

    fn run_tile_jobs_pipelined(
        &mut self,
        jobs: &[TileJob],
        c_data: &mut [f32],
        c_stride: usize,
        rows: usize,
        cols: usize,
    ) -> Result<(), RpuError> {
        if jobs.is_empty() {
            return Ok(());
        }

        let c_base = 2 * TILE_WORDS;
        let mut active_bank = 0;
        let mut active_job = 0;

        self.preload_tile(active_bank, jobs[active_job].a, jobs[active_job].b)?;
        self.start_preloaded_tile(active_bank, c_base);

        for next_job in 1..jobs.len() {
            let next_bank = 1 - active_bank;
            self.preload_tile(next_bank, jobs[next_job].a, jobs[next_job].b)?;
            self.wait_until_done(Self::MAX_WAIT_CYCLES)?;
            let result_tile = self.read_tile_output(active_bank, c_base);
            Self::accumulate_tile(
                &jobs[active_job],
                &result_tile,
                c_data,
                c_stride,
                rows,
                cols,
            );

            active_bank = next_bank;
            active_job = next_job;
            self.start_preloaded_tile(active_bank, c_base);
        }

        self.wait_until_done(Self::MAX_WAIT_CYCLES)?;
        let result_tile = self.read_tile_output(active_bank, c_base);
        Self::accumulate_tile(
            &jobs[active_job],
            &result_tile,
            c_data,
            c_stride,
            rows,
            cols,
        );

        Ok(())
    }

    fn accumulate_tile(
        job: &TileJob,
        result_tile: &Bf16Tile,
        c_data: &mut [f32],
        c_stride: usize,
        rows: usize,
        cols: usize,
    ) {
        for r in 0..TILE {
            for c in 0..TILE {
                let global_r = job.tile_row * TILE + r;
                let global_c = job.tile_col * TILE + c;

                if global_r < rows && global_c < cols {
                    let idx = global_r * c_stride + global_c;
                    c_data[idx] += result_tile[r * TILE + c].to_f32();
                }
            }
        }
    }

    pub fn load_busy(&self) -> bool {
        self.status() & STATUS_LOAD_BUSY != 0
    }

    pub fn compute_busy(&self) -> bool {
        self.status() & STATUS_COMPUTE_BUSY != 0
    }

    fn write_tile_inputs(
        &mut self,
        bank: usize,
        a_base: u16,
        b_base: u16,
        a: &Bf16Tile,
        b: &Bf16Tile,
    ) {
        let ext_base = Self::ext_base(bank);
        for i in 0..TILE_WORDS {
            unsafe {
                sys::rpu_write(
                    self.inner.as_ptr(),
                    ext_base + a_base + i,
                    a[usize::from(i)].to_bits(),
                );
                sys::rpu_write(
                    self.inner.as_ptr(),
                    ext_base + b_base + i,
                    b[usize::from(i)].to_bits(),
                );
            }
        }
    }

    fn configure_bases(&mut self, a_base: u16, b_base: u16, c_base: u16) {
        unsafe {
            sys::rpu_write(self.inner.as_ptr(), REG_A_BASE, a_base);
            sys::rpu_write(self.inner.as_ptr(), REG_B_BASE, b_base);
            sys::rpu_write(self.inner.as_ptr(), REG_C_BASE, c_base);
        }
    }

    fn write_control(&mut self, bank: usize, flags: u16) {
        let bank_flag = if bank == 0 { 0 } else { CONTROL_BANK1 };
        unsafe {
            sys::rpu_write(self.inner.as_ptr(), REG_CONTROL, flags | bank_flag);
        }
    }

    fn read_tile_output(&self, bank: usize, c_base: u16) -> Bf16Tile {
        let ext_base = Self::ext_base(bank);
        let mut out = [BFloat16::ZERO; TILE * TILE];
        for i in 0..TILE_WORDS {
            let bits = unsafe { sys::rpu_read(self.inner.as_ptr(), ext_base + c_base + i) };
            out[usize::from(i)] = BFloat16::from_bits(bits);
        }
        out
    }

    fn ext_base(bank: usize) -> u16 {
        match bank {
            0 => EXT_BASE_BANK0,
            1 => EXT_BASE_BANK1,
            _ => panic!("RPU only has two external memory banks"),
        }
    }

    fn tick(&mut self) {
        unsafe { sys::rpu_tick(self.inner.as_ptr()) };
    }

    pub fn busy(&self) -> bool {
        unsafe { sys::rpu_busy(self.inner.as_ptr()) != 0 }
    }

    pub fn done(&self) -> bool {
        unsafe { sys::rpu_done(self.inner.as_ptr()) != 0 }
    }

    pub fn status(&self) -> u16 {
        unsafe { sys::rpu_read(self.inner.as_ptr(), REG_STATUS) }
    }

    fn wait_until_done(&mut self, max_cycles: usize) -> Result<(), RpuError> {
        for _ in 0..max_cycles {
            if self.done() {
                return Ok(());
            }
            self.tick();
        }

        Err(RpuError::Timeout { max_cycles })
    }

    fn wait_until_load_idle(&mut self, max_cycles: usize) -> Result<(), RpuError> {
        for _ in 0..max_cycles {
            if !self.load_busy() {
                return Ok(());
            }
            self.tick();
        }

        Err(RpuError::Timeout { max_cycles })
    }

    fn encode_matrix(matrix: Matrix) -> Result<Bf16Matrix, RpuError> {
        let mut encoded = [[BFloat16::ZERO; TILE]; TILE];
        for row in 0..TILE {
            for col in 0..TILE {
                encoded[row][col] = BFloat16::from_f32(matrix[row][col])?;
            }
        }
        Ok(encoded)
    }

    fn decode_matrix(matrix: Bf16Matrix) -> Matrix {
        let mut decoded = [[0.0; TILE]; TILE];
        for row in 0..TILE {
            for col in 0..TILE {
                decoded[row][col] = matrix[row][col].to_f32();
            }
        }
        decoded
    }

    fn flatten_tile(matrix: Bf16Matrix) -> Bf16Tile {
        let mut tile = [BFloat16::ZERO; TILE * TILE];
        for row in 0..TILE {
            for col in 0..TILE {
                tile[row * TILE + col] = matrix[row][col];
            }
        }
        tile
    }

    fn unflatten_tile(tile: Bf16Tile) -> Bf16Matrix {
        let mut matrix = [[BFloat16::ZERO; TILE]; TILE];
        for row in 0..TILE {
            for col in 0..TILE {
                matrix[row][col] = tile[row * TILE + col];
            }
        }
        matrix
    }
}

impl Drop for Rpu {
    fn drop(&mut self) {
        unsafe { sys::rpu_free(self.inner.as_ptr()) };
    }
}

pub trait MatrixElement: Copy {
    const ZERO: Self;

    fn mul(self, rhs: Self) -> Self;
    fn add(self, rhs: Self) -> Self;

    fn is_zero(self) -> bool;
}

impl MatrixElement for f32 {
    const ZERO: Self = 0.0;

    #[inline]
    fn mul(self, rhs: Self) -> Self {
        self * rhs
    }

    #[inline]
    fn add(self, rhs: Self) -> Self {
        self + rhs
    }

    #[inline]
    fn is_zero(self) -> bool {
        self == 0.0
    }
}

impl MatrixElement for BFloat16 {
    const ZERO: Self = BFloat16::ZERO;

    #[inline]
    fn mul(self, rhs: Self) -> Self {
        BFloat16::from_f32(self.to_f32() * rhs.to_f32()).unwrap()
    }

    #[inline]
    fn add(self, rhs: Self) -> Self {
        BFloat16::from_f32(self.to_f32() + rhs.to_f32()).unwrap()
    }

    #[inline]
    fn is_zero(self) -> bool {
        self == BFloat16::ZERO
    }
}

pub fn mat_mul<T: MatrixElement>(
    a: &[[T; TILE]; TILE],
    b: &[[T; TILE]; TILE],
) -> [[T; TILE]; TILE] {
    let mut out = [[T::ZERO; TILE]; TILE];

    for i in 0..TILE {
        for k in 0..TILE {
            let aik = a[i][k];

            if aik.is_zero() {
                continue;
            }

            for j in 0..TILE {
                out[i][j] = out[i][j].add(aik.mul(b[k][j]));
            }
        }
    }

    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn multiplies_8x8_bf16_matrices() {
        let mut rpu = Rpu::new().unwrap();
        let a = [
            [1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
            [0.0, 1.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
            [0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0],
            [0.0, 0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
        ];
        let b = [
            [2.0, 3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0],
            [6.0, 7.0, 8.0, 9.0, 0.0, 0.0, 0.0, 0.0],
            [10.0, 11.0, 12.0, 13.0, 0.0, 0.0, 0.0, 0.0],
            [14.0, 15.0, 16.0, 17.0, 0.0, 0.0, 0.0, 0.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
            [0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0],
        ];

        let c = rpu.multiply(a, b).unwrap();
        let a_bf16 = Rpu::encode_matrix(a).unwrap();
        let b_bf16 = Rpu::encode_matrix(b).unwrap();
        let expected_bf16 = mat_mul(&a_bf16, &b_bf16);
        let expected = Rpu::decode_matrix(expected_bf16);
        assert_eq!(c, expected);
    }

    fn bf16_mat_mul_dyn(
        a: &[BFloat16],
        a_rows: usize,
        a_cols: usize,
        b: &[BFloat16],
        b_cols: usize,
    ) -> Vec<f32> {
        let mut c = vec![0.0_f32; a_rows * b_cols];
        for i in 0..a_rows {
            for k in 0..a_cols {
                let aik = a[i * a_cols + k];
                if aik == BFloat16::ZERO {
                    continue;
                }
                for j in 0..b_cols {
                    let product = aik.to_f32() * b[k * b_cols + j].to_f32();
                    let product_bf16 = BFloat16::from_f32(product).unwrap();
                    c[i * b_cols + j] += product_bf16.to_f32();
                }
            }
        }
        c
    }

    fn test_dyn(rpu: &mut Rpu, m: usize, k: usize, n: usize) {
        let a_data: Vec<f32> = (0..m * k).map(|i| ((i + 1) % 7) as f32).collect();
        let b_data: Vec<f32> = (0..k * n).map(|i| ((i * 3 + 2) % 11) as f32).collect();

        let a = DynMatrix {
            rows: m,
            cols: k,
            data: a_data.clone(),
        };
        let b = DynMatrix {
            rows: k,
            cols: n,
            data: b_data.clone(),
        };

        let c = rpu.multiply_dyn(&a, &b).unwrap();

        let a_bf16: Vec<BFloat16> = a_data
            .iter()
            .map(|&v| BFloat16::from_f32(v).unwrap())
            .collect();
        let b_bf16: Vec<BFloat16> = b_data
            .iter()
            .map(|&v| BFloat16::from_f32(v).unwrap())
            .collect();
        let expected = bf16_mat_mul_dyn(&a_bf16, m, k, &b_bf16, n);

        for i in 0..m {
            for j in 0..n {
                let got = c.data[i * n + j];
                let exp = expected[i * n + j];
                assert!(
                    (got - exp).abs() < 0.1,
                    "Mismatch at [{i}][{j}]: got {got}, expected {exp}"
                );
            }
        }
    }

    #[test]
    fn multiply_dyn_matches_reference() {
        let mut rpu = Rpu::new().unwrap();

        test_dyn(&mut rpu, 3, 3, 3);
        test_dyn(&mut rpu, 8, 8, 8);
        test_dyn(&mut rpu, 16, 16, 16);
        test_dyn(&mut rpu, 9, 5, 7);
        test_dyn(&mut rpu, 1, 8, 1);
        test_dyn(&mut rpu, 12, 3, 15);
    }

    #[test]
    fn preload_overlaps_active_compute() {
        let mut rpu = Rpu::new().unwrap();
        let a0 = Rpu::flatten_tile(Rpu::encode_matrix([[1.0; TILE]; TILE]).unwrap());
        let b0 = Rpu::flatten_tile(Rpu::encode_matrix([[2.0; TILE]; TILE]).unwrap());
        let a1 = Rpu::flatten_tile(Rpu::encode_matrix([[3.0; TILE]; TILE]).unwrap());
        let b1 = Rpu::flatten_tile(Rpu::encode_matrix([[4.0; TILE]; TILE]).unwrap());
        let a_base = 0;
        let b_base = TILE_WORDS;
        let c_base = 2 * TILE_WORDS;

        rpu.write_tile_inputs(0, a_base, b_base, &a0, &b0);
        rpu.write_tile_inputs(1, a_base, b_base, &a1, &b1);

        rpu.preload_tile(0, a0, b0).unwrap();

        rpu.configure_bases(a_base, b_base, c_base);
        rpu.write_control(0, CONTROL_START);
        rpu.tick();
        assert!(rpu.compute_busy());

        rpu.configure_bases(a_base, b_base, c_base);
        rpu.write_control(1, CONTROL_PRELOAD);
        rpu.tick();

        assert!(rpu.compute_busy());
        assert!(rpu.load_busy());

        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        let c0 = rpu.read_tile_output(0, c_base);
        assert_eq!(c0[0].to_f32(), 16.0);

        rpu.wait_until_load_idle(Rpu::MAX_WAIT_CYCLES).unwrap();
        rpu.configure_bases(a_base, b_base, c_base);
        rpu.write_control(1, CONTROL_START);
        rpu.tick();
        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        let c1 = rpu.read_tile_output(1, c_base);
        assert_eq!(c1[0].to_f32(), 96.0);
    }

    #[test]
    fn cycles_are_reported() {
        let mut rpu = Rpu::new().unwrap();
        let zero = [[0.0; TILE]; TILE];
        rpu.multiply(zero, zero).unwrap();
        assert!(rpu.cycles() > 0);
        assert_eq!(rpu.status() & 0b10, 0b10);
    }
}
