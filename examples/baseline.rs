//! Prints the cycle counts of one tile job. See docs/baseline.md.
use hardware_dev::{Rpu, TILE};

/// Words of C x 3 cycles per word (`rpu_sim_memory` handshake).
const STORE_CYCLES: u32 = (TILE * TILE * 2 * 3) as u32;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let a = vec![1i8; TILE * TILE];
    let b = vec![1i8; TILE * TILE];

    let mut rpu = Rpu::new()?;
    rpu.preload_panel_i8(0, &a, &b, TILE)?;
    println!("load A+B:          {} cycles", rpu.cycles());

    // run_tile_i8 preloads again, then START resets the counter, so this is compute + store only.
    rpu.run_tile_i8(&a, &b)?;
    println!("compute + store C: {} cycles", rpu.cycles());

    // One K = 784 panel job (8x784 x 784x8), as in MNIST layer 1.
    let k = 784;
    let panel = vec![1i8; TILE * k];
    let active = rpu.active_cycles();
    rpu.run_panel_i8(&panel, &panel, k)?;
    let total = rpu.cycles();
    println!(
        "K={k}: compute + store C {total} cycles, compute {} (streaming {}), store {STORE_CYCLES}",
        total - STORE_CYCLES,
        rpu.active_cycles() - active,
    );
    Ok(())
}
