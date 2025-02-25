-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY Tflipflop IS
    PORT (
        T : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        R : IN STD_LOGIC
    );
END Tflipflop;

ARCHITECTURE TffBehav OF Tflipflop IS
BEGIN
    proc : PROCESS (CLK, R) IS
    BEGIN
        IF R = '1' THEN
            Q <= '0';
        ELSE
            IF CLK'event AND CLK = '0' THEN
                IF T = '1' THEN
                    Q <= not Q;
                END IF;
            END IF;
        END IF;
    END PROCESS proc;
END TffBehav;