-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY Testbench IS
END Testbench;

ARCHITECTURE test OF Testbench IS
    COMPONENT Tflipflop IS
        PORT (
            T : IN STD_LOGIC;
            CLK : IN STD_LOGIC;
            R : IN STD_LOGIC;
            Q : OUT STD_LOGIC
        );
    END COMPONENT;

    SIGNAL T0, T1, T2, T : STD_LOGIC := '0';
    SIGNAL CLK : STD_LOGIC := '0';
    SIGNAL Q : STD_LOGIC := '0';
    SIGNAL R : STD_LOGIC := '1';

BEGIN
    TFF : Tflipflop PORT MAP(T, CLK, R, Q);

    CLK <= NOT CLK AFTER 10ns;
    T0 <= NOT T0 AFTER 5ns;
    T1 <= NOT T1 AFTER 20ns;
    T2 <= T0 XOR T1;
    T <= T2 AFTER 3ns;
    R <= NOT R AFTER 16ns;

END test;