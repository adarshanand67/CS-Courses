LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- Moore Behavioural
ENTITY Moore001101detect IS
    PORT (
        X, R, CLK : IN STD_LOGIC;
        Y : OUT STD_LOGIC
    );
END Moore001101detect;
ARCHITECTURE behav OF Moore001101detect IS

    SIGNAL Q : STD_LOGIC_VECTOR(2 DOWNTO 0) := "000";
BEGIN
    proce_state : PROCESS (R, CLK)
    BEGIN
        IF (R = '1') THEN
            Q <= "000";
        ELSIF (CLK = '1' AND CLK'event) THEN
            CASE Q IS
                WHEN "000" =>
                    IF X = '1' THEN
                        Q <= "000";
                    ELSE
                        Q <= "001";
                    END IF;
                -- Add cases
                WHEN OTHERS =>
                    Q <= "000";

            END CASE;
        END IF;
    END PROCESS;
    -- Must put this process separately
    ouputdetect : PROCESS (Q) IS
    BEGIN
        CASE (Q) IS
            WHEN "110" => Y <= '1';
            WHEN OTHERS => Y <= '0';
        END CASE;
    END PROCESS;
END behav;

