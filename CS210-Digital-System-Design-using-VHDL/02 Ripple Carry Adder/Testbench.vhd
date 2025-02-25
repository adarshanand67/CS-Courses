-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY Testbench IS
END Testbench;

-- Architecture of the Testbench
ARCHITECTURE behav OF Testbench IS
    COMPONENT ripple_adder
        PORT (
            a, b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            c_in : IN STD_LOGIC
            s : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
            c_out : OUT STD_LOGIC;
        );
    END COMPONENT;
    SIGNAL a, b, s : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0000";
    SIGNAL c_in : STD_LOGIC := "0";
    SIGNAL c_out : STD_LOGIC := "0";
BEGIN
    -- Instantiate the component ripple_adder
    RA : ripple_adder PORT MAP(
        a => a, b => b, c_in => c_in, s => s, c_out => c_out);
    a <= STD_LOGIC_VECTOR(unsigned(A) + 1) AFTER 10 ns;
    b <= STD_LOGIC_VECTOR(unsigned(B) + 1) AFTER 160 ns;
    c_in <= NOT c_out AFTER 2560 ns;
END behav;