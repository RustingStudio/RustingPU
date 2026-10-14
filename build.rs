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

    // Array size and memory read latency, e.g. RPU_N=16 RPU_READ_LATENCY=10 cargo test.
    let n = std::env::var("RPU_N").unwrap_or_else(|_| "8".into());
    let read_latency = std::env::var("RPU_READ_LATENCY").unwrap_or_else(|_| "1".into());

    // A rebuild with other parameters can emit fewer files; never compile stale ones.
    let _ = std::fs::remove_dir_all(&obj_dir);

    let mut cmd = std::process::Command::new("verilator");
    cmd.args(["--cc", "-Wno-CASEINCOMPLETE", "--top-module", "rpu_top"])
        .arg(format!("-GN={n}"))
        .arg(format!("-GREAD_LATENCY={read_latency}"))
        .args(["-Mdir", &obj_dir]);
    for f in &rtl_files {
        cmd.arg(format!("{}/{}", base, f));
    }
    let status = cmd.status().expect("verilator not found");
    assert!(status.success(), "Verilator failed");

    let mut build = cc::Build::new();
    build.cpp(true).flag("-Os").flag("-w");

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
    for f in &rtl_files {
        println!("cargo:rerun-if-changed={}", f);
    }
    println!("cargo:rerun-if-changed=verilated_wrapper/wrapper.cpp");
    println!("cargo:rerun-if-changed=verilated_wrapper/wrapper.h");
}
