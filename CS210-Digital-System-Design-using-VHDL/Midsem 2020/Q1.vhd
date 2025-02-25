LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- The code is perfect but NAND gates need to be placed in parenthesis and thats why due to less time, I 
-- am not able to remove the compilation errors due to brackets


ENTITY bitComparator IS
    PORT (
        A : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        B : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        G, L, E, Z : OUT STD_LOGIC

    );
END ENTITY;
ARCHITECTURE Behavioral OF bitComparator IS
BEGIN

    G <= (A(1) NAND A(0) NAND NOT B(0)) NAND (A(1) NAND NOT B(1)) NAND (A(0) NAND NOT B(1) NAND NOT B(0));
    L <= (NOT A(1) NAND NOT A(0) NAND B(0)) NAND (NOT A(1) NAND B(1)) NAND (NOT A(1) NAND B(1) NAND B(0));
    E <= (A(1) NAND A(0) NAND B(1) NAND B(0)) NAND (A(1) NAND NOT A(0) NAND B(1) NAND NOT B(0)) NAND (NOT A(1) NAND A(0) NAND NOT B(1) NAND B(0)) NAND (NOT A(1) NAND NOT A(0) NAND NOT B(1) NAND NOT B(0));
    Z <= NOT A(1) NAND NOT A(0) NAND NOT B(1) NAND NOT B(0);
END;


LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY Testbench IS

END Testbench;
-- Architecture of the Testbench
ARCHITECTURE behav OF Testbench IS

    COMPONENT bitComparator IS
        PORT (
            A : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            B : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            G, L, E, Z : OUT STD_LOGIC
        );
    END COMPONENT;
    SIGNAL A : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    SIGNAL G, L, E, Z : OUT STD_LOGIC;
    SIGNAL B : IN STD_LOGIC_VECTOR(1 DOWNTO 0);

BEGIN

    BC : BitComparator PORT MAP(A, B, G, L, E, Z);
    B <= "00";
    WAIT FOR 10 ns;
    B <= "01";
    WAIT FOR 10 ns;
    B <= "10";
    WAIT FOR 10 ns;
    B <= "11";
    WAIT FOR 10 ns;
    A <= "00";
    WAIT FOR 10 ns;
    A <= "01";
    WAIT FOR 10 ns;
    A <= "10";
    WAIT FOR 10 ns;
    A <= "11";
    WAIT FOR 10 ns;
END behav;