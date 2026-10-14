//! MNIST end to end: train a 784-128-10 MLP with RustingBrain on the CPU (or load the saved
//! one), then classify the 10k test images in f32, host int8 and on the RPU.
//!
//! ```text
//! cargo run --release --features brain --example mnist [data/mnist]
//! RPU_N=16 cargo run --release --features brain --example mnist
//! ```
//!
//! The data directory holds the four unpacked MNIST IDX files. The trained network is saved
//! as `mnist-784-128-10.json` in it, so every array size evaluates the same weights.
use rusting_brain::{Activation, Dataset, Loss, Network, Optimizer, TrainConfig};
use rusting_pu::brain::RpuMlp;
use rusting_pu::{Rpu, TILE};
use std::path::Path;
use std::time::Instant;

/// Images per RPU batch. One activation scale covers the whole batch.
const BATCH: usize = 64;
const SEED: u64 = 0x6d6e_6973_7400_0001;

fn argmax(v: &[f32]) -> usize {
    (0..v.len()).fold(0, |best, i| if v[i] > v[best] { i } else { best })
}

fn train_or_load(dir: &Path) -> Result<Network, Box<dyn std::error::Error>> {
    let path = dir.join("mnist-784-128-10.json");
    if path.exists() {
        println!("loading {}", path.display());
        return Ok(Network::load_json(&path)?);
    }
    let mut train = Dataset::from_idx(
        dir.join("train-images-idx3-ubyte"),
        dir.join("train-labels-idx1-ubyte"),
    )?;
    train.one_hot_targets(10)?;
    let mut network = Network::builder()
        .input_size(784)
        .dense(128, Activation::Relu)
        .dense(10, Activation::Softmax)
        .loss(Loss::CrossEntropy)
        .optimizer(Optimizer::adam(1e-3))
        .seed(SEED)
        .build();
    let config = TrainConfig {
        epochs: 3,
        batch_size: 32,
        shuffle: true,
        seed: Some(SEED),
    };
    let start = Instant::now();
    network.fit_with(&train, config, |epoch, loss| {
        println!("epoch {epoch}: loss {loss:.4}");
        true
    })?;
    println!("trained in {:.1} s", start.elapsed().as_secs_f64());
    network.save_json(&path)?;
    Ok(network)
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let dir = std::env::args()
        .nth(1)
        .unwrap_or_else(|| "data/mnist".into());
    let dir = Path::new(&dir);
    let network = train_or_load(dir)?;
    let test = Dataset::from_idx(
        dir.join("t10k-images-idx3-ubyte"),
        dir.join("t10k-labels-idx1-ubyte"),
    )?;
    let labels: Vec<usize> = test.targets.iter().map(|t| t[0] as usize).collect();
    let count = labels.len();
    let correct = |outputs: &[Vec<f32>]| {
        outputs
            .iter()
            .zip(&labels)
            .filter(|(o, &l)| argmax(o) == l)
            .count()
    };

    let f32_correct = correct(&network.predict_batch(&test.inputs)?);
    let mut mlp = RpuMlp::from_network(&network);
    let mut rpu = Rpu::new()?;
    let (mut host, mut on_rpu) = (Vec::with_capacity(count), Vec::with_capacity(count));
    let (active, busy) = (rpu.active_cycles(), rpu.busy_cycles());
    let (written, read) = (rpu.host_words_written(), rpu.host_words_read());
    let start = Instant::now();
    for batch in test.inputs.chunks(BATCH) {
        let h = mlp.predict_batch_host(batch);
        let r = mlp.predict_batch(&mut rpu, batch)?;
        assert_eq!(r, h, "RPU and host int8 outputs must be bit-identical");
        host.extend(h);
        on_rpu.extend(r);
    }
    let wall = start.elapsed().as_secs_f64();
    let (active, busy) = (rpu.active_cycles() - active, rpu.busy_cycles() - busy);
    let (written, read) = (
        rpu.host_words_written() - written,
        rpu.host_words_read() - read,
    );
    let (host_correct, rpu_correct) = (correct(&host), correct(&on_rpu));

    let pct = |c: usize| 100.0 * c as f64 / count as f64;
    println!("N = {TILE}, batch {BATCH}, {count} test images");
    println!("f32       {f32_correct} correct, {:.2}%", pct(f32_correct));
    println!(
        "host int8 {host_correct} correct, {:.2}%",
        pct(host_correct)
    );
    println!("RPU       {rpu_correct} correct, {:.2}%", pct(rpu_correct));
    println!("f32 - int8: {:.2} pp", pct(f32_correct) - pct(host_correct));
    println!(
        "RPU busy {busy} cycles, {:.1} cycles per image, streaming {active} ({:.2}%)",
        f64::from(busy) / count as f64,
        100.0 * f64::from(active) / f64::from(busy)
    );
    println!(
        "host link: {:.1} words written, {:.1} words read per image (64-bit words)",
        written as f64 / count as f64,
        read as f64 / count as f64
    );
    println!("simulation wall time {wall:.1} s (host int8 included)");
    Ok(())
}
