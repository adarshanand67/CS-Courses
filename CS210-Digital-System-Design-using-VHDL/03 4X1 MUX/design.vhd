-- Team: Digital Daemon
-- Team Member 1: Adarsh Anand (2003101)
-- Team Member 2: Aniket Akshay Chaudhri (2003104)

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- Creating an entity for 4x1 Multiplexor.
ENTITY Mux4X1 IS
    PORT (
        -- Inputs
        A : IN STD_LOGIC;
        B : IN STD_LOGIC;
        C : IN STD_LOGIC;
        D : IN STD_LOGIC;
        s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        -- Outputs
        Y : OUT STD_LOGIC_VECTOR (3 DOWNTO 0)
    );
END Mux4X1;

-- Creating And gate 
ENTITY And_Gate IS
    PORT (
        a_in : IN STD_LOGIC;
        b_in : IN STD_LOGIC;
        c_out : OUT BIT
    );
END And_Gate;
ARCHITECTURE gate OF And_Gate IS
BEGIN
    c_out <= a_in AND b_in;
END gate;
-- End of And_Gate

-- Creating Or gate
ENTITY Or_Gate IS
    PORT (
        a_in : IN STD_LOGIC;
        b_in : IN STD_LOGIC;
        c_out : OUT BIT
    );
END Or_Gate;
ARCHITECTURE gate OF Or_Gate IS
BEGIN
    c_out <= a_in OR b_in;
END gate;
-- End of Or_Gate

-- Creating Not gate
ENTITY Not_Gate IS
    PORT (
        a_in : IN STD_LOGIC;
        c_out : OUT BIT
    );
END Not_Gate;
ARCHITECTURE gate OF Not_Gate IS
BEGIN
    c_out <= NOT a_in;
END gate;
-- End of Not_Gate

ARCHITECTURE behav OF Mux4X1 IS
    y <= ((a AND (NOT(s(0))) AND (NOT(s(1)))) OR (b AND s(0) AND (NOT(s(1)))) OR (c AND (NOT(s(0))) AND s(1)) OR (d AND s(0) AND s(1)));
END behav;