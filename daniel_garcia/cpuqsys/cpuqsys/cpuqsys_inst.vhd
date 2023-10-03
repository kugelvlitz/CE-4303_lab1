	component cpuqsys is
		port (
			clk_clk                                   : in    std_logic                     := 'X';             -- clk
			pio_continue_0_external_connection_export : in    std_logic                     := 'X';             -- export
			pio_leds_0_external_connection_export     : out   std_logic_vector(7 downto 0);                     -- export
			reset_reset_n                             : in    std_logic                     := 'X';             -- reset_n
			new_sdram_controller_0_wire_addr          : out   std_logic_vector(13 downto 0);                    -- addr
			new_sdram_controller_0_wire_ba            : out   std_logic_vector(1 downto 0);                     -- ba
			new_sdram_controller_0_wire_cas_n         : out   std_logic;                                        -- cas_n
			new_sdram_controller_0_wire_cke           : out   std_logic;                                        -- cke
			new_sdram_controller_0_wire_cs_n          : out   std_logic;                                        -- cs_n
			new_sdram_controller_0_wire_dq            : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			new_sdram_controller_0_wire_dqm           : out   std_logic_vector(3 downto 0);                     -- dqm
			new_sdram_controller_0_wire_ras_n         : out   std_logic;                                        -- ras_n
			new_sdram_controller_0_wire_we_n          : out   std_logic                                         -- we_n
		);
	end component cpuqsys;

	u0 : component cpuqsys
		port map (
			clk_clk                                   => CONNECTED_TO_clk_clk,                                   --                                clk.clk
			pio_continue_0_external_connection_export => CONNECTED_TO_pio_continue_0_external_connection_export, -- pio_continue_0_external_connection.export
			pio_leds_0_external_connection_export     => CONNECTED_TO_pio_leds_0_external_connection_export,     --     pio_leds_0_external_connection.export
			reset_reset_n                             => CONNECTED_TO_reset_reset_n,                             --                              reset.reset_n
			new_sdram_controller_0_wire_addr          => CONNECTED_TO_new_sdram_controller_0_wire_addr,          --        new_sdram_controller_0_wire.addr
			new_sdram_controller_0_wire_ba            => CONNECTED_TO_new_sdram_controller_0_wire_ba,            --                                   .ba
			new_sdram_controller_0_wire_cas_n         => CONNECTED_TO_new_sdram_controller_0_wire_cas_n,         --                                   .cas_n
			new_sdram_controller_0_wire_cke           => CONNECTED_TO_new_sdram_controller_0_wire_cke,           --                                   .cke
			new_sdram_controller_0_wire_cs_n          => CONNECTED_TO_new_sdram_controller_0_wire_cs_n,          --                                   .cs_n
			new_sdram_controller_0_wire_dq            => CONNECTED_TO_new_sdram_controller_0_wire_dq,            --                                   .dq
			new_sdram_controller_0_wire_dqm           => CONNECTED_TO_new_sdram_controller_0_wire_dqm,           --                                   .dqm
			new_sdram_controller_0_wire_ras_n         => CONNECTED_TO_new_sdram_controller_0_wire_ras_n,         --                                   .ras_n
			new_sdram_controller_0_wire_we_n          => CONNECTED_TO_new_sdram_controller_0_wire_we_n           --                                   .we_n
		);

