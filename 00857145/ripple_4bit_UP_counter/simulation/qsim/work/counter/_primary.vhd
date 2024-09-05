library verilog;
use verilog.vl_types.all;
entity counter is
    port(
        A               : out    vl_logic;
        EN              : in     vl_logic;
        CLK             : in     vl_logic;
        B               : out    vl_logic;
        C               : out    vl_logic;
        D               : out    vl_logic;
        CAS             : out    vl_logic
    );
end counter;
