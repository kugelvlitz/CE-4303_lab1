
module qsys (
	clk_clk,
	reset_reset_n,
	display1_external_connection_export,
	display2_external_connection_export,
	display3_external_connection_export,
	display4_external_connection_export,
	display6_external_connection_export,
	rsa_filter_ready_external_connection_export,
	continue_external_connection_in_port,
	continue_external_connection_out_port,
	left_right_external_connection_in_port,
	left_right_external_connection_out_port,
	up_down_external_connection_in_port,
	up_down_external_connection_out_port,
	manual_auto_external_connection_in_port,
	manual_auto_external_connection_out_port,
	display5_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[6:0]	display1_external_connection_export;
	output	[6:0]	display2_external_connection_export;
	output	[6:0]	display3_external_connection_export;
	output	[6:0]	display4_external_connection_export;
	output	[6:0]	display6_external_connection_export;
	output	[1:0]	rsa_filter_ready_external_connection_export;
	input		continue_external_connection_in_port;
	output		continue_external_connection_out_port;
	input	[1:0]	left_right_external_connection_in_port;
	output	[1:0]	left_right_external_connection_out_port;
	input	[1:0]	up_down_external_connection_in_port;
	output	[1:0]	up_down_external_connection_out_port;
	input		manual_auto_external_connection_in_port;
	output		manual_auto_external_connection_out_port;
	output	[6:0]	display5_external_connection_export;
endmodule
