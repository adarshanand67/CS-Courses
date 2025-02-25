LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- I have changed input D to E to avoid conflict with D input of flip flop

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

ENTITY Mux4X1 IS
    PORT (
        -- Inputs
        A : IN STD_LOGIC;
        B : IN STD_LOGIC;
        C : IN STD_LOGIC;
        E : IN STD_LOGIC;
        s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        -- Outputs
        Y : OUT STD_LOGIC
    );
END Mux4X1;

ARCHITECTURE behav OF Mux4X1 IS
    y <= ((a AND (NOT(s(0))) AND (NOT(s(1)))) OR (b AND s(0) AND (NOT(s(1)))) OR (c AND (NOT(s(0))) AND s(1)) OR (d AND s(0) AND s(1)));
END behav;

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY SeqGen IS
    PORT (
        A, B, C, E : IN STD_LOGIC;
        CLK, R : IN STD_LOGIC;
        Y : OUT STD_LOGIC

    );
END SeqGen;

ARCHITECTURE arch OF SeqGen IS
    COMPONENT Dflipflop
        PORT (
            D : IN STD_LOGIC;
            CLK : IN STD_LOGIC;
            Q : OUT STD_LOGIC;
            R : IN STD_LOGIC
        );

    END COMPONENT;
    COMPONENT Mux4X1
        PORT (
            -- Inputs
            A : IN STD_LOGIC;
            B : IN STD_LOGIC;
            C : IN STD_LOGIC;
            E : IN STD_LOGIC;
            s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            -- Outputs
            Y : OUT STD_LOGIC
        );
    END COMPONENT;
    SIGNAL Qs : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
    SIGNAL Ds : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";

BEGIN
    DFF0 : DFlipFlop PORT MAP(Ds(0), CLK, Qs(0), R);
    DFF1 : DFlipFlop PORT MAP(Ds(1), CLK, Qs(1), R);
    Mux : Mux4X1 PORT MAP(A, B, C, E, Qs, Y);

    Ds(0) <= Qs(0);
    Ds(1) <= Qs(1) XOR Qs(0);

END arch;