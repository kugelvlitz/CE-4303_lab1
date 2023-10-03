	component cpuqsys is
		port (
			clk_clk                                           : in    std_logic                     := 'X';             -- clk
			new_sdram_controller_0_wire_addr                  : out   std_logic_vector(13 downto 0);                    -- addr
			new_sdram_controller_0_wire_ba                    : out   std_logic_vector(1 downto 0);                     -- ba
			new_sdram_controller_0_wire_cas_n                 : out   std_logic;                                        -- cas_n
			new_sdram_controller_0_wire_cke                   : out   std_logic;                                        -- cke
			new_sdram_controller_0_wire_cs_n                  : out   std_logic;                                        -- cs_n
			new_sdram_controller_0_wire_dq                    : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			new_sdram_controller_0_wire_dqm                   : out   std_logic_vector(3 downto 0);                     -- dqm
			new_sdram_controller_0_wire_ras_n                 : out   std_logic;                                        -- ras_n
			new_sdram_controller_0_wire_we_n                  : out   std_logic;                                        -- we_n
			pio_continue_0_external_connection_export         : in    std_logic                     := 'X';             -- export
			pio_display1_0_external_connection_export         : out   std_logic_vector(6 downto 0);                     -- export
			pio_display2_0_external_connection_export         : out   std_logic_vector(6 downto 0);                     -- export
			pio_display3_0_external_connection_export         : out   std_logic_vector(6 downto 0);                     -- export
			pio_display4_0_external_connection_export         : out   std_logic_vector(6 downto 0);                     -- export
			pio_display5_0_external_connection_export         : out   std_logic_vector(6 downto 0);                     -- export
			pio_display6_0_external_connection_export         : out   std_logic_vector(6 downto 0);                     -- export
			pio_leds_0_external_connection_export             : out   std_logic_vector(7 downto 0);                     -- export
			pio_left_right_0_external_connection_export       : in    std_logic_vector(1 downto 0)  := (others => 'X'); -- export
			pio_up_down_0_external_connection_export          : in    std_logic_vector(1 downto 0)  := (others => 'X'); -- export
			reset_reset_n                                     : in    std_logic                     := 'X';             -- reset_n
			pio_set_value_0_external_connection_export        : in    std_logic                     := 'X';             -- export
			pio_auto_manual_0_external_connection_export      : in    std_logic                     := 'X';             -- export
			pio_ready_rsa_filter_0_external_connection_export : out   std_logic_vector(1 downto 0)                      -- export
		);
	end component cpuqsys;

	u0 : component cpuqsys
		port map (
			clk_clk                                           => CONNECTED_TO_clk_clk,                                           --                                        clk.clk
			new_sdram_controller_0_wire_addr                  => CONNECTED_TO_new_sdram_controller_0_wire_addr,                  --                new_sdram_controller_0_wire.addr
			new_sdram_controller_0_wire_ba                    => CONNECTED_TO_new_sdram_controller_0_wire_ba,                    --                                           .ba
			new_sdram_controller_0_wire_cas_n                 => CONNECTED_TO_new_sdram_controller_0_wire_cas_n,                 --                                           .cas_n
			new_sdram_controller_0_wire_cke                   => CONNECTED_TO_new_sdram_controller_0_wire_cke,                   --                                           .cke
			new_sdram_controller_0_wire_cs_n                  => CONNECTED_TO_new_sdram_controller_0_wire_cs_n,                  --                                           .cs_n
			new_sdram_controller_0_wire_dq                    => CONNECTED_TO_new_sdram_controller_0_wire_dq,                    --                                           .dq
			new_sdram_controller_0_wire_dqm                   => CONNECTED_TO_new_sdram_controller_0_wire_dqm,                   --                                           .dqm
			new_sdram_controller_0_wire_ras_n                 => CONNECTED_TO_new_sdram_controller_0_wire_ras_n,                 --                                           .ras_n
			new_sdram_controller_0_wire_we_n                  => CONNECTED_TO_new_sdram_controller_0_wire_we_n,                  --                                           .we_n
			pio_continue_0_external_connection_export         => CONNECTED_TO_pio_continue_0_external_connection_export,         --         pio_continue_0_external_connection.export
			pio_display1_0_external_connection_export         => CONNECTED_TO_pio_display1_0_external_connection_export,         --         pio_display1_0_external_connection.export
			pio_display2_0_external_connection_export         => CONNECTED_TO_pio_display2_0_external_connection_export,         --         pio_display2_0_external_connection.export
			pio_display3_0_external_connection_export         => CONNECTED_TO_pio_display3_0_external_connection_export,         --         pio_display3_0_external_connection.export
			pio_display4_0_external_connection_export         => CONNECTED_TO_pio_display4_0_external_connection_export,         --         pio_display4_0_external_connection.export
			pio_display5_0_external_connection_export         => CONNECTED_TO_pio_display5_0_external_connection_export,         --         pio_display5_0_external_connection.export
			pio_display6_0_external_connection_export         => CONNECTED_TO_pio_display6_0_external_connection_export,         --         pio_display6_0_external_connection.export
			pio_leds_0_external_connection_export             => CONNECTED_TO_pio_leds_0_external_connection_export,             --             pio_leds_0_external_connection.export
			pio_left_right_0_external_connection_export       => CONNECTED_TO_pio_left_right_0_external_connection_export,       --       pio_left_right_0_external_connection.export
			pio_up_down_0_external_connection_export          => CONNECTED_TO_pio_up_down_0_external_connection_export,          --          pio_up_down_0_external_connection.export
			reset_reset_n                                     => CONNECTED_TO_reset_reset_n,                                     --                                      reset.reset_n
			pio_set_value_0_external_connection_export        => CONNECTED_TO_pio_set_value_0_external_connection_export,        --        pio_set_value_0_external_connection.export
			pio_auto_manual_0_external_connection_export      => CONNECTED_TO_pio_auto_manual_0_external_connection_export,      --      pio_auto_manual_0_external_connection.export
			pio_ready_rsa_filter_0_external_connection_export => CONNECTED_TO_pio_ready_rsa_filter_0_external_connection_export  -- pio_ready_rsa_filter_0_external_connection.export
		);

