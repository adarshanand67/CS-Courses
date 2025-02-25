LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

-- Draw a Moore-type FSM for a circuit with an asynchronous reset input R, 
-- a clock input CLK, a single bit synchronous input X and a three-bit output Y 
-- (consisting of bits Y(2), Y(1) and Y(0)).
-- Write a behavioral-style VHDL description for the FSM using a process block 
-- and the case construct.

ENTITY Successive_Zero_Counter IS
    PORT (
        R : IN STD_LOGIC; -- Reset input
        CLK : IN STD_LOGIC; -- Clock input
        X : IN STD_LOGIC; -- Synchronous input
        Y : OUT STD_LOGIC_VECTOR(2 DOWNTO 0) -- Output Y(2), Y(1) and Y(0)
    );
END ENTITY;

ARCHITECTURE Behav OF Successive_Zero_Counter IS
BEGIN
    SIGNAL count : STD_LOGIC_VECTOR(2 DOWNTO 0); -- Internal state
    SIGNAL reset : STD_LOGIC; -- Internal reset

    -- count wraps around to “000” after “100”.
    -- However whenever an input of ‘1’ is received on X, the 
    -- count value resets to ‘000’
    proc1 : PROCESS (CLK, R, X) IS
    BEGIN
        IF rising_edge(CLK) THEN -- Rising edge of clock
            IF R = '1' THEN -- Reset condition
                count <= '000';
            ELSE
                IF X = '0' THEN --0 input
                    count <= count + '001';
                ELSE
                    count <= '000'; --1 input
                END IF;
            END IF;
        END IF;
    END PROCESS;

    proc2 : PROCESS (CLK)
    BEGIN
        IF rising_edge(CLK) THEN
            reset <= '0';
        END IF;
    END PROCESS;

    -- Outputs
    Y <= count;
END Behav;


-- Write an appropriate Testbench and check that the circuit works as 
ENTITY test_bench IS
END test_bench;

ARCHITECTURE test_bench OF Successive_Zero_Counter IS
    SIGNAL clk : STD_LOGIC;
    SIGNAL rst : STD_LOGIC;
    SIGNAL x : STD_LOGIC;
    SIGNAL y : STD_LOGIC_VECTOR(2 DOWNTO 0);
BEGIN
    clk <= '0';
    rst <= '0';
    x <= '0';
    y <= '000';
    clk <= NOT clk AFTER 10 ns;

    -- Testbench
    PROCESS (clk)
    BEGIN
        IF rising_edge(clk) THEN
            IF rst = '0' THEN
                x <= '0';
            ELSE
                x <= '1';
            END IF;
        END IF;
    END PROCESS;
END test_bench;