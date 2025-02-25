LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- 1. JK Flip Flop
ENTITY JK IS
    PORT (
        J : IN STD_LOGIC;
        K : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : INOUT STD_LOGIC; -- Note INOUT 
        QN : INOUT STD_LOGIC;
    );
END JK;
ARCHITECTURE JKarchi OF JK IS
BEGIN
    PROCESS (CLK, J, K)
    BEGIN
        IF (CLK = '1' AND CLK'event) THEN
            IF (J = '0' AND K = '0') THEN
                Q <= Q;
                QN <= QN;
            ELSIF (J = '0' AND K = '1') THEN
                Q <= '1';
                QN <= '0';
            ELSIF (J = '1' AND K = '0') THEN
                Q <= '0';
                QN <= '1';
            ELSIF (J = '1' AND K = '1') THEN
                Q <= NOT Q;
                QN <= NOT QN;
            END IF;
        END IF;
    END PROCESS;

END JKarchi;

-- 2. D Flip Flop
ENTITY DF IS
    PORT (
        D : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        QN : OUT STD_LOGIC
    );
END DF;
ARCHITECTURE DFarchi OF DF IS
BEGIN
    PROCESS (CLK)
    BEGIN
        IF CLK = '1' THEN
            Q <= D;
            QN <= NOT D;
        END IF;
    END PROCESS;
END DFarchi;

-- 3. T Flip Flop
ENTITY TFF IS
    PORT (
        T : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        QN : OUT STD_LOGIC
    );
END TFF;
ARCHITECTURE TFFarchi OF TFF IS
BEGIN
    PROCESS (CLK, T)
    BEGIN
        IF (CLK = '1' AND CLK'event) THEN
            IF (T = '0') THEN
                Q <= '1';
                QN <= '0';
            ELSE
                Q <= '0';
                QN <= '1';
            END IF;
        END IF;
    END PROCESS;
END TFFarchi;

-- 4. SR Flip Flop or Latch
ENTITY SR IS
    PORT (
        R : IN STD_LOGIC;
        S : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        QN : OUT STD_LOGIC
    );
END SR;
ARCHITECTURE SRarchi OF SR IS
BEGIN
    PROCESS (CLK, R, S)
    BEGIN
        IF (CLK = '1' AND CLK'event) THEN
            IF (R = '0' AND S = '0') THEN
                Q <= Q;
                QN <= QN;
            ELSIF (R = '0' AND S = '1') THEN
                Q <= '1';
                QN <= '0';
            ELSIF (R = '1' AND S = '0') THEN
                Q <= '0';
                QN <= '1';
            ELSIF (R = '1' AND S = '1') THEN
                Q <= NOT Q;
                QN <= NOT QN;
            END IF;
        END IF;
    END PROCESS;
END SRarchi;