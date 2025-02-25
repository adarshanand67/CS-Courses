LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- D Flip Flop

ENTITY D_Flip_Flop IS
    PORT (
        clk : IN STD_LOGIC; -- Clock
        d : IN STD_LOGIC; -- data
        q : OUT STD_LOGIC; -- output
        rst : IN STD_LOGIC -- reset
        q_bar : OUT STD_LOGIC --  complementary output
    );
END D_Flip_Flop;

-- Behavior for D Flip Flop
ARCHITECTURE D_Flip_Flop_Behavior OF D_Flip_Flop IS
BEGIN
    proc1 : PROCESS (clk, rst) IS
    BEGIN
        IF rst = '1' THEN
            q <= '0';
            q_bar <= '0';
        ELSE
            IF (rising_edge(clk)) THEN
                q <= d;
                q_bar <= NOT d;
            END IF;
        END IF;
    END PROCESS;
END D_Flip_Flop_Behavior;

-- T Flip Flop
entity T_Flip_Flop is
    PORT (
        clk : IN STD_LOGIC; -- Clock
        t : IN STD_LOGIC; -- data
        q : OUT STD_LOGIC; -- output
        rst : IN STD_LOGIC -- reset
        q_bar : OUT STD_LOGIC --  complementary output
    );
END T_Flip_Flop;

architecture T_Flip_Flop_Behavior of T_Flip_Flop is
begin
    proc2 : PROCESS (clk, rst) IS -- process
    BEGIN
        IF rst = '1' THEN -- reset condition 
            q <= '0';
            q_bar <= '0';
        ELSE
            IF (rising_edge(clk)) THEN -- rising edge condition
                q <= t;
                q_bar <= NOT t;
            END IF;
        END IF;
    END PROCESS;
end T_Flip_Flop_Behavior;

