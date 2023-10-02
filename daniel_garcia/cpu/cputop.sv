module cputop (
		input  logic       clk,                                     //                                  clk.clk
		input  logic       auto_manual, // pio_auto_manual_0_external_connection.export
		input  logic       continue0,   //   pio_continue_0_external_connection.export
		output logic [6:0] display1,   //   pio_display1_0_external_connection.export
		output logic [6:0] display2,   //   pio_display2_0_external_connection.export
		output logic [6:0] display3,   //   pio_display3_0_external_connection.export
		output logic [6:0] display4,   //   pio_display4_0_external_connection.export
		output logic [6:0] display5,   //   pio_display5_0_external_connection.export
		output logic [6:0] display6,   //   pio_display6_0_external_connection.export
		output logic [7:0] leds,
		output logic [1:0] ready_rsa_filter,       //       pio_leds_0_external_connection.export
		input  logic [1:0] left_right, // pio_left_right_0_external_connection.export
		input  logic       set_value,   //   pio_set_value_0_external_connection.export
		input  logic [1:0] up_down,    //    pio_up_down_0_external_connection.export
		input  logic       reset                                //                                reset.reset_n
	);
	
		
	cpu qcpu(
		.clk_clk(clk),                                     //                                  clk.clk
		.pio_auto_manual_0_external_connection_export(auto_manual),
		.pio_continue_0_external_connection_export(continue0),   //   pio_continue_0_external_connection.export
		.pio_display1_0_external_connection_export(display1),   //   pio_display1_0_external_connection.export
		.pio_display2_0_external_connection_export(display2),   //   pio_display2_0_external_connection.export
		.pio_display3_0_external_connection_export(display3),   //   pio_display3_0_external_connection.export
		.pio_display4_0_external_connection_export(display4),   //   pio_display4_0_external_connection.export
		.pio_display5_0_external_connection_export(display5),   //   pio_display5_0_external_connection.export
		.pio_display6_0_external_connection_export(display6),   //   pio_display6_0_external_connection.export
		.pio_leds_0_external_connection_export(leds),
		.pio_left_right_0_external_connection_export(left_right), // pio_left_right_0_external_connection.export
		.pio_ready_rsa_filter_0_external_connection_export(ready_rsa_filter),       //       pio_leds_0_external_connection.export
		.pio_set_value_0_external_connection_export(set_value),
		.pio_up_down_0_external_connection_export(up_down),    //    pio_up_down_0_external_connection.export
		.reset_reset_n(reset)                                //                                reset.reset_n
		);
	
endmodule