pub mod quant;

/// Array size N. Must match the default `N` of `rtl/rpu_top.sv`.
pub const TILE: usize = 8;
/// Longest K of one panel job. Must match `KMAX` of `rtl/rpu_top.sv`.
pub const KMAX: usize = 1024;

use std::fmt;
use std::ptr::NonNull;

const REG_CONTROL: u16 = 0x0000;
const REG_STATUS: u16 = 0x0001;
const REG_A_BASE: u16 = 0x0002;
const REG_B_BASE: u16 = 0x0003;
const REG_C_BASE: u16 = 0x0004;
const REG_K_LEN: u16 = 0x0005;
const REG_ACTIVE_LO: u16 = 0x0006;
const REG_BUSY_LO: u16 = 0x0008;

/// Bus words per A or B panel: two int8 per 16-bit word.
const PANEL_WORDS: u16 = (TILE * KMAX / 2) as u16;
/// Fixed layout inside each external bank: A, then B, then C (two words per i32).
const A_BASE: u16 = 0;
const B_BASE: u16 = PANEL_WORDS;
const C_BASE: u16 = 2 * PANEL_WORDS;
const EXT_WORDS: u16 = C_BASE + (2 * TILE * TILE) as u16;

const EXT_BASE_BANK0: u16 = 0x1000;
const EXT_BASE_BANK1: u16 = EXT_BASE_BANK0 + EXT_WORDS;

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

#[derive(Debug, Clone, PartialEq)]
pub enum RpuError {
    AllocationFailed,
    Timeout { max_cycles: usize },
}

impl fmt::Display for RpuError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::AllocationFailed => write!(f, "failed to allocate RPU model"),
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
    const MAX_WAIT_CYCLES: usize = 1 << 20;

    pub fn new() -> Result<Self, RpuError> {
        let inner = NonNull::new(unsafe { sys::rpu_new() }).ok_or(RpuError::AllocationFailed)?;
        let mut rpu = Self { inner };
        rpu.reset();
        Ok(rpu)
    }

    pub fn reset(&mut self) {
        unsafe { sys::rpu_reset(self.inner.as_ptr()) };
    }

    /// Cycles the RPU was busy since the last START (or reset).
    pub fn cycles(&self) -> u32 {
        unsafe { sys::rpu_cycles(self.inner.as_ptr()) }
    }

    /// Free-running count of cycles the array streamed, since reset.
    pub fn active_cycles(&self) -> u32 {
        self.read_u32(REG_ACTIVE_LO)
    }

    /// Free-running count of cycles the RPU was busy (load or compute), since reset.
    pub fn busy_cycles(&self) -> u32 {
        self.read_u32(REG_BUSY_LO)
    }

    /// One int8 NT tile: `C[i][j] = sum_k A[i][k] * B[j][k]`, all `TILE x TILE` row-major.
    pub fn run_tile_i8(&mut self, a: &[i8], b: &[i8]) -> Result<Vec<i32>, RpuError> {
        self.run_panel_i8(a, b, TILE)
    }

    /// One int8 NT panel job: A and B are `TILE x k` row-major, C is `TILE x TILE`.
    pub fn run_panel_i8(&mut self, a: &[i8], b: &[i8], k: usize) -> Result<Vec<i32>, RpuError> {
        self.preload_panel_i8(0, a, b, k)?;
        self.start(0);
        self.wait_until_done(Self::MAX_WAIT_CYCLES)?;
        Ok(self.read_c(0))
    }

    /// Writes A and B (`TILE x k`) into external `bank` and loads them into the local buffer
    /// of the same bank. Returns once the load is done; a compute on the other bank may run.
    pub fn preload_panel_i8(
        &mut self,
        bank: usize,
        a: &[i8],
        b: &[i8],
        k: usize,
    ) -> Result<(), RpuError> {
        self.write_panel_i8(bank, a, b, k);
        self.configure_bases();
        self.write_control(bank, CONTROL_PRELOAD);
        self.tick();
        self.wait_until_load_idle(Self::MAX_WAIT_CYCLES)
    }

    /// Starts the compute on local `bank`. Without a preloaded bank, the RPU loads first.
    pub fn start(&mut self, bank: usize) {
        self.configure_bases();
        self.write_control(bank, CONTROL_START);
        self.tick();
    }

    /// Reads the C tile that the last compute on `bank` stored.
    pub fn read_c(&self, bank: usize) -> Vec<i32> {
        self.read_words(bank, C_BASE, 2 * TILE * TILE)
            .chunks_exact(2)
            .map(|w| (u32::from(w[0]) | (u32::from(w[1]) << 16)) as i32)
            .collect()
    }

    /// Writes the panels and sets K_LEN. Each row is packed on its own, padded to even k.
    fn write_panel_i8(&mut self, bank: usize, a: &[i8], b: &[i8], k: usize) {
        assert!((1..=KMAX).contains(&k), "k must be in 1..={KMAX}");
        assert_eq!(a.len(), TILE * k, "A must be TILE x k");
        assert_eq!(b.len(), TILE * k, "B must be TILE x k");
        let pack_rows = |m: &[i8]| -> Vec<u16> { m.chunks_exact(k).flat_map(pack_i8).collect() };
        self.write_words(bank, A_BASE, &pack_rows(a));
        self.write_words(bank, B_BASE, &pack_rows(b));
        unsafe { sys::rpu_write(self.inner.as_ptr(), REG_K_LEN, k as u16) };
    }

    fn read_u32(&self, lo_addr: u16) -> u32 {
        let lo = unsafe { sys::rpu_read(self.inner.as_ptr(), lo_addr) };
        let hi = unsafe { sys::rpu_read(self.inner.as_ptr(), lo_addr + 1) };
        u32::from(lo) | (u32::from(hi) << 16)
    }

    pub fn load_busy(&self) -> bool {
        self.status() & STATUS_LOAD_BUSY != 0
    }

    pub fn compute_busy(&self) -> bool {
        self.status() & STATUS_COMPUTE_BUSY != 0
    }

    fn write_words(&mut self, bank: usize, base: u16, words: &[u16]) {
        let ext_base = Self::ext_base(bank) + base;
        for (i, &w) in words.iter().enumerate() {
            unsafe { sys::rpu_write(self.inner.as_ptr(), ext_base + i as u16, w) };
        }
    }

    fn read_words(&self, bank: usize, base: u16, count: usize) -> Vec<u16> {
        let ext_base = Self::ext_base(bank) + base;
        (0..count)
            .map(|i| unsafe { sys::rpu_read(self.inner.as_ptr(), ext_base + i as u16) })
            .collect()
    }

    fn configure_bases(&mut self) {
        unsafe {
            sys::rpu_write(self.inner.as_ptr(), REG_A_BASE, A_BASE);
            sys::rpu_write(self.inner.as_ptr(), REG_B_BASE, B_BASE);
            sys::rpu_write(self.inner.as_ptr(), REG_C_BASE, C_BASE);
        }
    }

    fn write_control(&mut self, bank: usize, flags: u16) {
        let bank_flag = if bank == 0 { 0 } else { CONTROL_BANK1 };
        unsafe {
            sys::rpu_write(self.inner.as_ptr(), REG_CONTROL, flags | bank_flag);
        }
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
}

impl Drop for Rpu {
    fn drop(&mut self) {
        unsafe { sys::rpu_free(self.inner.as_ptr()) };
    }
}

/// Two int8 per 16-bit bus word, even index in the low byte. Odd lengths pad with zero.
fn pack_i8(values: &[i8]) -> Vec<u16> {
    values
        .chunks(2)
        .map(|p| u16::from(p[0] as u8) | (u16::from(p.get(1).copied().unwrap_or(0) as u8) << 8))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    const N2: usize = TILE * TILE;

    #[test]
    fn preload_overlaps_active_compute() {
        let mut rpu = Rpu::new().unwrap();
        rpu.preload_panel_i8(0, &[1; N2], &[2; N2], TILE).unwrap();
        rpu.start(0);
        assert!(rpu.compute_busy());

        rpu.write_panel_i8(1, &[3; N2], &[-4; N2], TILE);
        rpu.configure_bases();
        rpu.write_control(1, CONTROL_PRELOAD);
        rpu.tick();
        assert!(rpu.compute_busy());
        assert!(rpu.load_busy());

        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(0), vec![2 * TILE as i32; N2]);

        rpu.wait_until_load_idle(Rpu::MAX_WAIT_CYCLES).unwrap();
        rpu.start(1);
        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(1), vec![-12 * TILE as i32; N2]);
    }

    #[test]
    fn cycles_are_reported() {
        let mut rpu = Rpu::new().unwrap();
        rpu.run_tile_i8(&[0; N2], &[0; N2]).unwrap();
        assert!(rpu.cycles() > 0);
        assert_eq!(rpu.status() & 0b10, 0b10);
    }

    fn assert_tile_i8_exact(rpu: &mut Rpu, a: &[i8], b: &[i8]) {
        let got = rpu.run_tile_i8(a, b).unwrap();
        let want = quant::matmul_nt_i8(a, b, TILE, TILE, TILE);
        assert_eq!(got, want, "A = {a:?}\nB = {b:?}");
    }

    #[test]
    fn int8_edge_tiles_are_bit_exact() {
        let mut rpu = Rpu::new().unwrap();
        for (a, b) in [(0, 0), (127, 127), (-127, -127), (-127, 127), (1, -1)] {
            assert_tile_i8_exact(&mut rpu, &[a; N2], &[b; N2]);
        }
        let ramp: Vec<i8> = (0..N2).map(|i| (i as i32 * 4 - 127) as i8).collect();
        assert_tile_i8_exact(&mut rpu, &ramp, &ramp);
        // Only the last k is nonzero: its products reach PE (N-1, N-1) last, so a drain
        // that is one cycle short loses them.
        let mut a = [0i8; N2];
        let mut b = [0i8; N2];
        for i in 0..TILE {
            a[i * TILE + TILE - 1] = 127;
            b[i * TILE + TILE - 1] = -127;
        }
        assert_tile_i8_exact(&mut rpu, &a, &b);
    }

    #[test]
    fn int8_random_tiles_are_bit_exact() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x5eed_1234_abcd_ef01);
        for _ in 0..1000 {
            let a: Vec<i8> = (0..N2).map(|_| rng.i8_sym()).collect();
            let b: Vec<i8> = (0..N2).map(|_| rng.i8_sym()).collect();
            assert_tile_i8_exact(&mut rpu, &a, &b);
        }
    }

    #[test]
    fn int8_panels_are_bit_exact_for_any_k() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x0bad_cafe_f00d_1234);
        for &(k, runs) in &[
            (1, 20),
            (7, 20),
            (8, 20),
            (9, 20),
            (64, 10),
            (784, 3),
            (1024, 3),
        ] {
            for _ in 0..runs {
                let a: Vec<i8> = (0..TILE * k).map(|_| rng.i8_sym()).collect();
                let b: Vec<i8> = (0..TILE * k).map(|_| rng.i8_sym()).collect();
                let active = rpu.active_cycles();
                let got = rpu.run_panel_i8(&a, &b, k).unwrap();
                assert_eq!(got, quant::matmul_nt_i8(&a, &b, TILE, TILE, k), "k = {k}");
                assert_eq!(rpu.active_cycles() - active, k as u32, "streams k cycles");
            }
        }
        // Largest magnitude: 1024 * 127^2 = 16,516,096 in every PE.
        let a = vec![-127i8; TILE * KMAX];
        let got = rpu.run_panel_i8(&a, &a, KMAX).unwrap();
        assert_eq!(got, vec![127 * 127 * KMAX as i32; N2]);
    }

    #[test]
    fn busy_cycles_count_load_and_compute() {
        let mut rpu = Rpu::new().unwrap();
        rpu.run_tile_i8(&[1; N2], &[1; N2]).unwrap();
        let (active, busy) = (rpu.active_cycles(), rpu.busy_cycles());
        assert_eq!(active, TILE as u32);
        assert!(busy > rpu.cycles() && rpu.cycles() > active);
    }
}
