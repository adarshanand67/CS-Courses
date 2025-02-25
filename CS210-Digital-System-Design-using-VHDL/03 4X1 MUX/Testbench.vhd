-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

-- The testbench for the  4x1 Multiplexor:
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
ENTITY Testbench IS
END Testbench;

-- The architecture of the 4x1 Multiplexor:
ARCHITECTURE behav OF Testbench IS

    COMPONENT Mux4X1
        PORT (
            a, b, c, d : IN STD_LOGIC;
            s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            y : OUT STD_LOGIC);
    END COMPONENT;
    -- The signal declarations:
    SIGNAL a, b, c, d, y : STD_LOGIC := '0';
    SIGNAL s : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";

BEGIN
    -- The process:
    Mu : Mux4X1 PORT MAP(a, b, c, d, s, y);

    -- The signal assignments :
    s(0) <= NOT s(0) AFTER 10 ns;
    s(1) <= NOT s(1) AFTER 9 ns;
    a <= NOT a AFTER 1ns;
    b <= NOT b AFTER 2ns;
    c <= NOT c AFTER 3ns;
    d <= NOT d AFTER 4ns;
END behav;