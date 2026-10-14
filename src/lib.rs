pub mod quant;

/// Array size N, set at build time with `RPU_N` (default 8).
pub const TILE: usize = parse_usize(env!("RPU_N"));
/// Longest K of one panel job. Must match `KMAX` of `rtl/rpu_top.sv`.
pub const KMAX: usize = 1024;
/// Size of the RPU memory. Must match `MEM_BYTES` of `rtl/rpu_top.sv`.
const MEM_BYTES: usize = 1 << 20;

use std::fmt;
use std::ptr::NonNull;

const REG_CONTROL: u32 = 0;
const REG_STATUS: u32 = 1;
const REG_A_BASE: u32 = 2;
const REG_B_BASE: u32 = 3;
const REG_C_BASE: u32 = 4;
const REG_K_LEN: u32 = 5;
const REG_ACTIVE: u32 = 6;
const REG_BUSY: u32 = 7;
/// Host address of memory word 0. The host bus moves 64-bit words.
const MEM_BASE: u32 = 0x1000_0000;

/// A memory beat is N int8, so N/8 host words.
const BEAT_WORDS: u32 = (TILE / 8) as u32;
const _: () = assert!(
    TILE.is_multiple_of(8),
    "the 64-bit host bus needs N to be a multiple of 8"
);
/// Beats per panel row: each row is padded to a whole number of beats.
const ROW_BEATS: u32 = KMAX.div_ceil(TILE) as u32;
const PANEL_BEATS: u32 = TILE as u32 * ROW_BEATS;
/// C is TILE x TILE int32: 4 beats per row.
const C_BEATS: u32 = 4 * TILE as u32;
/// Memory layout per local bank, in beats: A panel, B panel, C tile.
const BANK_BEATS: u32 = 2 * PANEL_BEATS + C_BEATS;

const CONTROL_START: u64 = 0b0001;
const CONTROL_BANK1: u64 = 0b0010;
const CONTROL_PRELOAD: u64 = 0b0100;
/// Load only B: the A panel buffer keeps its contents.
const CONTROL_KEEP_A: u64 = 0b1000;
const STATUS_LOAD_BUSY: u64 = 0b0100;
const STATUS_COMPUTE_BUSY: u64 = 0b1000;

mod sys {
    #[repr(C)]
    pub struct Rpu(std::ffi::c_void);

    extern "C" {
        pub fn rpu_new() -> *mut Rpu;
        pub fn rpu_free(r: *mut Rpu);
        pub fn rpu_reset(r: *mut Rpu);
        pub fn rpu_tick(r: *mut Rpu);
        pub fn rpu_cycles(r: *mut Rpu) -> u32;
        pub fn rpu_write(r: *mut Rpu, addr: u32, value: u64);
        pub fn rpu_read(r: *mut Rpu, addr: u32) -> u64;
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
        self.read_reg(REG_ACTIVE) as u32
    }

    /// Free-running count of cycles the RPU was busy (load, compute or C store), since reset.
    pub fn busy_cycles(&self) -> u32 {
        self.read_reg(REG_BUSY) as u32
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

    /// Int8 NT GEMM `C[i][j] = sum_k A[i][k] * B[j][k]`: A is `m x k`, B is `n x k`, C is
    /// `m x n`, all row-major. All operands go into external memory first. For each block
    /// of TILE rows of A, A is loaded once; the B tiles alternate between the two local
    /// banks, so the load of the next B overlaps the compute of the current one.
    pub fn matmul_nt_i8(
        &mut self,
        a: &[i8],
        b: &[i8],
        m: usize,
        n: usize,
        k: usize,
    ) -> Result<Vec<i32>, RpuError> {
        assert!((1..=KMAX).contains(&k), "k must be in 1..={KMAX}");
        assert_eq!(a.len(), m * k, "A must be m x k");
        assert_eq!(b.len(), n * k, "B must be n x k");
        let (mt, nt) = (m.div_ceil(TILE), n.div_ceil(TILE));
        let panel = (TILE * k.div_ceil(TILE)) as u32;
        let (a_base, b_base) = (0, mt as u32 * panel);
        let c_base = b_base + nt as u32 * panel;
        let c_tile = |r: usize, j: usize| c_base + (r * nt + j) as u32 * C_BEATS;
        assert!(
            (c_tile(mt, 0) * BEAT_WORDS) as usize * 8 <= MEM_BYTES,
            "GEMM does not fit in RPU memory"
        );
        let pad = |x: &[i8], rows: usize| {
            let mut v = x.to_vec();
            v.resize(rows * TILE * k, 0);
            v
        };
        self.write_words(a_base, &pack_rows(&pad(a, mt), k));
        self.write_words(b_base, &pack_rows(&pad(b, nt), k));
        self.write_reg(REG_K_LEN, k as u64);

        for r in 0..mt {
            // Tile 0 has no preloaded bank: START loads A and B first.
            self.write_reg(REG_A_BASE, (a_base + r as u32 * panel).into());
            self.write_reg(REG_B_BASE, b_base.into());
            self.write_reg(REG_C_BASE, c_tile(r, 0).into());
            for j in 0..nt {
                self.write_control(j % 2, CONTROL_START);
                self.tick();
                self.wait_until(|rpu| !rpu.load_busy())?;
                if j + 1 < nt {
                    self.write_reg(REG_B_BASE, (b_base + (j + 1) as u32 * panel).into());
                    self.write_control((j + 1) % 2, CONTROL_PRELOAD | CONTROL_KEEP_A);
                    // START took the C base already, so this is for the next tile.
                    self.write_reg(REG_C_BASE, c_tile(r, j + 1).into());
                }
                // The C store of this tile overlaps the next compute.
                self.wait_until(|rpu| !rpu.load_busy() && !rpu.compute_busy())?;
            }
        }
        self.wait_until(Self::done)?;

        let tile_words = (C_BEATS * BEAT_WORDS) as usize;
        let mut c = vec![0i32; m * n];
        for r in 0..mt {
            for j in 0..nt {
                let words = self.read_words(c_tile(r, j), tile_words);
                let tile = words
                    .iter()
                    .flat_map(|&w| [w as u32 as i32, (w >> 32) as u32 as i32]);
                for (idx, v) in tile.enumerate() {
                    let (i, jj) = (r * TILE + idx / TILE, j * TILE + idx % TILE);
                    if i < m && jj < n {
                        c[i * n + jj] = v;
                    }
                }
            }
        }
        Ok(c)
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
        self.configure_bases(bank);
        self.write_control(bank, CONTROL_PRELOAD);
        self.tick();
        self.wait_until_load_idle(Self::MAX_WAIT_CYCLES)
    }

    /// Starts the compute on local `bank`. Without a preloaded bank, the RPU loads first.
    pub fn start(&mut self, bank: usize) {
        self.configure_bases(bank);
        self.write_control(bank, CONTROL_START);
        self.tick();
    }

    /// Reads the C tile that the last compute on `bank` stored.
    pub fn read_c(&self, bank: usize) -> Vec<i32> {
        self.read_words(Self::c_base(bank), (C_BEATS * BEAT_WORDS) as usize)
            .into_iter()
            .flat_map(|w| [w as u32 as i32, (w >> 32) as u32 as i32])
            .collect()
    }

    /// Writes the panels and sets K_LEN. Each row is padded to a whole number of beats.
    fn write_panel_i8(&mut self, bank: usize, a: &[i8], b: &[i8], k: usize) {
        assert!((1..=KMAX).contains(&k), "k must be in 1..={KMAX}");
        assert_eq!(a.len(), TILE * k, "A must be TILE x k");
        assert_eq!(b.len(), TILE * k, "B must be TILE x k");
        let a_base = Self::a_base(bank);
        self.write_words(a_base, &pack_rows(a, k));
        self.write_words(a_base + PANEL_BEATS, &pack_rows(b, k));
        self.write_reg(REG_K_LEN, k as u64);
    }

    fn read_reg(&self, addr: u32) -> u64 {
        unsafe { sys::rpu_read(self.inner.as_ptr(), addr) }
    }

    fn write_reg(&mut self, addr: u32, value: u64) {
        unsafe { sys::rpu_write(self.inner.as_ptr(), addr, value) };
    }

    pub fn load_busy(&self) -> bool {
        self.status() & STATUS_LOAD_BUSY != 0
    }

    pub fn compute_busy(&self) -> bool {
        self.status() & STATUS_COMPUTE_BUSY != 0
    }

    /// Writes host words starting at memory beat `beat`.
    fn write_words(&mut self, beat: u32, words: &[u64]) {
        let base = MEM_BASE + beat * BEAT_WORDS;
        for (i, &w) in words.iter().enumerate() {
            self.write_reg(base + i as u32, w);
        }
    }

    fn read_words(&self, beat: u32, count: usize) -> Vec<u64> {
        let base = MEM_BASE + beat * BEAT_WORDS;
        (0..count).map(|i| self.read_reg(base + i as u32)).collect()
    }

    fn configure_bases(&mut self, bank: usize) {
        let a_base = Self::a_base(bank);
        self.write_reg(REG_A_BASE, a_base.into());
        self.write_reg(REG_B_BASE, (a_base + PANEL_BEATS).into());
        self.write_reg(REG_C_BASE, Self::c_base(bank).into());
    }

    fn write_control(&mut self, bank: usize, flags: u64) {
        let bank_flag = if bank == 0 { 0 } else { CONTROL_BANK1 };
        self.write_reg(REG_CONTROL, flags | bank_flag);
    }

    fn a_base(bank: usize) -> u32 {
        assert!(bank < 2, "RPU only has two local banks");
        bank as u32 * BANK_BEATS
    }

    fn c_base(bank: usize) -> u32 {
        Self::a_base(bank) + 2 * PANEL_BEATS
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

    pub fn status(&self) -> u64 {
        self.read_reg(REG_STATUS)
    }

    fn wait_until_done(&mut self, max_cycles: usize) -> Result<(), RpuError> {
        self.wait_for(max_cycles, Self::done)
    }

    fn wait_until_load_idle(&mut self, max_cycles: usize) -> Result<(), RpuError> {
        self.wait_for(max_cycles, |rpu| !rpu.load_busy())
    }

    fn wait_until(&mut self, ready: impl Fn(&Self) -> bool) -> Result<(), RpuError> {
        self.wait_for(Self::MAX_WAIT_CYCLES, ready)
    }

    /// Ticks until `ready`, checking before each tick.
    fn wait_for(
        &mut self,
        max_cycles: usize,
        ready: impl Fn(&Self) -> bool,
    ) -> Result<(), RpuError> {
        for _ in 0..max_cycles {
            if ready(self) {
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

const fn parse_usize(s: &str) -> usize {
    let bytes = s.as_bytes();
    let mut i = 0;
    let mut value = 0;
    while i < bytes.len() {
        assert!(bytes[i].is_ascii_digit(), "RPU_N must be a decimal number");
        value = value * 10 + (bytes[i] - b'0') as usize;
        i += 1;
    }
    value
}

/// Packs `k`-long rows into 64-bit host words, each row zero-padded to whole beats.
/// Value 0 of a word is its low byte.
fn pack_rows(m: &[i8], k: usize) -> Vec<u64> {
    let row_bytes = k.div_ceil(TILE) * TILE;
    m.chunks_exact(k)
        .flat_map(|row| {
            let mut bytes = vec![0u8; row_bytes];
            for (dst, &v) in bytes.iter_mut().zip(row) {
                *dst = v as u8;
            }
            bytes
                .chunks_exact(8)
                .map(|w| u64::from_le_bytes(w.try_into().unwrap()))
                .collect::<Vec<_>>()
        })
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
        // Host writes take a cycle each, so write bank 1 before the compute starts.
        rpu.write_panel_i8(1, &[3; N2], &[-4; N2], TILE);
        rpu.start(0);
        assert!(rpu.compute_busy());

        // Only B: a new A must not be loaded while a compute runs.
        rpu.configure_bases(1);
        rpu.write_control(1, CONTROL_PRELOAD | CONTROL_KEEP_A);
        rpu.tick();
        assert!(rpu.compute_busy());
        assert!(rpu.load_busy());

        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(0), vec![2 * TILE as i32; N2]);

        rpu.wait_until_load_idle(Rpu::MAX_WAIT_CYCLES).unwrap();
        rpu.start(1);
        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(1), vec![-4 * TILE as i32; N2]);
    }

    fn assert_gemm_exact(rpu: &mut Rpu, m: usize, n: usize, k: usize, rng: &mut quant::XorShift) {
        let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
        let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
        let got = rpu.matmul_nt_i8(&a, &b, m, n, k).unwrap();
        assert_eq!(
            got,
            quant::matmul_nt_i8(&a, &b, m, n, k),
            "{m}x{k} x {k}x{n}"
        );
    }

    #[test]
    fn gemm_with_ragged_shapes_is_bit_exact() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0xfeed_0007_d00d_5eed);
        for (m, n, k) in [
            (1, 1, 1),
            // Short K: the next drain must wait for the C store of the tile before.
            (TILE, 4 * TILE, 1),
            (TILE, TILE, TILE),
            (3, 2 * TILE + 5, 9),
            (2 * TILE + 1, 3 * TILE, 40),
        ] {
            assert_gemm_exact(&mut rpu, m, n, k, &mut rng);
        }
    }

    /// Plan phase 7 check: layer 1 for batch 8, streaming at least 85% of busy cycles.
    #[test]
    fn layer1_batch8_is_bit_exact_and_mostly_streaming() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x1a7e_0001_8888_0784);
        let (active, busy) = (rpu.active_cycles(), rpu.busy_cycles());
        assert_gemm_exact(&mut rpu, 8, 128, 784, &mut rng);
        let (active, busy) = (rpu.active_cycles() - active, rpu.busy_cycles() - busy);
        let tiles = 8usize.div_ceil(TILE) * 128usize.div_ceil(TILE);
        assert_eq!(active as usize, tiles * 784);
        println!("layer 1 batch 8: active {active} / busy {busy} cycles");
        if TILE == 8 {
            assert!(
                active as f64 >= 0.85 * busy as f64,
                "active {active}, busy {busy}"
            );
        }
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
    fn panel_load_moves_one_beat_per_cycle() {
        let latency: u32 = env!("RPU_READ_LATENCY").parse().unwrap();
        let mut rpu = Rpu::new().unwrap();
        for k in [1, 9, 784] {
            let panel = vec![1i8; TILE * k];
            let busy = rpu.busy_cycles();
            rpu.preload_panel_i8(0, &panel, &panel, k).unwrap();
            let beats = 2 * TILE as u32 * k.div_ceil(TILE) as u32;
            assert_eq!(rpu.busy_cycles() - busy, beats + latency, "k = {k}");
        }
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
