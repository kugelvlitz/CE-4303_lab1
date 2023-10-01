	component p1 is
		port (
			clk_clk                                      : in  std_logic                    := 'X';             -- clk
			pio_disp1_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_disp2_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_disp3_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_disp4_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_disp5_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			pio_disp6_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			reset_reset_n                                : in  std_logic                    := 'X';             -- reset_n
			pio_buttons_external_connection_in_port      : in  std_logic_vector(3 downto 0) := (others => 'X'); -- in_port
			pio_buttons_external_connection_out_port     : out std_logic_vector(3 downto 0);                    -- out_port
			pio_mode_external_connection_in_port         : in  std_logic                    := 'X';             -- in_port
			pio_mode_external_connection_out_port        : out std_logic;                                       -- out_port
			pio_rsaready_external_connection_export      : out std_logic_vector(1 downto 0);                    -- export
			pio_start_funct_external_connection_in_port  : in  std_logic_vector(1 downto 0) := (others => 'X'); -- in_port
			pio_start_funct_external_connection_out_port : out std_logic_vector(1 downto 0)                     -- out_port
		);
	end component p1;

	u0 : component p1
		port map (
			clk_clk                                      => CONNECTED_TO_clk_clk,                                      --                                 clk.clk
			pio_disp1_external_connection_export         => CONNECTED_TO_pio_disp1_external_connection_export,         --       pio_disp1_external_connection.export
			pio_disp2_external_connection_export         => CONNECTED_TO_pio_disp2_external_connection_export,         --       pio_disp2_external_connection.export
			pio_disp3_external_connection_export         => CONNECTED_TO_pio_disp3_external_connection_export,         --       pio_disp3_external_connection.export
			pio_disp4_external_connection_export         => CONNECTED_TO_pio_disp4_external_connection_export,         --       pio_disp4_external_connection.export
			pio_disp5_external_connection_export         => CONNECTED_TO_pio_disp5_external_connection_export,         --       pio_disp5_external_connection.export
			pio_disp6_external_connection_export         => CONNECTED_TO_pio_disp6_external_connection_export,         --       pio_disp6_external_connection.export
			reset_reset_n                                => CONNECTED_TO_reset_reset_n,                                --                               reset.reset_n
			pio_buttons_external_connection_in_port      => CONNECTED_TO_pio_buttons_external_connection_in_port,      --     pio_buttons_external_connection.in_port
			pio_buttons_external_connection_out_port     => CONNECTED_TO_pio_buttons_external_connection_out_port,     --                                    .out_port
			pio_mode_external_connection_in_port         => CONNECTED_TO_pio_mode_external_connection_in_port,         --        pio_mode_external_connection.in_port
			pio_mode_external_connection_out_port        => CONNECTED_TO_pio_mode_external_connection_out_port,        --                                    .out_port
			pio_rsaready_external_connection_export      => CONNECTED_TO_pio_rsaready_external_connection_export,      --    pio_rsaready_external_connection.export
			pio_start_funct_external_connection_in_port  => CONNECTED_TO_pio_start_funct_external_connection_in_port,  -- pio_start_funct_external_connection.in_port
			pio_start_funct_external_connection_out_port => CONNECTED_TO_pio_start_funct_external_connection_out_port  --                                    .out_port
		);
