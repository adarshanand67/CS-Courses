LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- D Flip Flop
ENTITY Dflipflop IS
    PORT (
        D : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        R : IN STD_LOGIC
    );
END Dflipflop;

-- Behavioural Modelling
ARCHITECTURE DffBehav OF Dflipflop IS
BEGIN
    proc : PROCESS (CLK, R) IS
    BEGIN
        IF R = '1' THEN
            Q <= '0';
        ELSE
            IF CLK'event AND CLK = '1' THEN
                Q <= D;
            END IF;
        END IF;
    END PROCESS proc;
END DffBehav;

-- T FLip Flop
ENTITY Tflipflop IS
    PORT (
        T : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        R : IN STD_LOGIC
    );
END Tflipflop;

-- Behavioural Architecture (Asynchronous)
ARCHITECTURE TffBehav OF Tflipflop IS
BEGIN
    proc : PROCESS (CLK, R) IS
    BEGIN
        IF R = '1' THEN
            Q <= '0';
        ELSE
            IF CLK'event AND CLK = '0' THEN
                IF T = '1' THEN
                    Q <= NOT Q;
                END IF;
            END IF;
        END IF;
    END PROCESS proc;
END TffBehav;

-- Structural Architecture 
-- TODO

