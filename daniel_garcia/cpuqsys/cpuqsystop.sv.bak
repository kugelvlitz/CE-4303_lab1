module cpuqsystop (
		input  logic       clk,                                   //                                clk.clk
		input  logic       continue0, // pio_continue_0_external_connection.export
		output logic [7:0] leds,     //     pio_leds_0_external_connection.export
		input  logic       reset                              //                              reset.reset_n
	);
	
	
	cpuqsys cpu(
		.clk_clk(clk),                                   //                                clk.clk
		.pio_continue_0_external_connection_export(continue0), // pio_continue_0_external_connection.export
		.pio_leds_0_external_connection_export(leds),     //     pio_leds_0_external_connection.export
		.reset_reset_n(reset)                              //                              reset.reset_n
	);
	
	
endmodule