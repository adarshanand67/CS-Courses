-- Steps for Structural Moore/Mealy FSM
-- 1. Draw FSM
-- 2. 2^Number of flip flips = states, number of lip flops = Q0, Q1, Q2, n times
-- 2. Draw State transition Table
-- 3. Write next state Q's and Y in terms of min terms
-- 4. Convert those min terms into boolean expressions
-- Follow below code

-- For Behaviorial
-- Mealy - refer eda (azfj)
-- Moore - refer Lab 8 design

-- Have D flip flop declared in design
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

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;


ENTITY moore IS
    PORT (
        X : IN STD_LOGIC;
        Y : OUT STD_LOGIC
    );
END moore;

ARCHITECTURE arch OF moore IS
    COMPONENT Dflipflop
        PORT (
            D : IN STD_LOGIC;
            CLK : IN STD_LOGIC;
            Q : OUT STD_LOGIC;
            R : IN STD_LOGIC
        );
    END COMPONENT;

    SIGNAL Q : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
    SIGNAL D : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";

BEGIN
    DFF0 : Dflipflop PORT MAP(D(0), CLK, Q(0), R);
    DFF1 : Dflipflop PORT MAP(D(1), CLK, Q(1), R);

    D(0) <= (NOT Q(0)) AND (NOT Q(1)) AND X;
    D(1) <= (Q(0) AND X) OR (Q(1) AND X);

    Y <= Q(0);
END arch;