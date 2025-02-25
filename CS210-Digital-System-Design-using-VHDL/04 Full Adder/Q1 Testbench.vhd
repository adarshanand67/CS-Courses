-- TEST BENCH

-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
-- The testbench for the Ripple_adder:
ENTITY Testbench IS
    GENERIC (N : INTEGER := 4);
END Testbench;
-- Defining the architecture for above Testbench entity.
ARCHITECTURE arch_test OF Testbench IS

    -- Declaring the Ripple adder component.
    COMPONENT N_Ripple_adder
        GENERIC (N : INTEGER := 4);
        PORT (
            a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            c_in : IN STD_LOGIC;
            s : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            c_out : OUT STD_LOGIC);
    END COMPONENT;
    -- Declaring the signals and initializing.
    SIGNAL a, b, s : STD_LOGIC_VECTOR(N - 1 DOWNTO 0) := (N - 1 DOWNTO 0 => '0');
    SIGNAL c_in, c_out : STD_LOGIC := '0';

BEGIN

    -- Instantiating the Ripple_adder
    RA : N_Ripple_adder PORT MAP(a, b, c_in, s, c_out);

    -- Assigning values to input signals.
    a <= STD_LOGIC_VECTOR(unsigned(a) + 1) AFTER 7 ns;
    b <= STD_LOGIC_VECTOR(unsigned(b) + 1) AFTER 14 ns;

    -- NOTE:- Use atleast 100 ns Run Time for checking to cover max possibilites.

END arch_test;