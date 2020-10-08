--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____ 
--  /   /\/   / 
-- /___/  \  /    Vendor: Xilinx 
-- \   \   \/     Version : 14.7
--  \   \         Application : sch2hdl
--  /   /         Filename : CRC.vhf
-- /___/   /\     Timestamp : 09/17/2020 22:12:04
-- \   \  /  \ 
--  \___\/\___\ 
--
--Command: sch2hdl -intstyle ise -family spartan6 -flat -suppress -vhdl "C:/Users/Predator/Desktop/Learning Resources/DataCom/Lab/Lab5/CRC_sim/CRC.vhf" -w "C:/Users/Predator/Desktop/Learning Resources/DataCom/Lab/Lab5/CRC_sim/CRC.sch"
--Design Name: CRC
--Device: spartan6
--Purpose:
--    This vhdl netlist is translated from an ECS schematic. It can be 
--    synthesized and simulated, but it should not be modified. 
--
----- CELL FJKC_HXILINX_CRC -----


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity FJKC_HXILINX_CRC is
generic(
    INIT : bit := '0'
    );

  port (
    Q   : out STD_LOGIC := '0';
    C   : in STD_LOGIC;
    CLR : in STD_LOGIC;
    J   : in STD_LOGIC;
    K   : in STD_LOGIC
    );
end FJKC_HXILINX_CRC;

architecture Behavioral of FJKC_HXILINX_CRC is
signal q_tmp : std_logic := TO_X01(INIT);

begin

process(C, CLR)
begin
  if (CLR='1') then
    q_tmp <= '0';
  elsif (C'event and C = '1') then
    if(J='0') then
      if(K='1') then
      q_tmp <= '0';
    end if;
    else
      if(K='0') then
      q_tmp <= '1';
      else
      q_tmp <= not q_tmp;
      end if;
    end if;
  end if;  
end process;

Q <= q_tmp;

end Behavioral;


library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
library UNISIM;
use UNISIM.Vcomponents.ALL;

entity CRC is
   port ( clear     : in    std_logic; 
          clock     : in    std_logic; 
          data_word : in    std_logic; 
          led1      : out   std_logic; 
          led2      : out   std_logic; 
          led3      : out   std_logic; 
          led4      : out   std_logic);
end CRC;

architecture BEHAVIORAL of CRC is
   attribute BOX_TYPE   : string ;
   attribute HU_SET     : string ;
   signal XLXN_10    : std_logic;
   signal XLXN_13    : std_logic;
   signal XLXN_23    : std_logic;
   signal XLXN_24    : std_logic;
   signal XLXN_36    : std_logic;
   signal XLXN_52    : std_logic;
   signal led1_DUMMY : std_logic;
   signal led2_DUMMY : std_logic;
   signal led3_DUMMY : std_logic;
   signal led4_DUMMY : std_logic;
   component INV
      port ( I : in    std_logic; 
             O : out   std_logic);
   end component;
   attribute BOX_TYPE of INV : component is "BLACK_BOX";
   
   component XOR2
      port ( I0 : in    std_logic; 
             I1 : in    std_logic; 
             O  : out   std_logic);
   end component;
   attribute BOX_TYPE of XOR2 : component is "BLACK_BOX";
   
   component FJKC_HXILINX_CRC
      port ( C   : in    std_logic; 
             CLR : in    std_logic; 
             J   : in    std_logic; 
             K   : in    std_logic; 
             Q   : out   std_logic);
   end component;
   
   attribute HU_SET of XLXI_9 : label is "XLXI_9_0";
   attribute HU_SET of XLXI_10 : label is "XLXI_10_1";
   attribute HU_SET of XLXI_11 : label is "XLXI_11_3";
   attribute HU_SET of XLXI_12 : label is "XLXI_12_2";
begin
   led1 <= led1_DUMMY;
   led2 <= led2_DUMMY;
   led3 <= led3_DUMMY;
   led4 <= led4_DUMMY;
   XLXI_5 : INV
      port map (I=>XLXN_36,
                O=>XLXN_10);
   
   XLXI_6 : INV
      port map (I=>led2_DUMMY,
                O=>XLXN_23);
   
   XLXI_7 : XOR2
      port map (I0=>data_word,
                I1=>led4_DUMMY,
                O=>XLXN_36);
   
   XLXI_8 : XOR2
      port map (I0=>led4_DUMMY,
                I1=>led3_DUMMY,
                O=>XLXN_52);
   
   XLXI_9 : FJKC_HXILINX_CRC
      port map (C=>clock,
                CLR=>clear,
                J=>XLXN_36,
                K=>XLXN_10,
                Q=>led1_DUMMY);
   
   XLXI_10 : FJKC_HXILINX_CRC
      port map (C=>clock,
                CLR=>clear,
                J=>led1_DUMMY,
                K=>XLXN_13,
                Q=>led2_DUMMY);
   
   XLXI_11 : FJKC_HXILINX_CRC
      port map (C=>clock,
                CLR=>clear,
                J=>led2_DUMMY,
                K=>XLXN_23,
                Q=>led3_DUMMY);
   
   XLXI_12 : FJKC_HXILINX_CRC
      port map (C=>clock,
                CLR=>clear,
                J=>XLXN_52,
                K=>XLXN_24,
                Q=>led4_DUMMY);
   
   XLXI_13 : INV
      port map (I=>led1_DUMMY,
                O=>XLXN_13);
   
   XLXI_14 : INV
      port map (I=>XLXN_52,
                O=>XLXN_24);
   
end BEHAVIORAL;


