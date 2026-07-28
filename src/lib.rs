use std::fmt;
use std::ptr::NonNull;

pub type Matrix2 = [[f32; 2]; 2];
pub type Bf16Matrix2 = [[BFloat16; 2]; 2];

mod sys {
    #[repr(C)]
    pub struct Rpu(std::ffi::c_void);

    extern "C" {
        pub fn rpu_new() -> *mut Rpu;
        pub fn rpu_free(r: *mut Rpu);
        pub fn rpu_reset(r: *mut Rpu);
        pub fn rpu_tick(r: *mut Rpu);
        pub fn rpu_cycles(r: *mut Rpu) -> u32;
        pub fn rpu_set_a(r: *mut Rpu, row: u8, col: u8, value: u16);
        pub fn rpu_set_b(r: *mut Rpu, row: u8, col: u8, value: u16);
        pub fn rpu_start(r: *mut Rpu);
        pub fn rpu_busy(r: *mut Rpu) -> u8;
        pub fn rpu_done(r: *mut Rpu) -> u8;
        pub fn rpu_get_c(r: *mut Rpu, row: u8, col: u8) -> u16;
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
            Self::NonFiniteInput(value) => write!(
                f,
                "RPU BF16 model does not support non-finite input {value}"
            ),
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
    const MAX_WAIT_CYCLES: usize = 64;

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

    pub fn multiply(&mut self, a: Matrix2, b: Matrix2) -> Result<Matrix2, RpuError> {
        let a = Self::encode_matrix(a)?;
        let b = Self::encode_matrix(b)?;
        let c = self.multiply_bf16(a, b)?;
        Ok(Self::decode_matrix(c))
    }

    pub fn multiply_bf16(
        &mut self,
        a: Bf16Matrix2,
        b: Bf16Matrix2,
    ) -> Result<Bf16Matrix2, RpuError> {
        for row in 0..2 {
            for col in 0..2 {
                unsafe {
                    sys::rpu_set_a(
                        self.inner.as_ptr(),
                        row as u8,
                        col as u8,
                        a[row][col].to_bits(),
                    );
                    sys::rpu_set_b(
                        self.inner.as_ptr(),
                        row as u8,
                        col as u8,
                        b[row][col].to_bits(),
                    );
                }
            }
        }

        unsafe { sys::rpu_start(self.inner.as_ptr()) };
        self.wait_until_done(Self::MAX_WAIT_CYCLES)?;
        Ok(self.read_bf16())
    }

    pub fn busy(&self) -> bool {
        unsafe { sys::rpu_busy(self.inner.as_ptr()) != 0 }
    }

    pub fn done(&self) -> bool {
        unsafe { sys::rpu_done(self.inner.as_ptr()) != 0 }
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

    fn read_bf16(&self) -> Bf16Matrix2 {
        let mut c = [[BFloat16::ZERO; 2]; 2];
        for row in 0..2 {
            for col in 0..2 {
                let bits = unsafe { sys::rpu_get_c(self.inner.as_ptr(), row as u8, col as u8) };
                c[row][col] = BFloat16::from_bits(bits);
            }
        }
        c
    }

    fn encode_matrix(matrix: Matrix2) -> Result<Bf16Matrix2, RpuError> {
        let mut encoded = [[BFloat16::ZERO; 2]; 2];
        for row in 0..2 {
            for col in 0..2 {
                encoded[row][col] = BFloat16::from_f32(matrix[row][col])?;
            }
        }
        Ok(encoded)
    }

    fn decode_matrix(matrix: Bf16Matrix2) -> Matrix2 {
        let mut decoded = [[0.0; 2]; 2];
        for row in 0..2 {
            for col in 0..2 {
                decoded[row][col] = matrix[row][col].to_f32();
            }
        }
        decoded
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
    fn multiplies_2x2_bf16_matrices() {
        let mut rpu = Rpu::new().unwrap();
        let c = rpu
            .multiply([[1.5, 2.0], [0.0, 1.0]], [[2.0, 0.0], [0.0, 3.0]])
            .unwrap();

        assert_eq!(c, [[3.0, 6.0], [0.0, 3.0]]);
    }

    #[test]
    fn cycles() {
        let mut rpu = Rpu::new().unwrap();
        rpu.multiply([[0.0, 0.0], [0.0, 0.0]], [[0.0, 0.0], [0.0, 0.0]])
            .unwrap();
        assert_eq!(7, rpu.cycles());
    }
}
