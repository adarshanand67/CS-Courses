LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY testbench IS
END testbench;

ARCHITECTURE test OF testbench IS
    COMPONENT det0 IS
        PORT (
        X : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        R : IN STD_LOGIC;
        Y : OUT STD_LOGIC_VECTOR (2 DOWNTO 0)

    );
    END COMPONENT;
    SIGNAL X0, X, R : STD_LOGIC := '0';
    SIGNAL Y : STD_LOGIC_VECTOR (2 DOWNTO 0) := "000";
    SIGNAL CLK : STD_LOGIC := '1';

BEGIN

    Counter : det0 PORT MAP(X, CLK, R, Y);
    R <= '1', '0' AFTER 8 ns;
    CLK <= NOT CLK AFTER 5ns;
    X0 <= '1',
        '0' AFTER 10ns,
        '0' AFTER 20ns,
        '1' AFTER 30ns,
        '1' AFTER 40ns,
        '0' AFTER 50ns,
        '1' AFTER 60ns,
        '0' AFTER 70ns,
        '1' AFTER 80ns,
        '1' AFTER 90ns,
        '1' AFTER 100ns,
        '0' AFTER 110ns,
        '0' AFTER 120ns,
        '0' AFTER 130ns,
        '0' AFTER 140ns,
        '1' AFTER 150ns,
        '1' AFTER 160ns,
        '0' AFTER 170ns,
        '1' AFTER 180ns,
        '1' AFTER 190ns,
        '1' AFTER 200ns,
        '0' AFTER 210ns,
        '0' AFTER 220ns,
        '1' AFTER 230ns,
        '0' AFTER 240ns,
        '1' AFTER 250ns,
        '1' AFTER 260ns,
        '0' AFTER 270ns,
        '1' AFTER 280ns,
        '0' AFTER 290ns;
    X <= X0 AFTER 1ns;

END ARCHITECTURE;