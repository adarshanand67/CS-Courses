-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

-- The testbench for the  4x1 Multiplexor:
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY Testbench IS
END Testbench;

ARCHITECTURE Test OF Testbench IS

    -- Declaring Component Instances
    COMPONENT Mux4X1_Conditional
        PORT (
            a, b, c, d : STD_LOGIC_VECTOR(7 DOWNTO 0); -- 8 bits
            s : IN STD_LOGIC_VECTOR(1 DOWNTO 0); -- 2 bits
            y : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
    END COMPONENT;
    -- End of Component Instances

    -- Declaring Component Instances
    COMPONENT Mux4X1_Selected
        PORT (
            a, b, c, d : STD_LOGIC_VECTOR(7 DOWNTO 0);
            s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            y : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
    END COMPONENT;
    -- End of Component Instances

    -- Declaring signals
    SIGNAL a, b, c, d, y : STD_LOGIC_VECTOR(7 DOWNTO 0) := "00000000";
    SIGNAL s : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
BEGIN
    -- Instantiating the components
    MUX_Conditional : Mux4X1_Conditional PORT MAP(a, b, c, d, s, y);
    MUX_Selected : Mux4X1_Selected PORT MAP(a, b, c, d, s, y);

    -- Altering the values at the input signals.
    a <= STD_LOGIC_VECTOR(unsigned(a) + 1) AFTER 2 ns;
    b <= STD_LOGIC_VECTOR(unsigned(b) + 1) AFTER 3 ns;
    c <= STD_LOGIC_VECTOR(unsigned(c) + 1) AFTER 4 ns;
    d <= STD_LOGIC_VECTOR(unsigned(d) + 1) AFTER 5 ns;
    s <= STD_LOGIC_VECTOR(unsigned(s) + 1) AFTER 6 ns;

END Test;