library verilog;
use verilog.vl_types.all;
entity sametime_counter_12bit is
    port(
        A               : out    vl_logic;
        EN              : in     vl_logic;
        CLK             : in     vl_logic;
        B               : out    vl_logic;
        C               : out    vl_logic;
        D               : out    vl_logic;
        E               : out    vl_logic;
        F               : out    vl_logic;
        G               : out    vl_logic;
        H               : out    vl_logic;
        I               : out    vl_logic;
        J               : out    vl_logic;
        K               : out    vl_logic;
        L               : out    vl_logic;
        CAS             : out    vl_logic
    );
end sametime_counter_12bit;
