fn main() {
    let base = std::env::var("CARGO_MANIFEST_DIR").unwrap();
    let obj_dir = format!("{}/obj_dir", std::env::var("OUT_DIR").unwrap());
    let verilator_inc = "/usr/share/verilator/include".to_string();

    let rtl_files = [
        "rtl/delay_cell.sv",
        "rtl/int8_cell.sv",
        "rtl/rpu_array.sv",
        "rtl/rpu_sim_memory.sv",
        "rtl/rpu_top.sv",
    ];

    // Array size, memory read latency, beats per load request and store cycles per
    // requantized row, e.g. RPU_N=16 RPU_READ_LATENCY=10 RPU_LOAD_BEATS=2 cargo test.
    let n = std::env::var("RPU_N").unwrap_or_else(|_| "8".into());
    let read_latency = std::env::var("RPU_READ_LATENCY").unwrap_or_else(|_| "1".into());
    let load_beats = std::env::var("RPU_LOAD_BEATS").unwrap_or_else(|_| "1".into());
    let quant_parts = std::env::var("RPU_QUANT_PARTS").unwrap_or_else(|_| "4".into());

    // A rebuild with other parameters can emit fewer files; never compile stale ones.
    let _ = std::fs::remove_dir_all(&obj_dir);

    let mut cmd = std::process::Command::new("verilator");
    cmd.args(["--cc", "-Wno-CASEINCOMPLETE", "--top-module", "rpu_top"])
        .arg(format!("-GN={n}"))
        .arg(format!("-GREAD_LATENCY={read_latency}"))
        .arg(format!("-GLOAD_BEATS={load_beats}"))
        .arg(format!("-GQUANT_PARTS={quant_parts}"))
        .args(["-Mdir", &obj_dir]);
    for f in &rtl_files {
        cmd.arg(format!("{}/{}", base, f));
    }
    let status = cmd.status().expect("verilator not found");
    assert!(status.success(), "Verilator failed");

    let mut build = cc::Build::new();
    build.cpp(true).flag("-O2").flag("-w");

    for entry in std::fs::read_dir(&obj_dir).expect("failed to read Verilator obj_dir") {
        let path = entry.expect("failed to read Verilator output").path();
        let Some(file_name) = path.file_name().and_then(|name| name.to_str()) else {
            continue;
        };

        if file_name.starts_with("Vrpu_top") && file_name.ends_with(".cpp") {
            build.file(path);
        }
    }

    build.file(format!("{}/verilated_wrapper/wrapper.cpp", base));
    build.file(format!("{}/verilated.cpp", verilator_inc));
    build.file(format!("{}/verilated_threads.cpp", verilator_inc));
    build.include(&obj_dir);
    build.include(&verilator_inc);
    build.compile("rpu_soc");

    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-env-changed=RPU_N");
    println!("cargo:rustc-env=RPU_N={n}");
    println!("cargo:rerun-if-env-changed=RPU_READ_LATENCY");
    println!("cargo:rustc-env=RPU_READ_LATENCY={read_latency}");
    println!("cargo:rerun-if-env-changed=RPU_LOAD_BEATS");
    println!("cargo:rustc-env=RPU_LOAD_BEATS={load_beats}");
    println!("cargo:rerun-if-env-changed=RPU_QUANT_PARTS");
    println!("cargo:rustc-env=RPU_QUANT_PARTS={quant_parts}");
    for f in &rtl_files {
        println!("cargo:rerun-if-changed={}", f);
    }
    println!("cargo:rerun-if-changed=verilated_wrapper/wrapper.cpp");
    println!("cargo:rerun-if-changed=verilated_wrapper/wrapper.h");
}
