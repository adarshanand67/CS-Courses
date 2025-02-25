-- Team Digital Demons
-- Aniket Akshay Chaudhri (2003104)
-- Adarsh (2003101)

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

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY Combinational_ckt IS
    PORT (
        X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
        F0, F1, F2, F3 : OUT STD_LOGIC
    );
END Combinational_ckt;

ARCHITECTURE ckt OF Combinational_ckt IS
    COMPONENT decoder_3x8_dataflow
        PORT (
            X : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
            E : IN STD_LOGIC;
            D0, D1, D2, D3, D4, D5, D6, D7 : OUT STD_LOGIC);
    END COMPONENT;

    SIGNAL E : std_logic := '1';
    SIGNAL D0, D1, D2, D3, D4, D5, D6, D7 : STD_LOGIC;
BEGIN
    Decoder : decoder_3x8_dataflow PORT MAP(X, E, D0, D1, D2, D3, D4, D5, D6, D7);

    -- all inputs zero
    F0 <= D0;
    -- even:0,2,4,6 ; multiple of 3: 3,6
    F1 <= (D0 OR D2 OR D3 OR D4 OR D6);
    -- 6 and 7
    F2 <= (D6 OR D7);
    -- 1: 0001, 2: 0010, 4: 0100, 7: 0111
    F3 <= (D1 OR D2 OR D4 OR D7);

END ckt;