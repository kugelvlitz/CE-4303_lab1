
module plattform (
	clk_clk,
	pio_auto_manual_0_external_connection_export,
	pio_continue_0_external_connection_export,
	pio_display1_0_external_connection_export,
	pio_display2_0_external_connection_export,
	pio_display3_0_external_connection_export,
	pio_display4_0_external_connection_export,
	pio_display5_0_external_connection_export,
	pio_display6_0_external_connection_export,
	pio_leds_0_external_connection_export,
	pio_left_right_0_external_connection_export,
	pio_set_value_0_external_connection_export,
	pio_up_down_0_external_connection_export,
	reset_reset_n);	

	input		clk_clk;
	input		pio_auto_manual_0_external_connection_export;
	input		pio_continue_0_external_connection_export;
	output	[6:0]	pio_display1_0_external_connection_export;
	output	[6:0]	pio_display2_0_external_connection_export;
	output	[6:0]	pio_display3_0_external_connection_export;
	output	[6:0]	pio_display4_0_external_connection_export;
	output	[6:0]	pio_display5_0_external_connection_export;
	output	[6:0]	pio_display6_0_external_connection_export;
	output	[1:0]	pio_leds_0_external_connection_export;
	input	[1:0]	pio_left_right_0_external_connection_export;
	input		pio_set_value_0_external_connection_export;
	input	[1:0]	pio_up_down_0_external_connection_export;
	input		reset_reset_n;
endmodule
