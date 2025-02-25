-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

-- For Structural Description

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY decoder_3x8_struc IS
    PORT (
        X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
        E : IN STD_LOGIC;
        D0, D1, D2, D3, D4, D5, D6, D7 : OUT STD_LOGIC);
END decoder_3x8_struc;

ARCHITECTURE Structural OF decoder_3x8_struc IS
BEGIN
    D0 <= (NOT(X(2)) AND NOT(X(1)) AND NOT(X(0)) AND E);
    D1 <= (NOT(X(2)) AND NOT(X(1)) AND X(0) AND E);
    D2 <= (NOT(X(2)) AND X(1) AND NOT(X(0)) AND E);
    D3 <= (NOT(X(2)) AND X(1) AND X(0) AND E);
    D4 <= (X(2) AND NOT(X(1)) AND NOT(X(0)) AND E);
    D5 <= (X(2) AND NOT(X(1)) AND X(0) AND E);
    D6 <= (X(2) AND X(1) AND NOT(X(0)) AND E);
    D7 <= (X(2) AND X(1) AND X(0) AND E);

END Structural;

-- For DataFlow Description

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY decoder_3x8_dataflow IS
    PORT (
        X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
        E : IN STD_LOGIC;
        D0, D1, D2, D3, D4, D5, D6, D7 : OUT STD_LOGIC);
END decoder_3x8_dataflow;

ARCHITECTURE DataFlow OF decoder_3x8_dataflow IS
BEGIN
    D0 <= E WHEN (X = "000") ELSE
        '0';
    D1 <= E WHEN (X = "001") ELSE
        '0';
    D2 <= E WHEN (X = "010") ELSE
        '0';
    D3 <= E WHEN (X = "011") ELSE
        '0';
    D4 <= E WHEN (X = "100") ELSE
        '0';
    D5 <= E WHEN (X = "101") ELSE
        '0';
    D6 <= E WHEN (X = "110") ELSE
        '0';
    D7 <= E WHEN (X = "111") ELSE
        '0';

END DataFlow;