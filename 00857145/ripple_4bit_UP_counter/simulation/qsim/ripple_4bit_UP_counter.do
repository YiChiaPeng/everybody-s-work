onerror {exit -code 1}
vlib work
vlog -work work ripple_4bit_UP_counter.vo
vlog -work work Waveformcounter_12bit.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiv_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.sametime_counter_12bit_vlg_vec_tst -voptargs="+acc"
vcd file -direction ripple_4bit_UP_counter.msim.vcd
vcd add -internal sametime_counter_12bit_vlg_vec_tst/*
vcd add -internal sametime_counter_12bit_vlg_vec_tst/i1/*
run -all
quit -f
