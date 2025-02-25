-- Team: Digital Demons
-- Aniket 2003104
-- Adarsh 2003101

-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
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

------------------------------------------------------------

-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
-- Creating an entity for N-bit 2x1 MUX

ENTITY N_Mux_2X1 IS
    GENERIC (N : INTEGER := 4);
    PORT (
        a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
        s : IN STD_LOGIC;
        y : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0));
END N_Mux_2X1;

ARCHITECTURE arch_N_Mux OF N_Mux_2X1 IS
BEGIN
    y <= a WHEN (s = '0') ELSE
        b WHEN (s = '1');
END arch_N_Mux;

------------------------------------------------------------
-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
-- Creating an entity for 1-bit 2x1 MUX

ENTITY Mux_2X1 IS
    PORT (
        a, b : IN STD_LOGIC;
        s : IN STD_LOGIC;
        y : OUT STD_LOGIC);
END Mux_2X1;

ARCHITECTURE arch_1_Mux OF Mux_2X1 IS
BEGIN
    y <= a WHEN (s = '0') ELSE
        b WHEN (s = '1');
END arch_1_Mux;

------------------------------------------------------------
-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
-- Creating an entity for NOT_GATE

ENTITY NOT_GATE IS
    PORT (
        a : IN STD_LOGIC;
        a_inv : OUT STD_LOGIC);
END NOT_GATE;

ARCHITECTURE arch_Not OF NOT_GATE IS

BEGIN
    a_inv <= NOT a;
END arch_Not;

------------------------------------------------------------
-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
-- Creating an entity for Bitwise_Invertor

ENTITY Bitwise_Invert IS
    GENERIC (N : INTEGER := 4);
    PORT (
        a : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
        a_inv : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0));
END Bitwise_Invert;

ARCHITECTURE arch_Bit_Inv OF Bitwise_Invert IS

    COMPONENT NOT_GATE IS
        PORT (
            a : IN STD_LOGIC;
            a_inv : OUT STD_LOGIC);
    END COMPONENT;

BEGIN
    not_array : FOR i IN (N - 1) DOWNTO 0 GENERATE
        not_i : NOT_GATE PORT MAP(a(i), a_inv(i));
    END GENERATE not_array;

END arch_Bit_Inv;

------------------------------------------------------------
-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
-- Creating an entity for Checking Over Flow 

ENTITY Over_Flow_Checker IS
    PORT (
        a, b, y, op_sel : IN STD_LOGIC;
        ov : OUT STD_LOGIC);
END Over_Flow_Checker;

ARCHITECTURE arch_Over_Flow OF Over_Flow_Checker IS
BEGIN

    -- Upon Solving for Boolean Function of Over_Flow existence, We get below expression.

    ov <= ((a AND b AND NOT(y) AND NOT(op_sel)) OR (NOT(a) AND b AND y AND op_sel) OR
        (a AND NOT(b) AND NOT(y) AND op_sel) OR (NOT(a) AND NOT(b) AND y AND NOT(op_sel)));

END arch_Over_Flow;

------------------------------------------------------------

-- Importing the required Library and Packages.
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
-- Creating Adder-Subtractor Module

ENTITY N_Add_Sub IS
    GENERIC (N : INTEGER := 4);
    PORT (
        a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
        op_sel : IN STD_LOGIC;
        y : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
        Cout : OUT STD_LOGIC;
        OV : OUT STD_LOGIC);

END N_Add_Sub;
ARCHITECTURE arch_add_sub OF N_Add_Sub IS

    -- Declaring the Component of N-bit Ripple Carry Adder.
    COMPONENT N_Ripple_adder
        GENERIC (N : INTEGER := 4);
        PORT (
            a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            c_in : IN STD_LOGIC;
            s : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            c_out : OUT STD_LOGIC);
    END COMPONENT;

    -- Declaring the Component of N-bit 2X1 Mux.
    COMPONENT N_Mux_2X1
        GENERIC (N : INTEGER := 4);
        PORT (
            a, b : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            s : IN STD_LOGIC;
            y : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0));
    END COMPONENT;

    -- Declaring the Component of 1-bit 2X1 Mux.
    COMPONENT Mux_2X1
        PORT (
            a, b : IN STD_LOGIC;
            s : IN STD_LOGIC;
            y : OUT STD_LOGIC);
    END COMPONENT;

    -- Declaring the Component of Bitwise_Invertor.
    COMPONENT Bitwise_Invert IS
        GENERIC (N : INTEGER := 4);
        PORT (
            a : IN STD_LOGIC_VECTOR(N - 1 DOWNTO 0);
            a_inv : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0));
    END COMPONENT;

    -- Declaring the Component of Over_Flow_Checker.
    COMPONENT Over_Flow_Checker IS
        PORT (
            a, b, y, op_sel : IN STD_LOGIC;
            ov : OUT STD_LOGIC);
    END COMPONENT;
    -- Declaring the Signals

    SIGNAL BitInv_b, Y_N_Mux : STD_LOGIC_VECTOR(N - 1 DOWNTO 0);

    SIGNAL Y_1_Mux : STD_LOGIC := '0';

    SIGNAL one : STD_LOGIC := '1';

    SIGNAL zero : STD_LOGIC := '0';

BEGIN

    Bit_Inv : Bitwise_Invert PORT MAP(b, BitInv_b);

    N_Mux : N_Mux_2X1 PORT MAP(b, BitInv_b, op_sel, Y_N_Mux);

    One_Mux : Mux_2X1 PORT MAP(zero, one, op_sel, Y_1_Mux);

    Add_Sub : N_Ripple_adder PORT MAP(a, Y_N_MUX, Y_1_MUX, y, Cout);

    Overflow : Over_Flow_Checker PORT MAP(a(N - 1), b(N - 1), y(N - 1), op_sel, OV);
END arch_add_sub;