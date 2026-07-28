use hardware_dev::Rpu;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rpu = Rpu::new()?;

    let a = [[1.5, 2.0], [0.0, 1.0]];
    let b = [[2.0, 0.0], [0.0, 3.0]];
    let c = rpu.multiply(a, b)?;
    println!("[ {:>6.2}  {:>6.2} ]", c[0][0], c[0][1]);
    println!("[ {:>6.2}  {:>6.2} ]", c[1][0], c[1][1]);

    Ok(())
}
