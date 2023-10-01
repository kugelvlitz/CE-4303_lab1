
module qsysTOP (
		input  wire  clk_clk,       //   clk.clk
		input  wire  reset_reset_n  // reset.reset_n
	);

	qsys cpu (.clk_clk(clk_clk),
				 .reset_reset_n(reset_reset_n));
endmodule
