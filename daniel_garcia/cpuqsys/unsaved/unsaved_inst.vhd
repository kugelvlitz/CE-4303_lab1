	component unsaved is
		port (
			clk_clk                                   : in  std_logic                    := 'X'; -- clk
			reset_reset_n                             : in  std_logic                    := 'X'; -- reset_n
			pio_continue_0_external_connection_export : in  std_logic                    := 'X'; -- export
			pio_leds_0_external_connection_export     : out std_logic_vector(7 downto 0)         -- export
		);
	end component unsaved;

	u0 : component unsaved
		port map (
			clk_clk                                   => CONNECTED_TO_clk_clk,                                   --                                clk.clk
			reset_reset_n                             => CONNECTED_TO_reset_reset_n,                             --                              reset.reset_n
			pio_continue_0_external_connection_export => CONNECTED_TO_pio_continue_0_external_connection_export, -- pio_continue_0_external_connection.export
			pio_leds_0_external_connection_export     => CONNECTED_TO_pio_leds_0_external_connection_export      --     pio_leds_0_external_connection.export
		);

