LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

--1. D Flip Flop
ENTITY D_Flip_flop IS
    PORT (
        D : IN STD_LOGIC;
        CLK : IN STD_LOGIC;
        Q : OUT STD_LOGIC;
        QN : OUT STD_LOGIC
    );
END D_Flip_flop;
ARCHITECTURE D_Flip_flop_behav OF D_Flip_flop IS
BEGIN
    PROCESS (CLK)
    BEGIN
        IF CLK = '1' THEN
            Q <= D;
            QN <= NOT D;
        END IF;
    END PROCESS;
END D_Flip_flop_behav;

-- 2. Creating an entity for 4x1 Multiplexor.
ENTITY Mux4X1 IS
    PORT (
        -- Inputs
        A : IN STD_LOGIC;
        B : IN STD_LOGIC;
        C : IN STD_LOGIC;
        D : IN STD_LOGIC;
        s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
        -- Outputs
        Y : OUT STD_LOGIC_VECTOR (3 DOWNTO 0)
    );
END Mux4X1;

-- Creating And gate 
ENTITY And_Gate IS
    PORT (
        a_in : IN STD_LOGIC;
        b_in : IN STD_LOGIC;
        c_out : OUT BIT
    );
END And_Gate;
ARCHITECTURE gate OF And_Gate IS
BEGIN
    c_out <= a_in AND b_in;
END gate;
-- End of And_Gate

-- Creating Or gate
ENTITY Or_Gate IS
    PORT (
        a_in : IN STD_LOGIC;
        b_in : IN STD_LOGIC;
        c_out : OUT BIT
    );
END Or_Gate;
ARCHITECTURE gate OF Or_Gate IS
BEGIN
    c_out <= a_in OR b_in;
END gate;
-- End of Or_Gate

-- Creating Not gate
ENTITY Not_Gate IS
    PORT (
        a_in : IN STD_LOGIC;
        c_out : OUT BIT
    );
END Not_Gate;
ARCHITECTURE gate OF Not_Gate IS
BEGIN
    c_out <= NOT a_in;
END gate;
-- End of Not_Gate

ARCHITECTURE behav OF Mux4X1 IS
    y <= ((a AND (NOT(s(0))) AND (NOT(s(1)))) OR (b AND s(0) AND (NOT(s(1)))) OR (c AND (NOT(s(0))) AND s(1)) OR (d AND s(0) AND s(1)));
END behav;

ENTITY Sequence_Generator IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        x : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        y : OUT STD_LOGIC;
    );
END ENTITY;

-- 2. Creating a Sequence Generator
ARCHITECTURE seq_gen OF Sequence_Generator IS

    COMPONENT D_Flip_flop_behav
        PORT (
            D : IN STD_LOGIC;
            CLK : IN STD_LOGIC;
            Q : OUT STD_LOGIC;
            QN : OUT STD_LOGIC
        );
    END COMPONENT;

    COMPONENT Mux4X1
        PORT (
            A : IN STD_LOGIC;
            B : IN STD_LOGIC;
            C : IN STD_LOGIC;
            D : IN STD_LOGIC;
            s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            Y : OUT STD_LOGIC_VECTOR (3 DOWNTO 0)
        );
    END COMPONENT;

    SIGNAL x_reg : STD_LOGIC_VECTOR(3 DOWNTO 0); -- register for x
    SIGNAL y_reg : STD_LOGIC; -- register for y
    SIGNAL x_reg_next : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL y_reg_next : STD_LOGIC;
    proc1 : PROCESS (clk)
    BEGIN
        IF clk'event AND clk = '1' THEN
            IF rst = '1' THEN
                x_reg <= (OTHERS => '0');
                y_reg <= '0';
            ELSE
                x_reg_next <= x_reg(3 DOWNTO 0) & x(3);
                y_reg_next <= y_reg & x(2);
                x_reg <= x_reg_next;
                y_reg <= y_reg_next;
            END IF;
        END IF;
    END PROCESS;

    y <= y_reg;
END seq_gen;

-- Testing the Sequence Generator
ENTITY testbench IS
END ENTITY;

ARCHITECTURE test OF testbench IS
    SIGNAL x : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL y : STD_LOGIC;
    SIGNAL clk : STD_LOGIC;
    SIGNAL rst : STD_LOGIC;
    SIGNAL y_out : STD_LOGIC;
    SIGNAL y_out_next : STD_LOGIC;

    COMPONENT seq_gen
        PORT (
            clk : IN STD_LOGIC;
            rst : IN STD_LOGIC;
            x : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            y : OUT STD_LOGIC
        );
    END COMPONENT;

    COMPONENT testbench
        PORT (
            x : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            y : OUT STD_LOGIC;
            clk : IN STD_LOGIC;
            rst : IN STD_LOGIC
        );
    END COMPONENT;

    COMPONENT and_gate
        PORT (
            a_in : IN STD_LOGIC;
            b_in : IN STD_LOGIC;
            c_out : OUT STD_LOGIC
        );
    END COMPONENT;

    COMPONENT or_gate
        PORT (
            a_in : IN STD_LOGIC;
            b_in : IN STD_LOGIC;
            c_out : OUT STD_LOGIC
        );
    END COMPONENT;

    COMPONENT not_gate
        PORT (
            a_in : IN STD_LOGIC;
            c_out : OUT STD_LOGIC
        );
    END COMPONENT;

    COMPONENT mux4x1
        PORT (
            a : IN STD_LOGIC;
            b : IN STD_LOGIC;
            c : IN STD_LOGIC;
            d : IN STD_LOGIC;
            s : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
            y : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
        );
    END COMPONENT;

BEGIN
    clk <= NOT clk AFTER 10 ns;
    rst <= '1' AFTER 10 ns;
    x <= '0101' AFTER 10 ns;
    y <= '0' AFTER 10 ns;
    y_out <= '0' AFTER 10 ns;
end test;
