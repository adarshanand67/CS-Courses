-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY Testbench IS
END Testbench;

ARCHITECTURE test OF Testbench IS

    COMPONENT Combinational_ckt
        PORT (
            X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
            F0, F1, F2, F3 : OUT STD_LOGIC
        );
    END COMPONENT;
    SIGNAL X : STD_LOGIC_VECTOR(2 DOWNTO 0) := "000";
    SIGNAL F0, F1, F2, F3 : STD_LOGIC;

BEGIN
    Cominational : Combinational_ckt PORT MAP(X, F0, F1, F2, F3);

    X(0) <= NOT X(0) AFTER 2ns;
    X(1) <= NOT X(1) AFTER 4ns;
    X(2) <= NOT X(2) AFTER 6ns;
END test;