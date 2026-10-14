//! Prints the cycle counts of one 8x8 tile job. See docs/baseline.md.
use hardware_dev::{BFloat16, Rpu, TILE};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let one = BFloat16::from_f32(1.0)?;
    let a = [one; TILE * TILE];
    let b = [one; TILE * TILE];

    let mut rpu = Rpu::new()?;
    rpu.preload_tile(0, a, b)?;
    println!("load A+B:          {} cycles", rpu.cycles());

    // run_tile preloads again, then START resets the counter, so this is compute + store only.
    rpu.run_tile(a, b)?;
    println!("compute + store C: {} cycles", rpu.cycles());
    Ok(())
}
