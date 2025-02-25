-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY Testbench IS
END Testbench;

ARCHITECTURE test OF Testbench IS

    COMPONENT decoder_3x8_struc
        PORT (
            X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
            E : IN STD_LOGIC;
            D0, D1, D2, D3, D4, D5, D6, D7 : OUT STD_LOGIC);
    END COMPONENT;

    COMPONENT decoder_3x8_dataflow
        PORT (
            X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
            E : IN STD_LOGIC;
            D0, D1, D2, D3, D4, D5, D6, D7 : OUT STD_LOGIC);
    END COMPONENT;

    SIGNAL E : STD_LOGIC := '1';
    SIGNAL X : STD_LOGIC_VECTOR(2 DOWNTO 0) := "000";
    SIGNAL D0, D1, D2, D3, D4, D5, D6, D7 : STD_LOGIC;

BEGIN
    Structural : decoder_3x8_struc PORT MAP(X, E, D0, D1, D2, D3, D4, D5, D6, D7);
    DataFlow : decoder_3x8_dataflow PORT MAP(X, E, D0, D1, D2, D3, D4, D5, D6, D7);

    X(0) <= NOT X(0) AFTER 2ns;
    X(1) <= NOT X(1) AFTER 4ns;
    X(2) <= NOT X(2) AFTER 6ns;
    E <= NOT E AFTER 30ns;

END test;