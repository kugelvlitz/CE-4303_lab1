
module p1 (
	clk_clk,
	pio_disp1_external_connection_export,
	pio_disp2_external_connection_export,
	pio_disp3_external_connection_export,
	pio_disp4_external_connection_export,
	pio_disp5_external_connection_export,
	pio_disp6_external_connection_export,
	reset_reset_n,
	pio_buttons_external_connection_in_port,
	pio_buttons_external_connection_out_port,
	pio_mode_external_connection_in_port,
	pio_mode_external_connection_out_port,
	pio_rsaready_external_connection_export,
	pio_start_funct_external_connection_in_port,
	pio_start_funct_external_connection_out_port);	

	input		clk_clk;
	output	[6:0]	pio_disp1_external_connection_export;
	output	[6:0]	pio_disp2_external_connection_export;
	output	[6:0]	pio_disp3_external_connection_export;
	output	[6:0]	pio_disp4_external_connection_export;
	output	[6:0]	pio_disp5_external_connection_export;
	output	[6:0]	pio_disp6_external_connection_export;
	input		reset_reset_n;
	input	[3:0]	pio_buttons_external_connection_in_port;
	output	[3:0]	pio_buttons_external_connection_out_port;
	input		pio_mode_external_connection_in_port;
	output		pio_mode_external_connection_out_port;
	output	[1:0]	pio_rsaready_external_connection_export;
	input	[1:0]	pio_start_funct_external_connection_in_port;
	output	[1:0]	pio_start_funct_external_connection_out_port;
endmodule
