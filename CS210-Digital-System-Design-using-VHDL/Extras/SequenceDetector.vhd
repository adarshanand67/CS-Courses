LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- D flip flop
ENTITY DFF IS
    PORT (
        D : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        R : IN STD_LOGIC;
        Q : OUT STD_LOGIC);
END DFF;

ARCHITECTURE Behav OF DFF IS
BEGIN
    DFF_process : PROCESS (CLK, R) IS
    BEGIN
        IF R = '1' THEN
            Q <= '0';
        ELSIF (CLK'event AND CLK = '1') THEN
            Q <= D;
        END IF;
    END PROCESS DFF_process;
END Behav;

ENTITY SequenceDet IS
    PORT (
        A : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        R : IN STD_LOGIC;
        Y : OUT STD_LOGIC);
END SequenceDet;

ARCHITECTURE Struct OF SequenceDet IS
    COMPONENT DFF IS
        PORT (
            D : IN STD_LOGIC;
            CLK : IN STD_LOGIC;
            R : IN STD_LOGIC;
            Q : OUT STD_LOGIC);
    END COMPONENT;

    SIGNAL Q : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0000";

BEGIN
    DFF3 : DFF PORT MAP(A, CLK, R, Q(3)); --Q3
    DFF2 : DFF PORT MAP(Q(3), CLK, R, Q(2)); --Q2
    DFF1 : DFF PORT MAP(Q(2), CLK, R, Q(1)); --Q1
    DFF0 : DFF PORT MAP(Q(1), CLK, R, Q(0)); --Q0

    Y <= Q(0) AND NOT(Q(1)) AND Q(2) AND Q(3);

END Struct;