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

const EXT_BASE: u16 = 0x1000;
const TILE_WORDS: u16 = (TILE * TILE) as u16;

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

impl Rpu {
    const MAX_WAIT_CYCLES: usize = 512;

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

    pub fn run_tile(&mut self, a: Bf16Tile, b: Bf16Tile) -> Result<Bf16Tile, RpuError> {
        let a_base = 0;
        let b_base = TILE_WORDS;
        let c_base = 2 * TILE_WORDS;

        for i in 0..TILE_WORDS {
            unsafe {
                sys::rpu_write(
                    self.inner.as_ptr(),
                    EXT_BASE + a_base + i,
                    a[usize::from(i)].to_bits(),
                );
                sys::rpu_write(
                    self.inner.as_ptr(),
                    EXT_BASE + b_base + i,
                    b[usize::from(i)].to_bits(),
                );
            }
        }

        unsafe {
            sys::rpu_write(self.inner.as_ptr(), REG_A_BASE, a_base);
            sys::rpu_write(self.inner.as_ptr(), REG_B_BASE, b_base);
            sys::rpu_write(self.inner.as_ptr(), REG_C_BASE, c_base);
            sys::rpu_write(self.inner.as_ptr(), REG_CONTROL, 1);
            sys::rpu_tick(self.inner.as_ptr());
        }

        self.wait_until_done(Self::MAX_WAIT_CYCLES)?;

        let mut out = [BFloat16::ZERO; TILE * TILE];
        for i in 0..TILE_WORDS {
            let bits = unsafe { sys::rpu_read(self.inner.as_ptr(), EXT_BASE + c_base + i) };
            out[usize::from(i)] = BFloat16::from_bits(bits);
        }

        Ok(out)
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
            unsafe { sys::rpu_tick(self.inner.as_ptr()) };
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

    #[test]
    fn cycles_are_reported() {
        let mut rpu = Rpu::new().unwrap();
        let zero = [[0.0; TILE]; TILE];
        rpu.multiply(zero, zero).unwrap();
        assert!(rpu.cycles() > 0);
        assert_eq!(rpu.status() & 0b10, 0b10);
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
