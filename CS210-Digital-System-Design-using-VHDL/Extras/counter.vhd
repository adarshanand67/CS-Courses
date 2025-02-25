LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY binaryCounter IS
    GENERIC (
        N : INTEGER := 3 -- N-bit binary counter
    );
    PORT (
        clk, reset : IN STD_LOGIC;
        complete_tick : OUT STD_LOGIC;
        count : OUT STD_LOGIC_VECTOR(N - 1 DOWNTO 0)
    );
END binaryCounter;

ARCHITECTURE arch OF binaryCounter IS
    CONSTANT MAX_COUNT : INTEGER := 2 ** N - 1; -- maximum count for N bit
    SIGNAL count_reg, count_next : unsigned(N - 1 DOWNTO 0);
BEGIN
    PROCESS (clk, reset)
    BEGIN
        IF reset = '1' THEN
            count_reg <= (OTHERS => '0'); -- set count to 0 if reset
        ELSIF clk'event AND clk = '1' THEN
            count_reg <= count_next; -- assign next value of count
        ELSE -- note that else block is not required
            NULL;
        END IF;
    END PROCESS;

    count_next <= count_reg + 1; -- increase the count

    -- Generate 'tick' on each maximum count
    complete_tick <= '1' WHEN count_reg = MAX_COUNT ELSE
        '0';

    count <= STD_LOGIC_VECTOR(count_reg); -- assign value to output port
END arch;