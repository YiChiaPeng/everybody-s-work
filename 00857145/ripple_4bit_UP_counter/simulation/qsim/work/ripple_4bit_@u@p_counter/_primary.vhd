library verilog;
use verilog.vl_types.all;
entity ripple_4bit_UP_counter is
    port(
        A               : out    vl_logic;
        CLK             : in     vl_logic;
        B               : out    vl_logic;
        C               : out    vl_logic;
        D               : out    vl_logic
    );
end ripple_4bit_UP_counter;
