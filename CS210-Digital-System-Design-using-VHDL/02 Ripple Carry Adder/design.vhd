-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- A Full adder adds three bits (a,b,c) and returns the sum (s) and carry (c).
ENTITY full_adder IS
    PORT (
        a : IN STD_LOGIC;
        b : IN STD_LOGIC;
        c : IN STD_LOGIC;
        s : OUT STD_LOGIC;
        c_out : OUT STD_LOGIC
    );
END ENTITY;
 
ARCHITECTURE behav OF full_adder IS
BEGIN
    s <= a XOR b XOR c;
    c_out <= (a AND b) OR (a AND c) OR (b AND c);

END behav;

-- A ripple adder uses 4 full adders instances connected by
--  signals to add four bit input vectors a and b and returns the sum (s) and carry (c).

ENTITY ripple_adder IS
    PORT (
        a : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        b : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        c_in : IN STD_LOGIC;
        s : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
        c : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END ripple_adder;

ARCHITECTURE struct OF ripple_adder IS
    -- Declaring Full adder component here
    COMPONENT full_adder
        PORT (
            a : IN STD_LOGIC;
            b : IN STD_LOGIC;
            c : IN STD_LOGIC;
            s : OUT STD_LOGIC;
            c_out : OUT STD_LOGIC
        );
    END COMPONENT; -- End of full_adder component
    SIGNAL carry : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0000"

BEGIN
    -- Declaring Full adder instances here
    F1 : Full_adder PORT MAP(a(0), b(0), c_in, s(0), c(0));
    F2 : Full_adder PORT MAP(a(1), b(1), c(0), s(1), c(1));
    F3 : Full_adder PORT MAP(a(2), b(2), c(1), s(2), c(2));
    F4 : Full_adder PORT MAP(a(3), b(3), c(2), s(3), c_out);
    -- The ripple adder is a 4-bit adder with carry.
END struct;