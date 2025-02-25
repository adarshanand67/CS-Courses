-- Team: Digital Demons
-- Aniket 2003104
-- Adarsh 2003101

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_arith.ALL;

-- A Full_adder adds 3 bits (a,b,c_in) to produce a sum (s) and a carry (c_out).
ENTITY Full_adder IS
    PORT (
        a, b : IN STD_LOGIC;
        c_in : IN STD_LOGIC;
        s : OUT STD_LOGIC;
        c_out : OUT STD_LOGIC);
END Full_adder;
-- Defining the architecture for above Full_adder entity.
ARCHITECTURE arch_FA OF Full_adder IS
BEGIN
    -- Defining the sum(s)
    s <= (a XOR (b XOR c_in));
    -- Defining the carry(c_out)
    c_out <= ((c_in AND (a XOR b)) OR (a AND b));
END arch_FA;

------------------------------------------------------------
-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- An N-bit Ripple_adder uses N Full_adder instances connected 
-- together by signals to add two N bit input vectors a and b along with a carry in (c_in) and generates a N bit sum (s) and a carry out (c_out)

ENTITY N_Ripple_adder IS
    GENERIC (N : INTEGER := 4);
    PORT (
        a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
        c_in : IN STD_LOGIC;
        s : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
        c_out : OUT STD_LOGIC);
END N_Ripple_adder;
-- Defining the architecture for above N_Ripple_adder entity.
ARCHITECTURE arch_N_RA OF N_Ripple_adder IS

    -- Declaring the Full adder component.
    COMPONENT Full_adder
        PORT (
            a, b : IN STD_LOGIC;
            c_in : IN STD_LOGIC;
            s : OUT STD_LOGIC;
            c_out : OUT STD_LOGIC);
    END COMPONENT;
    -- the following signals will be useful for connecting together the full adders.
    SIGNAL carry : STD_LOGIC_VECTOR(N - 1 DOWNTO 0) := (N - 1 DOWNTO 0 => '0');

BEGIN

    each_bit : FOR i IN (N - 1) DOWNTO 0 GENERATE

        Initial_bit : IF i = 0 GENERATE
            FA_0 : Full_adder PORT MAP(a(i), b(i), c_in, s(i), carry(i));
        END GENERATE Initial_bit;

        Other_bits : IF i > 0 GENERATE
            FA_i : Full_adder PORT MAP(a(i), b(i), carry(i - 1), s(i), carry(i));
        END GENERATE Other_bits;

    END GENERATE each_bit;

    c_out <= carry(N - 1);

END arch_N_RA;