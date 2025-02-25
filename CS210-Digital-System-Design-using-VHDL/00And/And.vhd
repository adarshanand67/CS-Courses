LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY And_Gate IS
    PORT (
        a : IN BIT;
        b : IN BIT;
        c : OUT BIT
    );
END And_Gate;

ARCHITECTURE Behav OF And_Gate IS

BEGIN
    c <= a AND b;
END Behav;