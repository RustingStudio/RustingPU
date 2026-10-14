#[cfg(feature = "brain")]
pub mod brain;
pub mod quant;

/// Array size N, set at build time with `RPU_N` (default 8).
pub const TILE: usize = parse_usize(env!("RPU_N"));
/// Beats per load request, set at build time with `RPU_LOAD_BEATS` (default 1). A and B
/// must start at a multiple of it.
pub const LOAD_BEATS: usize = parse_usize(env!("RPU_LOAD_BEATS"));
const _: () = assert!(
    TILE.is_multiple_of(LOAD_BEATS),
    "RPU_LOAD_BEATS must divide RPU_N"
);
/// Store cycles per requantized C row, set at build time with `RPU_QUANT_PARTS` (1 to 4,
/// default 4). Each cycle requantizes ceil(N / QUANT_PARTS) columns.
pub const QUANT_PARTS: usize = parse_usize(env!("RPU_QUANT_PARTS"));
const _: () = assert!(
    QUANT_PARTS >= 1 && QUANT_PARTS <= 4,
    "RPU_QUANT_PARTS must be 1 to 4"
);
/// Longest K of one panel job. Must match `KMAX` of `rtl/rpu_top.sv`.
pub const KMAX: usize = 1024;
/// Size of the RPU memory. Must match `MEM_BYTES` of `rtl/rpu_top.sv`.
const MEM_BYTES: usize = (1 << 20) * if TILE > 16 { TILE / 16 } else { 1 };

use quant::Requant;
use std::cell::Cell;
use std::fmt;
use std::ptr::NonNull;
use std::sync::atomic::{AtomicU64, Ordering};

static NEXT_ID: AtomicU64 = AtomicU64::new(0);

const REG_CONTROL: u32 = 0;
const REG_STATUS: u32 = 1;
const REG_A_BASE: u32 = 2;
const REG_B_BASE: u32 = 3;
const REG_C_BASE: u32 = 4;
const REG_K_LEN: u32 = 5;
const REG_ACTIVE: u32 = 6;
const REG_BUSY: u32 = 7;
const REG_PANEL: u32 = 8;
const REG_TILES: u32 = 9;
/// Host address of memory word 0. The host bus moves 64-bit words.
const MEM_BASE: u32 = 0x1000_0000;

/// A memory beat is N int8 in N/8 host words, rounded up: the last word of a beat is
/// zero-padded when N is not a multiple of 8.
const BEAT_WORDS: u32 = TILE.div_ceil(8) as u32;
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
/// CONTROL bit 4: the local A bank that a load fills and a compute reads.
const CONTROL_A_BANK1: u64 = 0b1_0000;
/// Load only A: the B panel buffer keeps its contents. The GEMM sequencer sets it itself.
#[cfg(test)]
const CONTROL_KEEP_B: u64 = 0b10_0000;
/// Run the whole tiled GEMM described by the base, K, PANEL and TILES registers.
const CONTROL_GEMM: u64 = 0b100_0000;
/// CONTROL bit 7, with GEMM: store each C row as N int8, requantized per column.
const CONTROL_QUANT: u64 = 0b1000_0000;
/// Host address of requantization parameter word 0.
const QPARAM_BASE: u32 = 0x0800_0000;
/// Columns that one store cycle requantizes (QUANT_PARTS cycles per C row), and the width
/// of the lane field in a parameter address.
const QP_LANES: usize = TILE.div_ceil(QUANT_PARTS);
const QP_LANE_W: u32 = if QP_LANES > 1 {
    (QP_LANES - 1).ilog2() + 1
} else {
    1
};
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
    words_written: u64,
    words_read: Cell<u64>,
    /// Unique per model, so a [`ResidentB`] cannot be used with another RPU.
    id: u64,
}

/// B (`n x k`) in RPU memory, written by [`Rpu::upload_b`].
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ResidentB {
    id: u64,
    base: u32,
    n: usize,
    k: usize,
}

impl ResidentB {
    /// First memory beat after this B.
    pub fn end(&self) -> u32 {
        self.base + self.n.div_ceil(TILE) as u32 * panel_beats(self.k)
    }
}

/// Int8 activations (`m x k`) in RPU memory, in the A panel layout: written by
/// [`Rpu::upload_a`] or produced by [`Rpu::gemm_requant`].
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ResidentA {
    id: u64,
    base: u32,
    m: usize,
    k: usize,
}

impl ResidentA {
    /// First memory beat after this A.
    pub fn end(&self) -> u32 {
        self.base + self.m.div_ceil(TILE) as u32 * panel_beats(self.k)
    }
}

impl Rpu {
    const MAX_WAIT_CYCLES: usize = 1 << 20;

    pub fn new() -> Result<Self, RpuError> {
        let inner = NonNull::new(unsafe { sys::rpu_new() }).ok_or(RpuError::AllocationFailed)?;
        let mut rpu = Self {
            inner,
            words_written: 0,
            words_read: Cell::new(0),
            id: NEXT_ID.fetch_add(1, Ordering::Relaxed),
        };
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

    /// Host bus writes since `new`: memory words and registers. A UART link pays for each.
    pub fn host_words_written(&self) -> u64 {
        self.words_written
    }

    /// Memory words read by the host since `new`. Register reads (status polls, counters)
    /// are not counted: how often a real host polls is up to the transport.
    pub fn host_words_read(&self) -> u64 {
        self.words_read.get()
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
    /// `m x n`, all row-major. B goes to the start of RPU memory, A and C after it. To reuse
    /// B across calls, use [`Rpu::upload_b`] and [`Rpu::matmul_resident`].
    pub fn matmul_nt_i8(
        &mut self,
        a: &[i8],
        b: &[i8],
        m: usize,
        n: usize,
        k: usize,
    ) -> Result<Vec<i32>, RpuError> {
        let b = self.upload_b(0, b, n, k);
        self.matmul_resident(a, m, &b, b.end())
    }

    /// Writes B (`n x k`, row-major) into RPU memory from beat `base`, padded to whole tiles.
    /// The returned handle stays valid until something else overwrites that memory.
    pub fn upload_b(&mut self, base: u32, b: &[i8], n: usize, k: usize) -> ResidentB {
        assert!((1..=KMAX).contains(&k), "k must be in 1..={KMAX}");
        assert_eq!(b.len(), n * k, "B must be n x k");
        let handle = ResidentB {
            id: self.id,
            base,
            n,
            k,
        };
        assert!(
            (handle.end() * BEAT_WORDS) as usize * 8 <= MEM_BYTES,
            "B does not fit in RPU memory"
        );
        self.write_words(base, &pack_panels(&pad_rows(b, n, k), k));
        handle
    }

    /// The GEMM of [`Rpu::matmul_nt_i8`] with B already in RPU memory. A goes to memory
    /// from beat `scratch` and C after it; neither may overlap B.
    pub fn matmul_resident(
        &mut self,
        a: &[i8],
        m: usize,
        b: &ResidentB,
        scratch: u32,
    ) -> Result<Vec<i32>, RpuError> {
        let (mt, nt) = (m.div_ceil(TILE) as u32, b.n.div_ceil(TILE) as u32);
        let scratch_end = scratch + mt * panel_beats(b.k) + mt * nt * C_BEATS;
        assert!(
            scratch_end <= b.base || b.end() <= scratch,
            "scratch overlaps B"
        );
        let a = self.upload_a(scratch, a, m, b.k);
        self.gemm_i32(&a, b, a.end())
    }

    /// Writes A (`m x k`, row-major) into RPU memory from beat `base`, padded to whole tiles.
    pub fn upload_a(&mut self, base: u32, a: &[i8], m: usize, k: usize) -> ResidentA {
        assert!((1..=KMAX).contains(&k), "k must be in 1..={KMAX}");
        assert_eq!(a.len(), m * k, "A must be m x k");
        let handle = ResidentA {
            id: self.id,
            base,
            m,
            k,
        };
        assert!(
            (handle.end() * BEAT_WORDS) as usize * 8 <= MEM_BYTES,
            "A does not fit in RPU memory"
        );
        self.write_words(base, &pack_panels(&pad_rows(a, m, k), k));
        handle
    }

    /// Reads A back from RPU memory, `m x k` row-major.
    pub fn read_a(&self, a: &ResidentA) -> Vec<i8> {
        assert_eq!(a.id, self.id, "A is in another RPU");
        let words = self.read_words(a.base, ((a.end() - a.base) * BEAT_WORDS) as usize);
        unpack_panels(&words, a.m, a.k)
    }

    /// `C = A * B^T` in int32, `m x n` row-major. C goes to memory from beat `c_base`.
    pub fn gemm_i32(
        &mut self,
        a: &ResidentA,
        b: &ResidentB,
        c_base: u32,
    ) -> Result<Vec<i32>, RpuError> {
        let (mt, nt) = (a.m.div_ceil(TILE), b.n.div_ceil(TILE));
        let c_tile = |r: usize, j: usize| c_base + (r * nt + j) as u32 * C_BEATS;
        self.run_gemm(a, b, c_base, c_tile(mt, 0), CONTROL_GEMM)?;
        let (m, n) = (a.m, b.n);
        let mut c = vec![0i32; m * n];
        // Only the rows below m and the beats that hold columns below n cross the link.
        for r in 0..mt {
            for j in 0..nt {
                let cols = TILE.min(n - j * TILE);
                let words = c_row_beats(cols) * BEAT_WORDS as usize;
                for i in 0..TILE.min(m - r * TILE) {
                    let row = unpack_i32(&self.read_words(c_tile(r, j) + 4 * i as u32, words));
                    let at = (r * TILE + i) * n + j * TILE;
                    c[at..at + cols].copy_from_slice(&row[..cols]);
                }
            }
        }
        Ok(c)
    }

    /// `C = A * B^T`, with column j requantized by `params[j]`, stays in RPU memory from
    /// beat `out_base` as the int8 A (`m x n`) of the next GEMM. Only the parameters cross
    /// the host link.
    pub fn gemm_requant(
        &mut self,
        a: &ResidentA,
        b: &ResidentB,
        params: &[Requant],
        out_base: u32,
    ) -> Result<ResidentA, RpuError> {
        assert_eq!(params.len(), b.n, "one requantization per column");
        let out = ResidentA {
            id: self.id,
            base: out_base,
            m: a.m,
            k: b.n,
        };
        assert!(out.k <= KMAX, "the output must fit a panel row");
        // Padding columns keep stale parameters: the next GEMM streams only k < n.
        for (col, q) in params.iter().enumerate() {
            assert!(q.shift <= 48, "shift must be at most 48");
            let (j, w) = (col / TILE, col % TILE);
            let lane = (((j * QUANT_PARTS + w / QP_LANES) << QP_LANE_W) + w % QP_LANES) as u32;
            let word = u64::from(q.bias as u32)
                | u64::from(q.mult) << 32
                | u64::from(q.shift) << 48
                | u64::from(q.relu) << 54;
            self.write_reg(QPARAM_BASE + lane, word);
        }
        self.run_gemm(a, b, out_base, out.end(), CONTROL_GEMM | CONTROL_QUANT)?;
        Ok(out)
    }

    /// Runs the tiled GEMM sequencer with C (or the requantized output) in
    /// `c_base..c_end`.
    fn run_gemm(
        &mut self,
        a: &ResidentA,
        b: &ResidentB,
        c_base: u32,
        c_end: u32,
        control: u64,
    ) -> Result<(), RpuError> {
        assert!(
            a.id == self.id && b.id == self.id,
            "A or B is in another RPU"
        );
        assert_eq!(a.k, b.k, "A and B must have the same k");
        assert!(
            (c_end * BEAT_WORDS) as usize * 8 <= MEM_BYTES,
            "GEMM does not fit in RPU memory"
        );
        let apart = |base: u32, end: u32| c_end <= base || end <= c_base;
        assert!(apart(b.base, b.end()), "C overlaps B");
        assert!(apart(a.base, a.end()), "C overlaps A");
        assert!(a.end() <= b.base || b.end() <= a.base, "A overlaps B");
        assert!(
            (a.base as usize).is_multiple_of(LOAD_BEATS)
                && (b.base as usize).is_multiple_of(LOAD_BEATS),
            "A and B must start at a multiple of {LOAD_BEATS} beats"
        );
        self.write_reg(REG_K_LEN, a.k as u64);
        self.write_reg(REG_A_BASE, a.base.into());
        self.write_reg(REG_B_BASE, b.base.into());
        self.write_reg(REG_C_BASE, c_base.into());
        // The sequencer walks the tiles in serpentine order: B tile j runs backwards in odd
        // row blocks, so a row block change keeps its B tile and loads only A.
        self.write_reg(REG_PANEL, panel_beats(a.k).into());
        let (mt, nt) = (a.m.div_ceil(TILE), b.n.div_ceil(TILE));
        // An int32 C row of the last B tile stores only the beats that hold columns below n.
        let skip = if control & CONTROL_QUANT == 0 {
            4 - c_row_beats(b.n - (nt - 1) * TILE)
        } else {
            0
        };
        self.write_reg(
            REG_TILES,
            (mt as u64) | (nt as u64) << 16 | (skip as u64) << 32,
        );
        self.write_reg(REG_CONTROL, control);
        self.tick();
        self.wait_until(Self::done)
    }

    /// Writes A and B (`TILE x k`) into external `bank` and loads them into the local A and B
    /// banks of the same number. Returns once the load is done; a compute on the other bank
    /// may run.
    pub fn preload_panel_i8(
        &mut self,
        bank: usize,
        a: &[i8],
        b: &[i8],
        k: usize,
    ) -> Result<(), RpuError> {
        self.write_panel_i8(bank, a, b, k);
        self.configure_bases(bank);
        self.write_control(bank, bank, CONTROL_PRELOAD);
        self.tick();
        self.wait_until_load_idle(Self::MAX_WAIT_CYCLES)
    }

    /// Starts the compute on local `bank`. Without a preloaded bank, the RPU loads first.
    pub fn start(&mut self, bank: usize) {
        self.configure_bases(bank);
        self.write_control(bank, bank, CONTROL_START);
        self.tick();
    }

    /// Reads the C tile that the last compute on `bank` stored.
    pub fn read_c(&self, bank: usize) -> Vec<i32> {
        unpack_i32(&self.read_words(Self::c_base(bank), (C_BEATS * BEAT_WORDS) as usize))
    }

    /// Writes the panels and sets K_LEN. Each row is padded to a whole number of beats.
    fn write_panel_i8(&mut self, bank: usize, a: &[i8], b: &[i8], k: usize) {
        assert!((1..=KMAX).contains(&k), "k must be in 1..={KMAX}");
        assert_eq!(a.len(), TILE * k, "A must be TILE x k");
        assert_eq!(b.len(), TILE * k, "B must be TILE x k");
        let a_base = Self::a_base(bank);
        self.write_words(a_base, &pack_panels(a, k));
        self.write_words(a_base + PANEL_BEATS, &pack_panels(b, k));
        self.write_reg(REG_K_LEN, k as u64);
    }

    fn read_reg(&self, addr: u32) -> u64 {
        unsafe { sys::rpu_read(self.inner.as_ptr(), addr) }
    }

    fn write_reg(&mut self, addr: u32, value: u64) {
        self.words_written += 1;
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
        self.words_read.set(self.words_read.get() + count as u64);
        (0..count).map(|i| self.read_reg(base + i as u32)).collect()
    }

    fn configure_bases(&mut self, bank: usize) {
        let a_base = Self::a_base(bank);
        self.write_reg(REG_A_BASE, a_base.into());
        self.write_reg(REG_B_BASE, (a_base + PANEL_BEATS).into());
        self.write_reg(REG_C_BASE, Self::c_base(bank).into());
    }

    /// Writes CONTROL with local B bank `bank` and local A bank `a_bank`.
    fn write_control(&mut self, bank: usize, a_bank: usize, flags: u64) {
        let bank_flag = if bank == 0 { 0 } else { CONTROL_BANK1 };
        let a_flag = if a_bank == 0 { 0 } else { CONTROL_A_BANK1 };
        self.write_reg(REG_CONTROL, flags | bank_flag | a_flag);
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

/// Beats of one panel: TILE rows of `k` int8, each padded to whole beats.
fn panel_beats(k: usize) -> u32 {
    (TILE * k.div_ceil(TILE)) as u32
}

/// `rows x k` padded with zero rows to whole tiles.
fn pad_rows(x: &[i8], rows: usize, k: usize) -> Vec<i8> {
    let mut v = x.to_vec();
    v.resize(rows.div_ceil(TILE) * TILE * k, 0);
    v
}

/// Packs panels of N `k`-long rows into 64-bit host words, column by column: beat c of
/// rows 0..N-1, then beat c + 1. Each row is zero-padded to whole beats and each beat to
/// whole words. Value 0 of a word is its low byte.
fn pack_panels(m: &[i8], k: usize) -> Vec<u64> {
    let beats = k.div_ceil(TILE);
    m.chunks_exact(TILE * k)
        .flat_map(|panel| {
            (0..beats).flat_map(move |c| {
                (0..TILE).map(move |r| &panel[r * k + c * TILE..r * k + k.min(c * TILE + TILE)])
            })
        })
        .flat_map(|beat| {
            let mut bytes = [0u8; 8 * BEAT_WORDS as usize];
            for (dst, &v) in bytes.iter_mut().zip(beat) {
                *dst = v as u8;
            }
            (0..BEAT_WORDS as usize)
                .map(move |w| u64::from_le_bytes(bytes[8 * w..8 * w + 8].try_into().unwrap()))
        })
        .collect()
}

/// The inverse of [`pack_panels`] for `m x k`, dropping padding rows and columns.
fn unpack_panels(words: &[u64], m: usize, k: usize) -> Vec<i8> {
    let beats = k.div_ceil(TILE);
    let bytes: Vec<i8> = words
        .chunks_exact(BEAT_WORDS as usize)
        .flat_map(|beat| beat.iter().flat_map(|w| w.to_le_bytes()).take(TILE))
        .map(|b| b as i8)
        .collect();
    let mut out = vec![0i8; m * k];
    for (i, row) in out.chunks_exact_mut(k).enumerate() {
        let (r, ri) = (i / TILE, i % TILE);
        for (col, v) in row.iter_mut().enumerate() {
            let beat = (r * beats + col / TILE) * TILE + ri;
            *v = bytes[beat * TILE + col % TILE];
        }
    }
    out
}

/// Reads int32 values back from beats of host words: the first N bytes of each beat.
/// Beats of a C row (4 per row) that hold its first `cols` int32.
fn c_row_beats(cols: usize) -> usize {
    (4 * cols).div_ceil(TILE)
}

fn unpack_i32(words: &[u64]) -> Vec<i32> {
    let bytes: Vec<u8> = words
        .chunks_exact(BEAT_WORDS as usize)
        .flat_map(|beat| beat.iter().flat_map(|w| w.to_le_bytes()).take(TILE))
        .collect();
    bytes
        .chunks_exact(4)
        .map(|b| i32::from_le_bytes(b.try_into().unwrap()))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    const N2: usize = TILE * TILE;

    #[test]
    fn host_word_counters_count_bus_traffic() {
        let mut rpu = Rpu::new().expect("RPU model");
        let panel = vec![1i8; TILE * TILE];
        let written = rpu.host_words_written();
        rpu.preload_panel_i8(0, &panel, &panel, TILE).unwrap();
        // A and B: one beat per row. K_LEN, three bases and CONTROL are register writes.
        let panel_words = (TILE * BEAT_WORDS as usize) as u64;
        assert_eq!(rpu.host_words_written() - written, 2 * panel_words + 5);
        let read = rpu.host_words_read();
        rpu.read_c(0);
        assert_eq!(
            rpu.host_words_read() - read,
            u64::from(C_BEATS * BEAT_WORDS)
        );
    }

    #[test]
    fn preload_overlaps_active_compute() {
        const K: usize = 3 * TILE;
        let mut rpu = Rpu::new().unwrap();
        rpu.preload_panel_i8(0, &[1; TILE * K], &[2; TILE * K], K)
            .unwrap();
        // Host writes take a cycle each, so write bank 1 before the compute starts.
        rpu.write_panel_i8(1, &[3; TILE * K], &[-4; TILE * K], K);
        rpu.start(0);
        assert!(rpu.compute_busy());

        // A and B: the new A goes to A bank 1 and must not touch the A of the running
        // compute.
        rpu.configure_bases(1);
        rpu.write_control(1, 1, CONTROL_PRELOAD);
        rpu.tick();
        assert!(rpu.compute_busy());
        assert!(rpu.load_busy());

        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(0), vec![2 * K as i32; N2]);

        rpu.wait_until_load_idle(Rpu::MAX_WAIT_CYCLES).unwrap();
        rpu.start(1);
        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(1), vec![-12 * K as i32; N2]);
    }

    #[test]
    fn keep_b_load_fills_only_a() {
        const K: usize = 3 * TILE;
        let mut rpu = Rpu::new().unwrap();
        rpu.preload_panel_i8(0, &[1; TILE * K], &[2; TILE * K], K)
            .unwrap();
        rpu.write_panel_i8(1, &[3; TILE * K], &[-4; TILE * K], K);
        rpu.start(0);

        // While B bank 0 computes, load only A into A bank 1. B_BASE points at a B the load
        // must not fetch.
        rpu.configure_bases(1);
        rpu.write_control(0, 1, CONTROL_PRELOAD | CONTROL_KEEP_B);
        rpu.tick();
        assert!(rpu.compute_busy());
        assert!(rpu.load_busy());

        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(0), vec![2 * K as i32; N2]);

        // The B of the last compute with the new A.
        rpu.wait_until_load_idle(Rpu::MAX_WAIT_CYCLES).unwrap();
        rpu.write_control(0, 1, CONTROL_START);
        rpu.tick();
        rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
        assert_eq!(rpu.read_c(1), vec![6 * K as i32; N2]);
    }

    #[test]
    fn resident_b_serves_many_a_and_any_placement() {
        let mut rpu = Rpu::new().expect("RPU model");
        let mut rng = quant::XorShift(0x0e51_de47_b000_0001);
        let (n, k) = (3 * TILE + 5, 200);
        let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
        // B after the scratch area, then B before it.
        for (b_base, scratch) in [(20_000, Some(0)), (0, None)] {
            let handle = rpu.upload_b(b_base, &b, n, k);
            let scratch = scratch.unwrap_or(handle.end());
            for m in [1, TILE, 2 * TILE + 3] {
                let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
                let got = rpu.matmul_resident(&a, m, &handle, scratch).unwrap();
                assert_eq!(got, quant::matmul_nt_i8(&a, &b, m, n, k), "m = {m}");
            }
        }
    }

    #[test]
    #[should_panic(expected = "scratch overlaps B")]
    fn resident_b_rejects_overlapping_scratch() {
        let mut rpu = Rpu::new().expect("RPU model");
        let handle = rpu.upload_b(0, &[1; TILE * 16], TILE, 16);
        let _ = rpu.matmul_resident(&[1; TILE * 16], TILE, &handle, handle.end() - 1);
    }

    #[test]
    fn gemm_writes_its_registers_once() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x5e9_0011_0000_0001);
        let (m, n, k) = (2 * TILE + 1, 3 * TILE, 40);
        let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
        let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
        let handle = rpu.upload_b(0, &b, n, k);
        let written = rpu.host_words_written();
        let got = rpu.matmul_resident(&a, m, &handle, handle.end()).unwrap();
        assert_eq!(got, quant::matmul_nt_i8(&a, &b, m, n, k));
        // A, then K_LEN, the three bases, PANEL, TILES and CONTROL for all nine tiles.
        let a_words = 3 * panel_beats(k) * BEAT_WORDS;
        assert_eq!(rpu.host_words_written() - written, u64::from(a_words) + 7);
    }

    fn random_requant(rng: &mut quant::XorShift) -> Requant {
        if rng.next_u64().is_multiple_of(2) {
            // Any value the hardware takes, mostly saturating.
            Requant {
                bias: rng.next_u64() as i32,
                mult: rng.next_u64() as u16,
                shift: (rng.next_u64() % 49) as u8,
                relu: rng.next_u64().is_multiple_of(2),
            }
        } else {
            // Outputs across the int8 range for |acc| up to about 127^2 * k.
            let acc_scale = 1e-5 * (1.0 + rng.f32_sym().abs());
            Requant::new(
                acc_scale,
                rng.f32_sym(),
                0.01,
                rng.next_u64().is_multiple_of(2),
            )
        }
    }

    fn requant_host(acc: &[i32], n: usize, params: &[Requant]) -> Vec<i8> {
        let col = |i: usize| &params[i % n];
        acc.iter()
            .enumerate()
            .map(|(i, &v)| col(i).apply(v))
            .collect()
    }

    #[test]
    fn gemm_requant_matches_the_host_rule() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x9e_0a07_0000_0001);
        for (m, n, k) in [
            (1, 1, 1),
            (TILE, TILE, TILE),
            (3, 2 * TILE + 5, 9),
            (2 * TILE + 1, 3 * TILE, 40),
            (3 * TILE, 5, 3 * TILE + 1),
            (TILE, 4 * TILE, 1),
        ] {
            let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
            let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
            let params: Vec<Requant> = (0..n).map(|_| random_requant(&mut rng)).collect();
            let bh = rpu.upload_b(0, &b, n, k);
            let ah = rpu.upload_a(bh.end(), &a, m, k);
            let written = rpu.host_words_written();
            let out = rpu.gemm_requant(&ah, &bh, &params, ah.end()).unwrap();
            // One word per column, then the seven GEMM registers.
            assert_eq!(rpu.host_words_written() - written, n as u64 + 7);
            let want = requant_host(&quant::matmul_nt_i8(&a, &b, m, n, k), n, &params);
            assert_eq!(rpu.read_a(&out), want, "{m}x{k} x {k}x{n}");
            // The int32 store still works after a requantized GEMM.
            let c = rpu.gemm_i32(&ah, &bh, out.end()).unwrap();
            assert_eq!(c, quant::matmul_nt_i8(&a, &b, m, n, k));
        }
    }

    /// A requantized tile stores in QUANT_PARTS cycles per row, an int32 one in 4.
    #[test]
    fn requantized_store_takes_quant_parts_cycles_per_row() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x9e_0a07_0000_0018);
        let (m, n, k) = (TILE, TILE, 40);
        let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
        let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
        let params: Vec<Requant> = (0..n).map(|_| random_requant(&mut rng)).collect();
        let bh = rpu.upload_b(0, &b, n, k);
        let ah = rpu.upload_a(bh.end(), &a, m, k);
        let busy = rpu.busy_cycles();
        rpu.gemm_i32(&ah, &bh, ah.end()).unwrap();
        let int32 = rpu.busy_cycles() - busy;
        let busy = rpu.busy_cycles();
        rpu.gemm_requant(&ah, &bh, &params, ah.end()).unwrap();
        let quant = rpu.busy_cycles() - busy;
        // The same tile, then QUANT_PARTS N store cycles and the 5 requantization stages
        // instead of 4N.
        assert_eq!(
            quant as usize + 4 * TILE,
            int32 as usize + QUANT_PARTS * TILE + 5
        );
    }

    /// An int32 GEMM stores, of each C row of its last B tile, only the beats that hold
    /// columns below n; the other beats keep what was there.
    #[test]
    fn last_b_tile_stores_only_its_columns() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x5707_e000_0000_0017);
        for n in [TILE + 1, 2 * TILE - 1] {
            // Three row blocks: the GEMM ends on the last B tile.
            let (m, k) = (2 * TILE + 1, 40);
            let a: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
            let b: Vec<i8> = (0..n * k).map(|_| rng.i8_sym()).collect();
            let bh = rpu.upload_b(0, &b, n, k);
            let ah = rpu.upload_a(bh.end(), &a, m, k);
            let c_base = ah.end();
            let words = (6 * C_BEATS * BEAT_WORDS) as usize;
            rpu.write_words(c_base, &vec![0x5a5a_5a5a_5a5a_5a5a; words]);
            let before = rpu.read_words(c_base, words);
            let c = rpu.gemm_i32(&ah, &bh, c_base).unwrap();
            assert_eq!(c, quant::matmul_nt_i8(&a, &b, m, n, k));
            let after = rpu.read_words(c_base, words);
            let stored = c_row_beats(n - TILE);
            for (beat, (x, y)) in after
                .chunks(BEAT_WORDS as usize)
                .zip(before.chunks(BEAT_WORDS as usize))
                .enumerate()
            {
                let (j, part) = (beat / C_BEATS as usize % 2, beat % 4);
                let written = j == 0 || part < stored;
                assert_eq!(x != y, written, "n = {n}, beat {beat}");
            }
            // A tile started by the host after the GEMM stores whole rows again.
            let a: Vec<i8> = (0..N2).map(|_| rng.i8_sym()).collect();
            let b: Vec<i8> = (0..N2).map(|_| rng.i8_sym()).collect();
            let c = rpu.run_tile_i8(&a, &b).unwrap();
            assert_eq!(c, quant::matmul_nt_i8(&a, &b, TILE, TILE, TILE));
        }
    }

    /// Layer 2 reads the int8 output of layer 1 straight from RPU memory.
    #[test]
    fn requantized_output_feeds_the_next_gemm() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x9e_0a07_0000_0002);
        let (m, k, n1, n2) = (2 * TILE + 3, 50, 3 * TILE + 2, 7);
        let x: Vec<i8> = (0..m * k).map(|_| rng.i8_sym()).collect();
        let w1: Vec<i8> = (0..n1 * k).map(|_| rng.i8_sym()).collect();
        let w2: Vec<i8> = (0..n2 * n1).map(|_| rng.i8_sym()).collect();
        let params: Vec<Requant> = (0..n1).map(|_| random_requant(&mut rng)).collect();
        let b1 = rpu.upload_b(0, &w1, n1, k);
        let b2 = rpu.upload_b(b1.end(), &w2, n2, n1);
        let a1 = rpu.upload_a(b2.end(), &x, m, k);
        let a2 = rpu.gemm_requant(&a1, &b1, &params, a1.end()).unwrap();
        let read = rpu.host_words_read();
        let c = rpu.gemm_i32(&a2, &b2, a2.end()).unwrap();
        let h = requant_host(&quant::matmul_nt_i8(&x, &w1, m, n1, k), n1, &params);
        assert_eq!(c, quant::matmul_nt_i8(&h, &w2, m, n2, n1));
        // Only the final C crosses the host link.
        let row_beats: usize = (0..n2.div_ceil(TILE))
            .map(|j| c_row_beats(TILE.min(n2 - j * TILE)))
            .sum();
        let c_words = m * row_beats * BEAT_WORDS as usize;
        assert_eq!(rpu.host_words_read() - read, c_words as u64);
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
            // One B tile: every tile after the first preloads a new A.
            (3 * TILE, 5, 30),
            // Around the shortest K whose stream may start during the drain before (3N).
            (2 * TILE, 4 * TILE, 3 * TILE - 1),
            (2 * TILE, 4 * TILE, 3 * TILE),
            (2 * TILE, 4 * TILE, 3 * TILE + 1),
        ] {
            assert_gemm_exact(&mut rpu, m, n, k, &mut rng);
        }
    }

    /// The next START as soon as the stream ends, with K just under and at the shortest K
    /// that may overlap the drain (3N). The driver's handshake is slower than this.
    #[test]
    fn start_right_after_stream_end() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x5bad_0005_57a2_0002);
        for k in 3 * TILE - 4..=3 * TILE {
            let mut panel = || -> Vec<i8> { (0..TILE * k).map(|_| rng.i8_sym()).collect() };
            let (a0, b0, a1, b1) = (panel(), panel(), panel(), panel());
            rpu.preload_panel_i8(0, &a0, &b0, k).unwrap();
            rpu.preload_panel_i8(1, &a1, &b1, k).unwrap();
            rpu.write_reg(REG_C_BASE, Rpu::c_base(0).into());
            rpu.write_control(0, 0, CONTROL_START);
            rpu.tick();
            rpu.write_reg(REG_C_BASE, Rpu::c_base(1).into());
            rpu.wait_until(|rpu| !rpu.compute_busy()).unwrap();
            rpu.write_control(1, 1, CONTROL_START);
            rpu.wait_until_done(Rpu::MAX_WAIT_CYCLES).unwrap();
            let want = |a: &[i8], b: &[i8]| quant::matmul_nt_i8(a, b, TILE, TILE, k);
            assert_eq!(rpu.read_c(0), want(&a0, &b0), "k = {k}, tile 0");
            assert_eq!(rpu.read_c(1), want(&a1, &b1), "k = {k}, tile 1");
        }
    }

    #[test]
    fn next_tile_streams_during_drain() {
        let mut rpu = Rpu::new().unwrap();
        let mut rng = quant::XorShift(0x5bad_0005_d7a1_0001);
        // K a multiple of N, so every preload of B (or of A only, at a row block change)
        // takes exactly K beats.
        let k = 25.min(KMAX / TILE) * TILE;
        let latency: usize = env!("RPU_READ_LATENCY").parse().unwrap();
        for (blocks, n_tiles) in [(1, 8), (3, 3)] {
            let tiles = blocks * n_tiles;
            let (active, busy) = (rpu.active_cycles(), rpu.busy_cycles());
            assert_gemm_exact(&mut rpu, blocks * TILE, n_tiles * TILE, k, &mut rng);
            let (active, busy) = (rpu.active_cycles() - active, rpu.busy_cycles() - busy);
            println!("{blocks} x {n_tiles} tiles, K = {k}: active {active} / busy {busy} cycles");
            assert_eq!(active as usize, tiles * k);
            // Idle array cycles: the part of the first A + B load that the first stream does
            // not overlap (K + 2N, or 2N / LOAD_BEATS + 1 when the load keeps up with the
            // stream), the last settle, drain and store (7N), and per tile the
            // read latency of its load and a few cycles of START handshake, but no settle or
            // drain per tile and no B load at a row block change.
            let idle = busy as usize - tiles * k;
            let first = if LOAD_BEATS == 1 {
                k + 2 * TILE
            } else {
                2 * TILE / LOAD_BEATS + 1
            };
            let bound = first + latency + 7 * TILE + tiles * (latency + 8);
            assert!(idle <= bound, "{idle} idle cycles, bound {bound}");
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
    fn panel_load_moves_load_beats_per_cycle() {
        let latency: u32 = env!("RPU_READ_LATENCY").parse().unwrap();
        let mut rpu = Rpu::new().unwrap();
        for k in [1, 9, 784] {
            let panel = vec![1i8; TILE * k];
            let busy = rpu.busy_cycles();
            rpu.preload_panel_i8(0, &panel, &panel, k).unwrap();
            let beats = 2 * TILE as u32 * k.div_ceil(TILE) as u32;
            let requests = beats / LOAD_BEATS as u32;
            assert_eq!(rpu.busy_cycles() - busy, requests + latency, "k = {k}");
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
