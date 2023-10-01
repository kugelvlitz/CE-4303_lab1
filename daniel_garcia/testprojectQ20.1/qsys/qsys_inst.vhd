	component qsys is
		port (
			clk_clk                                     : in  std_logic                    := 'X';             -- clk
			reset_reset_n                               : in  std_logic                    := 'X';             -- reset_n
			display1_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			display2_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			display3_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			display4_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			display6_external_connection_export         : out std_logic_vector(6 downto 0);                    -- export
			rsa_filter_ready_external_connection_export : out std_logic_vector(1 downto 0);                    -- export
			continue_external_connection_in_port        : in  std_logic                    := 'X';             -- in_port
			continue_external_connection_out_port       : out std_logic;                                       -- out_port
			left_right_external_connection_in_port      : in  std_logic_vector(1 downto 0) := (others => 'X'); -- in_port
			left_right_external_connection_out_port     : out std_logic_vector(1 downto 0);                    -- out_port
			up_down_external_connection_in_port         : in  std_logic_vector(1 downto 0) := (others => 'X'); -- in_port
			up_down_external_connection_out_port        : out std_logic_vector(1 downto 0);                    -- out_port
			manual_auto_external_connection_in_port     : in  std_logic                    := 'X';             -- in_port
			manual_auto_external_connection_out_port    : out std_logic;                                       -- out_port
			display5_external_connection_export         : out std_logic_vector(6 downto 0)                     -- export
		);
	end component qsys;

	u0 : component qsys
		port map (
			clk_clk                                     => CONNECTED_TO_clk_clk,                                     --                                  clk.clk
			reset_reset_n                               => CONNECTED_TO_reset_reset_n,                               --                                reset.reset_n
			display1_external_connection_export         => CONNECTED_TO_display1_external_connection_export,         --         display1_external_connection.export
			display2_external_connection_export         => CONNECTED_TO_display2_external_connection_export,         --         display2_external_connection.export
			display3_external_connection_export         => CONNECTED_TO_display3_external_connection_export,         --         display3_external_connection.export
			display4_external_connection_export         => CONNECTED_TO_display4_external_connection_export,         --         display4_external_connection.export
			display6_external_connection_export         => CONNECTED_TO_display6_external_connection_export,         --         display6_external_connection.export
			rsa_filter_ready_external_connection_export => CONNECTED_TO_rsa_filter_ready_external_connection_export, -- rsa_filter_ready_external_connection.export
			continue_external_connection_in_port        => CONNECTED_TO_continue_external_connection_in_port,        --         continue_external_connection.in_port
			continue_external_connection_out_port       => CONNECTED_TO_continue_external_connection_out_port,       --                                     .out_port
			left_right_external_connection_in_port      => CONNECTED_TO_left_right_external_connection_in_port,      --       left_right_external_connection.in_port
			left_right_external_connection_out_port     => CONNECTED_TO_left_right_external_connection_out_port,     --                                     .out_port
			up_down_external_connection_in_port         => CONNECTED_TO_up_down_external_connection_in_port,         --          up_down_external_connection.in_port
			up_down_external_connection_out_port        => CONNECTED_TO_up_down_external_connection_out_port,        --                                     .out_port
			manual_auto_external_connection_in_port     => CONNECTED_TO_manual_auto_external_connection_in_port,     --      manual_auto_external_connection.in_port
			manual_auto_external_connection_out_port    => CONNECTED_TO_manual_auto_external_connection_out_port,    --                                     .out_port
			display5_external_connection_export         => CONNECTED_TO_display5_external_connection_export          --         display5_external_connection.export
		);

