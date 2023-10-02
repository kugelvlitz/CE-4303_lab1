	component cpu is
		port (
			clk_clk                                           : in  std_logic                    := 'X';             -- clk
			pio_auto_manual_0_external_connection_export      : in  std_logic                    := 'X';             -- export
			pio_continue_0_external_connection_export         : in  std_logic                    := 'X';             -- export
			pio_display1_0_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_display2_0_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_display3_0_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_display4_0_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_display5_0_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_display6_0_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_left_right_0_external_connection_export       : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
			pio_ready_rsa_filter_0_external_connection_export : out std_logic_vector(1 downto 0);                    -- export
			pio_set_value_0_external_connection_export        : in  std_logic                    := 'X';             -- export
			pio_up_down_0_external_connection_export          : in  std_logic_vector(1 downto 0) := (others => 'X'); -- export
			reset_reset_n                                     : in  std_logic                    := 'X';             -- reset_n
			pio_leds_0_external_connection_export             : out std_logic_vector(7 downto 0)                     -- export
		);
	end component cpu;

	u0 : component cpu
		port map (
			clk_clk                                           => CONNECTED_TO_clk_clk,                                           --                                        clk.clk
			pio_auto_manual_0_external_connection_export      => CONNECTED_TO_pio_auto_manual_0_external_connection_export,      --      pio_auto_manual_0_external_connection.export
			pio_continue_0_external_connection_export         => CONNECTED_TO_pio_continue_0_external_connection_export,         --         pio_continue_0_external_connection.export
			pio_display1_0_external_connection_export         => CONNECTED_TO_pio_display1_0_external_connection_export,         --         pio_display1_0_external_connection.export
			pio_display2_0_external_connection_export         => CONNECTED_TO_pio_display2_0_external_connection_export,         --         pio_display2_0_external_connection.export
			pio_display3_0_external_connection_export         => CONNECTED_TO_pio_display3_0_external_connection_export,         --         pio_display3_0_external_connection.export
			pio_display4_0_external_connection_export         => CONNECTED_TO_pio_display4_0_external_connection_export,         --         pio_display4_0_external_connection.export
			pio_display5_0_external_connection_export         => CONNECTED_TO_pio_display5_0_external_connection_export,         --         pio_display5_0_external_connection.export
			pio_display6_0_external_connection_export         => CONNECTED_TO_pio_display6_0_external_connection_export,         --         pio_display6_0_external_connection.export
			pio_left_right_0_external_connection_export       => CONNECTED_TO_pio_left_right_0_external_connection_export,       --       pio_left_right_0_external_connection.export
			pio_ready_rsa_filter_0_external_connection_export => CONNECTED_TO_pio_ready_rsa_filter_0_external_connection_export, -- pio_ready_rsa_filter_0_external_connection.export
			pio_set_value_0_external_connection_export        => CONNECTED_TO_pio_set_value_0_external_connection_export,        --        pio_set_value_0_external_connection.export
			pio_up_down_0_external_connection_export          => CONNECTED_TO_pio_up_down_0_external_connection_export,          --          pio_up_down_0_external_connection.export
			reset_reset_n                                     => CONNECTED_TO_reset_reset_n,                                     --                                      reset.reset_n
			pio_leds_0_external_connection_export             => CONNECTED_TO_pio_leds_0_external_connection_export              --             pio_leds_0_external_connection.export
		);

