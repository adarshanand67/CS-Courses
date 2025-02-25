LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY testbench IS
    -- no ports
END testbench;

ARCHITECTURE test OF testbench IS
    SIGNAL a_in, b_in, c_out : BIT := '0';

    COMPONENT And_Gate
        PORT (
            a, b : IN BIT;
            c : OUT BIT
        );
    END COMPONENT;
    -- create testbench architecture

BEGIN
    A1 : And_Gate PORT MAP(a_in, b_in, c_out);
    a_in <= NOT a_in AFTER 10 ns;
    b_in <= NOT b_in AFTER 10 ns;
END test;