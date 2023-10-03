module cpuqsystop (
		input  logic       clk,                                   //                                clk.clk
		output logic [13:0] new_sdram_controller_0_wire_addr,          //        new_sdram_controller_0_wire.addr
		output logic [1:0]  new_sdram_controller_0_wire_ba,            //                                   .ba
		output logic        new_sdram_controller_0_wire_cas_n,         //                                   .cas_n
		output logic        new_sdram_controller_0_wire_cke,           //                                   .cke
		output logic        new_sdram_controller_0_wire_cs_n,          //                                   .cs_n
		inout  logic [31:0] new_sdram_controller_0_wire_dq,            //                                   .dq
		output logic [3:0]  new_sdram_controller_0_wire_dqm,           //                                   .dqm
		output logic        new_sdram_controller_0_wire_ras_n,         //                                   .ras_n
		output logic        new_sdram_controller_0_wire_we_n,          //                                   .we_n
		input  logic        auto_manual,      //      pio_auto_manual_0_external_connection.export
		input  logic       continue0, // pio_continue_0_external_connection.export
		output logic [1:0]  current_key,      //      pio_current_key_0_external_connection.export
		output wire [6:0]  display1, // pio_display1_0_external_connection.export
		output wire [6:0]  display2, // pio_display2_0_external_connection.export
		output wire [6:0]  display3, // pio_display3_0_external_connection.export
		output wire [6:0]  display4, // pio_display4_0_external_connection.export
		output wire [6:0]  display5, // pio_display5_0_external_connection.export
		output wire [6:0]  display6, // pio_display6_0_external_connection.export
		output logic [5:0] leds,     //     pio_leds_0_external_connection.export
		input  logic [1:0]  left_right, // pio_left_right_0_external_connection.export
		output logic [1:0]  ready_rsa_filter, // pio_ready_rsa_filter_0_external_connection.export
		input  logic [1:0]  reveal_decimal,   //   pio_reveal_decimal_0_external_connection.export
		input  logic        set_value,        //        pio_set_value_0_external_connection.export
		input  logic [1:0]  up_down,    //    pio_up_down_0_external_connection.export
		input  logic       reset                              //                              reset.reset_n
	);
	
	
	cpuqsys cpu(
		.clk_clk(clk),                                   //                                clk.clk
		.new_sdram_controller_0_wire_addr(new_sdram_controller_0_wire_addr),          //        new_sdram_controller_0_wire.addr
		.new_sdram_controller_0_wire_ba(new_sdram_controller_0_wire_ba),            //                                   .ba
		.new_sdram_controller_0_wire_cas_n(new_sdram_controller_0_wire_cas_n),         //                                   .cas_n
		.new_sdram_controller_0_wire_cke(new_sdram_controller_0_wire_cke),           //                                   .cke
		.new_sdram_controller_0_wire_cs_n(new_sdram_controller_0_wire_cs_n),          //                                   .cs_n
		.new_sdram_controller_0_wire_dq(new_sdram_controller_0_wire_dq),            //                                   .dq
		.new_sdram_controller_0_wire_dqm(new_sdram_controller_0_wire_dqm),           //                                   .dqm
		.new_sdram_controller_0_wire_ras_n(new_sdram_controller_0_wire_ras_n),         //                                   .ras_n
		.new_sdram_controller_0_wire_we_n(new_sdram_controller_0_wire_we_n),          //                                   .we_n
		.pio_auto_manual_0_external_connection_export(auto_manual),      //      pio_auto_manual_0_external_connection.export
		.pio_continue_0_external_connection_export(continue0), // pio_continue_0_external_connection.export
		.pio_current_key_0_external_connection_export(current_key),      //      pio_current_key_0_external_connection.export
		.pio_display1_0_external_connection_export(display1), // pio_display1_0_external_connection.export
		.pio_display2_0_external_connection_export(display2), // pio_display2_0_external_connection.export
		.pio_display3_0_external_connection_export(display3), // pio_display3_0_external_connection.export
		.pio_display4_0_external_connection_export(display4), // pio_display4_0_external_connection.export
		.pio_display5_0_external_connection_export(display5), // pio_display5_0_external_connection.export
		.pio_display6_0_external_connection_export(display6), // pio_display6_0_external_connection.export
		.pio_leds_0_external_connection_export(leds),     //     pio_leds_0_external_connection.export
		.pio_left_right_0_external_connection_export(left_right), // pio_left_right_0_external_connection.export
		.pio_ready_rsa_filter_0_external_connection_export(ready_rsa_filter), // pio_ready_rsa_filter_0_external_connection.export
		.pio_reveal_decimal_0_external_connection_export(reveal_decimal),   //   pio_reveal_decimal_0_external_connection.export
		.pio_set_value_0_external_connection_export(set_value),        //        pio_set_value_0_external_connection.export
		.pio_up_down_0_external_connection_export(up_down),    //    pio_up_down_0_external_connection.export
		.reset_reset_n(reset)                              //                              reset.reset_n
	);
	
	
endmodule