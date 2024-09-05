library verilog;
use verilog.vl_types.all;
entity sametime_counter_12bit_vlg_sample_tst is
    port(
        CLK             : in     vl_logic;
        EN              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end sametime_counter_12bit_vlg_sample_tst;
