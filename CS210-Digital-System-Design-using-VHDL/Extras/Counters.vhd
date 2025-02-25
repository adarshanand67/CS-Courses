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
                    Q <= NOT Q;
                END IF;
            END IF;
        END IF;
    END PROCESS proc;
END TffBehav;

ENTITY Bit3CountAsync IS
    PORT (
        Log : IN STD_LOGIC := '1';
        CLK : IN STD_LOGIC := '0'
    );
END Bit3CountAsync;

ARCHITECTURE arch OF Bit3CountAsync IS
    COMPONENT Tflipflop
    BEGIN
        PORT (
            T : IN STD_LOGIC;
            CLK : IN STD_LOGIC;
            Q : OUT STD_LOGIC;
            R : IN STD_LOGIC
        );
    END COMPONENT;

    SIGNAL log : IN STD_LOGIC := '1';
    SIGNAL R : IN STD_LOGIC := '0';
    SIGNAL CLK : IN STD_LOGIC := '0';
    SIGNAL Qa, Qb, Qc : INOUT STD_LOGIC := '0';
BEGIN
    TFF1 : Tflipflop PORT MAP(log, CLK, Qa, R);
    TFF2 : Tflipflop PORT MAP(log, Qa, Qb, R);
    TFF3 : Tflipflop PORT MAP(log, Qb, Qc, R);
END arch;

-- TestBench

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY testbench IS
END testbench;

ARCHITECTURE test OF testbench IS
    COMPONENT Bit3CountAsync IS
        PORT (
        Log : IN STD_LOGIC := '1';
        CLK : IN STD_LOGIC := '0'
    );
    END COMPONENT;
    SIGNAL log : IN STD_LOGIC := '1';
    SIGNAL R : IN STD_LOGIC := '0';
    SIGNAL CLK : IN STD_LOGIC := '0';
    SIGNAL Qa, Qb, Qc : INOUT STD_LOGIC := '0';

BEGIN
    BCount : Bit3CountAsync port map(log, CLK);
    -- SD : Moore001101detect PORT MAP(X, R, CLK, Y);
    -- R <= '1', '0' AFTER 8 ns;
    CLK <= NOT CLK AFTER 5ns;
    

END ARCHITECTURE;