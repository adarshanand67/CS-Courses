-- TEST BENCH

-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY Testbench IS
    GENERIC (N : INTEGER := 4);
END Testbench;
-- Defining the architecture for above Testbench entity.
ARCHITECTURE arch_test OF Testbench IS

    -- Declaring the N_Add_Sub component.
    COMPONENT N_Add_Sub
        GENERIC (N : INTEGER := 4);
        PORT (
            a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            op_sel : IN STD_LOGIC;
            y : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            Cout : OUT STD_LOGIC;
            OV : OUT STD_LOGIC);
    END COMPONENT;
    -- Declaring the signals and initializing.
    SIGNAL A, B, Y : STD_LOGIC_VECTOR(N - 1 DOWNTO 0) := (N - 1 DOWNTO 0 => '0');
    SIGNAL C_OUT : STD_LOGIC;
    SIGNAL OP_SEL : STD_LOGIC := '0';
    SIGNAL OV : STD_LOGIC;
BEGIN
    -- Instantiating the N_Add_Sub
    ADD_SUB : N_Add_Sub PORT MAP(A, B, OP_SEL, Y, C_OUT, OV);

    -- Assigning values to input signals.
    A <= STD_LOGIC_VECTOR(signed(A) + 1) AFTER 6 ns;
    B <= STD_LOGIC_VECTOR(signed(B) + 1) AFTER 12 ns;

    OP_SEL <= NOT OP_SEL AFTER 50ns;

    -- NOTE:- Use atleast 100 ns Run Time for checking to cover max possibilites.

END arch_test;