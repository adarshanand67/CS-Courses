-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- Creating MUX4X1 using conditional statements(if else)
ENTITY Mux4X1_Conditional IS

    PORT (
        -- Inputs
        a : STD_LOGIC_VECTOR(7 DOWNTO 0);
        b : STD_LOGIC_VECTOR(7 DOWNTO 0);
        c : STD_LOGIC_VECTOR(7 DOWNTO 0);
        d : STD_LOGIC_VECTOR(7 DOWNTO 0);
        s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);

        -- Outputs
        y : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END Mux4X1_Conditional;

ARCHITECTURE Conditional OF Mux4X1_Conditional IS
BEGIN
    y <= a WHEN (s = "00") ELSE
        b WHEN (s = "01") ELSE
        c WHEN (s = "10") ELSE
        d;
END Conditional;
-- End of MUX4X1 using conditional statements

-- Creating MUX4X1 using selected statements(switch case)
ENTITY Mux4X1_Selected IS
    PORT (
        -- Inputs
        a : STD_LOGIC_VECTOR(7 DOWNTO 0);
        b : STD_LOGIC_VECTOR(7 DOWNTO 0);
        c : STD_LOGIC_VECTOR(7 DOWNTO 0);
        d : STD_LOGIC_VECTOR(7 DOWNTO 0);
        s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);

        -- Outputs
        y : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END Mux4X1_Selected;

ARCHITECTURE Selected OF Mux4X1_Selected IS
BEGIN
    WITH s SELECT
        y <= a WHEN "00",
        b WHEN "01",
        c WHEN "10",
        d WHEN "11",
        "00000000" WHEN OTHERS;
END Selected;
-- End of MUX4X1 using selected statements