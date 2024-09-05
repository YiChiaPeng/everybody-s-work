library verilog;
use verilog.vl_types.all;
entity sametime_counter_12bit_vlg_check_tst is
    port(
        A               : in     vl_logic;
        B               : in     vl_logic;
        C               : in     vl_logic;
        CAS             : in     vl_logic;
        D               : in     vl_logic;
        E               : in     vl_logic;
        F               : in     vl_logic;
        G               : in     vl_logic;
        H               : in     vl_logic;
        I               : in     vl_logic;
        J               : in     vl_logic;
        K               : in     vl_logic;
        L               : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end sametime_counter_12bit_vlg_check_tst;
