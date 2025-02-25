LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY testbench IS
END testbench;

ARCHITECTURE test OF testbench IS
    COMPONENT SeqGen IS
        PORT (
            A, B, C, E : IN STD_LOGIC;
            CLK, R : IN STD_LOGIC;
            Y : OUT STD_LOGIC

        );
    END COMPONENT;
    SIGNAL A : STD_LOGIC := '1';
    SIGNAL B : STD_LOGIC := '1';
    SIGNAL C : STD_LOGIC := '0';
    SIGNAL E : STD_LOGIC := '1';
    SIGNAL Y : STD_LOGIC;
    SIGNAL CLK, R : STD_LOGIC := '1';

BEGIN

    SD : SeqGen PORT MAP(A, B, C, E, CLK, R, Y);
    R <= '1', '0' AFTER 8 ns;
    CLK <= NOT CLK AFTER 5ns;
END ARCHITECTURE;