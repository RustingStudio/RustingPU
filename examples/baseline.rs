//! Prints the cycle counts of one tile job. See docs/baseline.md.
use hardware_dev::{Rpu, TILE};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let a = vec![1i8; TILE * TILE];
    let b = vec![1i8; TILE * TILE];

    let mut rpu = Rpu::new()?;
    rpu.preload_tile_i8(0, &a, &b)?;
    println!("load A+B:          {} cycles", rpu.cycles());

    // run_tile_i8 preloads again, then START resets the counter, so this is compute + store only.
    rpu.run_tile_i8(&a, &b)?;
    println!("compute + store C: {} cycles", rpu.cycles());
    Ok(())
}
