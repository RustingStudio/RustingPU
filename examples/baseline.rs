//! Prints the cycle counts of one tile job, one K = 784 panel job and layer 1 of the MLP
//! for batch 8 (8x784 x 784x128). See docs/baseline.md and docs/progress.md.
use rusting_pu::{Rpu, TILE};

/// C is stored as 4 beats per row, one beat per cycle.
const STORE_CYCLES: u32 = 4 * TILE as u32;

/// Busy cycles of a preload, and cycles of the following compute + store.
fn job(rpu: &mut Rpu, k: usize) -> Result<(u32, u32), Box<dyn std::error::Error>> {
    let panel = vec![1i8; TILE * k];
    let busy = rpu.busy_cycles();
    rpu.preload_panel_i8(0, &panel, &panel, k)?;
    let load = rpu.busy_cycles() - busy;
    // run_panel_i8 preloads again, then START resets the counter, so this is compute + store.
    rpu.run_panel_i8(&panel, &panel, k)?;
    Ok((load, rpu.cycles()))
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rpu = Rpu::new()?;
    for k in [TILE, 784] {
        let active = rpu.active_cycles();
        let (load, total) = job(&mut rpu, k)?;
        let streamed = rpu.active_cycles() - active;
        println!(
            "K={k}: load A+B {load} cycles; compute + store C {total} = compute {} \
             (streaming {streamed}) + store {STORE_CYCLES}",
            total - STORE_CYCLES,
        );
    }
    let (m, n, k) = (8, 128, 784);
    let (active, busy) = (rpu.active_cycles(), rpu.busy_cycles());
    rpu.matmul_nt_i8(&vec![1; m * k], &vec![1; n * k], m, n, k)?;
    let (active, busy) = (rpu.active_cycles() - active, rpu.busy_cycles() - busy);
    println!(
        "layer 1 {m}x{k} x {k}x{n}: busy {busy} cycles, streaming {active} ({:.2}%)",
        100.0 * f64::from(active) / f64::from(busy)
    );
    Ok(())
}
