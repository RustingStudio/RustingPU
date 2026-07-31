use hardware_dev::{DynMatrix, Rpu};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rpu = Rpu::new()?;

    let a = DynMatrix {
        rows: 3,
        cols: 5,
        data: (0..15).map(|i| i as f32).collect(),
    };
    let b = DynMatrix {
        rows: 5,
        cols: 4,
        data: (0..20).map(|i| (20 - i) as f32).collect(),
    };

    let c = rpu.multiply_dyn(&a, &b)?;
    println!("Matrix {}", c);

    Ok(())
}
