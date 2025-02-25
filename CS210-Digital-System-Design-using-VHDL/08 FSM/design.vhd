-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

-- FINAL: https://www.edaplayground.com/x/XLJD 

-- Trials:
        -- https://www.edaplayground.com/x/fG8b vector logic
        -- https://www.edaplayground.com/x/C74P state type logic


LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

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

                WHEN "001" =>
                    IF X = '1' THEN
                        Q <= "000";
                    ELSE
                        Q <= "010";
                    END IF;

                WHEN "010" =>
                    IF X = '1' THEN
                        Q <= "011";
                    ELSE
                        Q <= "010";
                    END IF;

                WHEN "011" =>
                    IF X = '1' THEN
                        Q <= "100";
                    ELSE
                        Q <= "001";
                    END IF;

                WHEN "100" =>
                    IF X = '1' THEN
                        Q <= "000";
                    ELSE
                        Q <= "101";
                    END IF;

                WHEN "101" =>
                    IF X = '1' THEN
                        Q <= "110";
                    ELSE
                        Q <= "010";
                    END IF;

                WHEN "110" =>
                    IF X = '1' THEN
                        Q <= "000";
                    ELSE
                        Q <= "001";
                    END IF;

                WHEN OTHERS =>
                    Q <= "000";

            END CASE;
        END IF;
    END PROCESS;
    ouputdetect : PROCESS (Q) IS
    BEGIN
        CASE (Q) IS
            WHEN "110" => Y <= '1';
            WHEN OTHERS => Y <= '0';
        END CASE;
    END PROCESS;
END behav;