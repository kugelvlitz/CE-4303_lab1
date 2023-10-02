module plattformtop (
		input  wire       clk,                                     //                                  clk.clk
		input  wire       continue0,   //   pio_continue_0_external_connection.export
		output wire [6:0] display1,   //   pio_display1_0_external_connection.export
		output wire [6:0] display2,   //   pio_display2_0_external_connection.export
		output wire [6:0] display3,   //   pio_display3_0_external_connection.export
		output wire [6:0] display4,   //   pio_display4_0_external_connection.export
		output wire [6:0] display5,   //   pio_display5_0_external_connection.export
		output wire [6:0] display6,   //   pio_display6_0_external_connection.export
		output wire [1:0] ready_rsa_filter,       //       pio_leds_0_external_connection.export
		input  wire [1:0] left_right, // pio_left_right_0_external_connection.export
		input  wire       switch,     //     pio_switch_0_external_connection.export
		input  wire [1:0] up_down,    //    pio_up_down_0_external_connection.export
		input  wire       reset                                //                                reset.reset_n
	);
	
		
	plattform cpu(
		.clk_clk(clk),                                     //                                  clk.clk
		.pio_continue_0_external_connection_export(continue0),   //   pio_continue_0_external_connection.export
		.pio_display1_0_external_connection_export(display1),   //   pio_display1_0_external_connection.export
		.pio_display2_0_external_connection_export(display2),   //   pio_display2_0_external_connection.export
		.pio_display3_0_external_connection_export(display3),   //   pio_display3_0_external_connection.export
		.pio_display4_0_external_connection_export(display4),   //   pio_display4_0_external_connection.export
		.pio_display5_0_external_connection_export(display5),   //   pio_display5_0_external_connection.export
		.pio_display6_0_external_connection_export(display6),   //   pio_display6_0_external_connection.export
		.pio_leds_0_external_connection_export(ready_rsa_filter),       //       pio_leds_0_external_connection.export
		.pio_left_right_0_external_connection_export(left_right), // pio_left_right_0_external_connection.export
		.pio_switch_0_external_connection_export(switch0),     //     pio_switch_0_external_connection.export
		.pio_up_down_0_external_connection_export(up_down),    //    pio_up_down_0_external_connection.export
		.reset_reset_n(reset)                                //                                reset.reset_n
		);
	
endmodule