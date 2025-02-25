-- The sequence being detected is "1001" or One Zero Zero One
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY VHDL_MOORE_FSM_Sequence_Detector IS
    PORT (
        clock : IN STD_LOGIC; --- clock signal
        reset : IN STD_LOGIC; -- reset input
        sequence_in : IN STD_LOGIC; -- binary sequence input
        detector_out : OUT STD_LOGIC -- output of the VHDL sequence detector
    );
END VHDL_MOORE_FSM_Sequence_Detector;

ARCHITECTURE Behavioral OF VHDL_MOORE_FSM_Sequence_Detector IS
    TYPE MOORE_FSM IS (Zero, One, OneZero, OneZeroZero, OneZeroZeroOne);
    SIGNAL current_state, next_state : MOORE_FSM;

BEGIN
    -- Sequential memory of the VHDL MOORE FSM Sequence Detector
    PROCESS (clock, reset)
    BEGIN
        IF (reset = '1') THEN
            current_state <= Zero;
        ELSIF (rising_edge(clock)) THEN
            current_state <= next_state;
        END IF;
    END PROCESS;
    -- Next state logic of the VHDL MOORE FSM Sequence Detector
    -- Combinational logic
    PROCESS (current_state, sequence_in)
    BEGIN
        CASE(current_state) IS
            WHEN Zero =>
            IF (sequence_in = '1') THEN
                -- "1"
                next_state <= One;
            ELSE
                next_state <= Zero;
            END IF;
            WHEN One =>
            IF (sequence_in = '0') THEN
                -- "10"
                next_state <= OneZero;
            ELSE
                next_state <= One;
            END IF;
            WHEN OneZero =>
            IF (sequence_in = '0') THEN
                -- "100"
                next_state <= OneZeroZero;
            ELSE
                next_state <= One;
            END IF;
            WHEN OneZeroZero =>
            IF (sequence_in = '1') THEN
                -- "1001"
                next_state <= OneZeroZeroOne;
            ELSE
                next_state <= Zero;
            END IF;
            WHEN OneZeroZeroOne =>
            IF (sequence_in = '1') THEN
                next_state <= One;
            ELSE
                next_state <= OneZero;
            END IF;
        END CASE;
    END PROCESS;
    -- Output logic of the VHDL MOORE FSM Sequence Detector
    PROCESS (current_state)
    BEGIN
        CASE current_state IS
            WHEN Zero =>
                detector_out <= '0';
            WHEN One =>
                detector_out <= '0';
            WHEN OneZero =>
                detector_out <= '0';
            WHEN OneZeroZero =>
                detector_out <= '0';
            WHEN OneZeroZeroOne =>
                detector_out <= '1';
        END CASE;
    END PROCESS;
END Behavioral;