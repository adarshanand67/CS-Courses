LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

-- https://www.edaplayground.com/x/KZ5Z

ENTITY det0 IS
    PORT (
        X : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        R : IN STD_LOGIC;
        Y : OUT STD_LOGIC_VECTOR (2 DOWNTO 0)

    );
END det0;

ARCHITECTURE arch OF det0 IS
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
                        Q <= "000";
                    ELSE
                        Q <= "011";
                    END IF;

                WHEN "011" =>
                    IF X = '1' THEN
                        Q <= "000";
                    ELSE
                        Q <= "100";
                    END IF;
                WHEN OTHERS =>
                    Q <= "000";

            END CASE;
        END IF;
    END PROCESS;
    ouputdetect : PROCESS (Q) IS
    BEGIN
        CASE (Q) IS
            WHEN "000" => Y <= "000";
            WHEN "001" => Y <= "001";
            WHEN "010" => Y <= "010";
            WHEN "011" => Y <= "011";
            WHEN "100" => Y <= "100";
            WHEN OTHERS => Y <= "000";
        END CASE;
    END PROCESS;
END arch;