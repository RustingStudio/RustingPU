fn main() {
    let base = std::env::var("CARGO_MANIFEST_DIR").unwrap();
    let obj_dir = format!("{}/obj_dir", base);
    let verilator_inc = "/usr/share/verilator/include".to_string();

    let rtl_files = [
        "rtl/rpu_soc.sv",
        "rtl/rpu_orchestrator.sv",
        "rtl/rpu_core_2x2.sv",
        "rtl/systolic_cell.sv",
        "rtl/delay_cell.sv",
        "rtl/mac_unit.sv",
        "rtl/sram.sv",
        "rtl/dma_streamer.sv",
    ];

    let mut cmd = std::process::Command::new("verilator");
    cmd.args(["--cc", "-Wno-CASEINCOMPLETE", "--top-module", "rpu_soc"])
        .args(["-Mdir", &obj_dir]);
    for f in &rtl_files {
        cmd.arg(format!("{}/{}", base, f));
    }
    let status = cmd.status().expect("verilator not found");
    assert!(status.success(), "Verilator failed");

    let gen_cpp = [
        "Vrpu_soc.cpp",
        "Vrpu_soc___024root__0.cpp",
        "Vrpu_soc___024root__0__Slow.cpp",
        "Vrpu_soc___024root__Slow.cpp",
        "Vrpu_soc__ConstPool__0__Slow.cpp",
        "Vrpu_soc__Syms__Slow.cpp",
    ];

    let mut build = cc::Build::new();
    build.cpp(true)
        .flag("-Os")
        .flag("-w");
    for f in &gen_cpp {
        build.file(format!("{}/{}", obj_dir, f));
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
