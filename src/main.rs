use rusting_pu::{quant, Rpu, TILE};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rpu = Rpu::new()?;
    let a: Vec<i8> = (0..TILE * TILE).map(|i| (i % 7) as i8 - 3).collect();
    let b: Vec<i8> = (0..TILE * TILE).map(|i| (i % 5) as i8 - 2).collect();

    let c = rpu.run_tile_i8(&a, &b)?;
    for row in c.chunks(TILE) {
        println!("{row:?}");
    }
    assert_eq!(c, quant::matmul_nt_i8(&a, &b, TILE, TILE, TILE));
    println!("matches host reference, {} cycles", rpu.cycles());
    Ok(())
}
