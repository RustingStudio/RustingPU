mod sys {
    #[repr(C)]
    pub struct Rpu(std::ffi::c_void);

    extern "C" {
        pub fn rpu_new() -> *mut Rpu;
        pub fn rpu_free(r: *mut Rpu);
        pub fn rpu_set_clk(r: *mut Rpu, v: u8);
        pub fn rpu_set_reset(r: *mut Rpu, v: u8);
        pub fn rpu_set_cpu_we(r: *mut Rpu, v: u8);
        pub fn rpu_set_cpu_addr(r: *mut Rpu, v: u8);
        pub fn rpu_set_wdata_a(r: *mut Rpu, v: u8);
        pub fn rpu_set_wdata_b(r: *mut Rpu, v: u8);
        pub fn rpu_set_dma_start(r: *mut Rpu, v: u8);
        pub fn rpu_get_c00(r: *mut Rpu) -> u8;
        pub fn rpu_get_c01(r: *mut Rpu) -> u8;
        pub fn rpu_get_c10(r: *mut Rpu) -> u8;
        pub fn rpu_get_c11(r: *mut Rpu) -> u8;
        pub fn rpu_tick(r: *mut Rpu);
    }
}

fn main() {
    unsafe {
        let rpu = sys::rpu_new();

        sys::rpu_set_reset(rpu, 1);
        sys::rpu_tick(rpu);

        sys::rpu_set_cpu_we(rpu, 1);

        sys::rpu_set_cpu_addr(rpu, 0);
        sys::rpu_set_wdata_a(rpu, 0x31);
        sys::rpu_set_wdata_b(rpu, 0x65);
        sys::rpu_tick(rpu);

        sys::rpu_set_cpu_addr(rpu, 1);
        sys::rpu_set_wdata_a(rpu, 0x42);
        sys::rpu_set_wdata_b(rpu, 0x87);
        sys::rpu_tick(rpu);

        sys::rpu_set_cpu_we(rpu, 0);
        sys::rpu_set_reset(rpu, 0);
        sys::rpu_set_dma_start(rpu, 1);
        sys::rpu_tick(rpu);
        sys::rpu_set_dma_start(rpu, 0);

        for _ in 0..6 {
            sys::rpu_tick(rpu);
        }

        let c00 = sys::rpu_get_c00(rpu);
        let c01 = sys::rpu_get_c01(rpu);
        let c10 = sys::rpu_get_c10(rpu);
        let c11 = sys::rpu_get_c11(rpu);

        println!("[ {:>3}  {:>3} ]", c00, c01);
        println!("[ {:>3}  {:>3} ]", c10, c11);

        assert_eq!(c00, 19, "c00 mismatch");
        assert_eq!(c01, 22, "c01 mismatch");
        assert_eq!(c10, 43, "c10 mismatch");
        assert_eq!(c11, 50, "c11 mismatch");

        println!("Correct!");
        sys::rpu_free(rpu);
    }
}
