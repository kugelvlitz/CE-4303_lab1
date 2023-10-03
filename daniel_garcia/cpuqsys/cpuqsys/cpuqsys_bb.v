
module cpuqsys (
	clk_clk,
	new_sdram_controller_0_wire_addr,
	new_sdram_controller_0_wire_ba,
	new_sdram_controller_0_wire_cas_n,
	new_sdram_controller_0_wire_cke,
	new_sdram_controller_0_wire_cs_n,
	new_sdram_controller_0_wire_dq,
	new_sdram_controller_0_wire_dqm,
	new_sdram_controller_0_wire_ras_n,
	new_sdram_controller_0_wire_we_n,
	pio_continue_0_external_connection_export,
	pio_leds_0_external_connection_export,
	reset_reset_n,
	pio_display1_0_external_connection_export,
	pio_display2_0_external_connection_export,
	pio_display3_0_external_connection_export,
	pio_display4_0_external_connection_export,
	pio_display5_0_external_connection_export,
	pio_display6_0_external_connection_export);	

	input		clk_clk;
	output	[13:0]	new_sdram_controller_0_wire_addr;
	output	[1:0]	new_sdram_controller_0_wire_ba;
	output		new_sdram_controller_0_wire_cas_n;
	output		new_sdram_controller_0_wire_cke;
	output		new_sdram_controller_0_wire_cs_n;
	inout	[31:0]	new_sdram_controller_0_wire_dq;
	output	[3:0]	new_sdram_controller_0_wire_dqm;
	output		new_sdram_controller_0_wire_ras_n;
	output		new_sdram_controller_0_wire_we_n;
	input		pio_continue_0_external_connection_export;
	output	[7:0]	pio_leds_0_external_connection_export;
	input		reset_reset_n;
	output	[6:0]	pio_display1_0_external_connection_export;
	output	[6:0]	pio_display2_0_external_connection_export;
	output	[6:0]	pio_display3_0_external_connection_export;
	output	[6:0]	pio_display4_0_external_connection_export;
	output	[6:0]	pio_display5_0_external_connection_export;
	output	[6:0]	pio_display6_0_external_connection_export;
endmodule
