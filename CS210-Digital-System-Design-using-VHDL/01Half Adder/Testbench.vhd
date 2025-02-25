-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- Create a new Testbench Half_Adder_TB
ENTITY Half_Adder_TB IS
    -- no ports
END Half_Adder_TB;

ARCHITECTURE test OF Half_Adder_TB IS

    COMPONENT Half_Adder
        PORT (
            a_in : IN BIT;
            b_in : IN BIT;
            s_out : OUT BIT;
            c_out : OUT BIT
        );
    END COMPONENT;
    SIGNAL a_in, b_in, c_out, s_out : BIT := '0';

BEGIN
    A1 : Half_Adder PORT MAP(a_in => a_in, b_in => b_in, c_out => c_out, s_out => s_out);
    a_in <= NOT a_in AFTER 10 ns;
    b_in <= NOT b_in AFTER 5 ns;
END;