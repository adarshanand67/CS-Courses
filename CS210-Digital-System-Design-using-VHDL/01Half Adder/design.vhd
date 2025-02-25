-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- Creating And gate 
ENTITY And_Gate IS
    PORT (
        a_in, b_in : IN BIT;
        c_out : OUT BIT
    );
END And_Gate;

ARCHITECTURE gate1 OF And_Gate IS
BEGIN
    c_out <= a_in AND b_in;
END gate1;
-- End of And_Gate

-- Creating Xor gate 
ENTITY Xor_Gate IS
    PORT (
        a_in, b_in : IN BIT;
        s_out : OUT BIT
    );
END Xor_Gate;

ARCHITECTURE gate2 OF Xor_Gate IS
BEGIN
    s_out <= a_in XOR b_in;
END gate2;
-- End of Xor_Gate

-- Creating Half_Adder
ENTITY Half_Adder IS
    PORT (
        a_in : IN BIT;
        b_in : IN BIT;
        s_out : OUT BIT;
        c_out : OUT BIT
    );
END Half_Adder;

ARCHITECTURE structure OF Half_Adder IS

    COMPONENT And_Gate IS
        PORT (
            a_in, b_in : IN BIT;
            c_out : OUT BIT
        );
    END COMPONENT;

    COMPONENT Xor_Gate IS
        PORT (
            a_in, b_in : IN BIT;
            s_out : OUT BIT
        );
    END COMPONENT;
BEGIN
    o_carry : And_Gate PORT MAP(a_in, b_in, c_out);
    o_sum : Xor_Gate PORT MAP(a_in, b_in, s_out);
END structure;
-- End of Half_Adder