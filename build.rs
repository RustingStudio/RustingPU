fn main() {
    let base = std::env::var("CARGO_MANIFEST_DIR").unwrap();
    let obj_dir = format!("{}/obj_dir", std::env::var("OUT_DIR").unwrap());
    let verilator_inc = "/usr/share/verilator/include".to_string();

    let rtl_files = [
        "rtl/delay_cell.sv",
        "rtl/bf16_multiplier.sv",
        "rtl/bf16_adder.sv",
        "rtl/bf16_systolic_cell.sv",
        "rtl/rpu_orchestrator_bf16.sv",
        "rtl/rpu_sim_memory.sv",
        "rtl/rpu_bf16_soc.sv",
    ];

    let mut cmd = std::process::Command::new("verilator");
    cmd.args([
        "--cc",
        "-Wno-CASEINCOMPLETE",
        "--top-module",
        "rpu_bf16_soc",
    ])
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

        if file_name.starts_with("Vrpu_bf16_soc") && file_name.ends_with(".cpp") {
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
    for f in &rtl_files {
        println!("cargo:rerun-if-changed={}", f);
    }
    println!("cargo:rerun-if-changed=verilated_wrapper/wrapper.cpp");
    println!("cargo:rerun-if-changed=verilated_wrapper/wrapper.h");
}
