//! Prints the cycle counts of one tile job and one K = 784 panel job. See docs/baseline.md.
use hardware_dev::{Rpu, TILE};

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
    Ok(())
}
