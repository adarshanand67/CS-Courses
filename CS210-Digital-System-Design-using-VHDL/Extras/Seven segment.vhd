LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

-- Seven segment display
-- https://www.youtube.com/watch?v=smeUN1Bxj3M 
-- https://www.youtube.com/watch?v=_qGFpgpqf7s

ENTITY SevenSegment IS
    PORT (
        A : IN STD_LOGIC;
        B : IN STD_LOGIC;
        C : IN STD_LOGIC;
        D : IN STD_LOGIC;
        S0 : OUT STD_LOGIC;
        S1 : OUT STD_LOGIC;
        S2 : OUT STD_LOGIC;
        S3 : OUT STD_LOGIC;
        S4 : OUT STD_LOGIC;
        S5 : OUT STD_LOGIC;
        S6 : OUT STD_LOGIC);
END SevenSegment;

ARCHITECTURE behav OF SevenSegment IS
BEGIN
    S0 <= NOT(((NOT A) AND (NOT B) AND (NOT C) AND (D)) OR (B AND (NOT C) AND (NOT D)));
    S1 <= NOT((B AND (NOT C)AND D) OR (B AND C AND (NOT D)));
    S2 <= NOT((NOT B)AND C AND (NOT D));
    S3 <= NOT((B AND (NOT C) AND (NOT D)) OR ((NOT A) AND (NOT B) AND (NOT C)AND D) OR (B AND C AND D));
    S4 <= NOT((D) OR (B AND(NOT C)));
    S5 <= NOT((C AND D) OR ((NOT B)AND C) OR ((NOT A) AND (NOT B)AND D));
    S6 <= NOT(((NOT A) AND (NOT B) AND (NOT C)) OR (B AND C AND D));
END behav;