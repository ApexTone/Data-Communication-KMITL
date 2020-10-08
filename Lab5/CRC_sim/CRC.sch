<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="data_word" />
        <signal name="XLXN_10" />
        <signal name="XLXN_13" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="led1" />
        <signal name="led4" />
        <signal name="XLXN_36" />
        <signal name="clock" />
        <signal name="clear" />
        <signal name="led2" />
        <signal name="led3" />
        <signal name="XLXN_52" />
        <port polarity="Input" name="data_word" />
        <port polarity="Output" name="led1" />
        <port polarity="Output" name="led4" />
        <port polarity="Input" name="clock" />
        <port polarity="Input" name="clear" />
        <port polarity="Output" name="led2" />
        <port polarity="Output" name="led3" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <blockdef name="fjkc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-320" y2="-320" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="64" y1="-32" y2="-32" x1="192" />
            <line x2="192" y1="-64" y2="-32" x1="192" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
            <rect width="256" x="64" y="-384" height="320" />
        </blockdef>
        <block symbolname="inv" name="XLXI_5">
            <blockpin signalname="XLXN_36" name="I" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_6">
            <blockpin signalname="led2" name="I" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_7">
            <blockpin signalname="data_word" name="I0" />
            <blockpin signalname="led4" name="I1" />
            <blockpin signalname="XLXN_36" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_8">
            <blockpin signalname="led4" name="I0" />
            <blockpin signalname="led3" name="I1" />
            <blockpin signalname="XLXN_52" name="O" />
        </block>
        <block symbolname="fjkc" name="XLXI_9">
            <blockpin signalname="clock" name="C" />
            <blockpin signalname="clear" name="CLR" />
            <blockpin signalname="XLXN_36" name="J" />
            <blockpin signalname="XLXN_10" name="K" />
            <blockpin signalname="led1" name="Q" />
        </block>
        <block symbolname="fjkc" name="XLXI_10">
            <blockpin signalname="clock" name="C" />
            <blockpin signalname="clear" name="CLR" />
            <blockpin signalname="led1" name="J" />
            <blockpin signalname="XLXN_13" name="K" />
            <blockpin signalname="led2" name="Q" />
        </block>
        <block symbolname="fjkc" name="XLXI_12">
            <blockpin signalname="clock" name="C" />
            <blockpin signalname="clear" name="CLR" />
            <blockpin signalname="XLXN_52" name="J" />
            <blockpin signalname="XLXN_24" name="K" />
            <blockpin signalname="led4" name="Q" />
        </block>
        <block symbolname="inv" name="XLXI_13">
            <blockpin signalname="led1" name="I" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_14">
            <blockpin signalname="XLXN_52" name="I" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="fjkc" name="XLXI_11">
            <blockpin signalname="clock" name="C" />
            <blockpin signalname="clear" name="CLR" />
            <blockpin signalname="led2" name="J" />
            <blockpin signalname="XLXN_23" name="K" />
            <blockpin signalname="led3" name="Q" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="544" y="1056" name="XLXI_9" orien="R0" />
        <branch name="data_word">
            <wire x2="3088" y1="368" y2="368" x1="2704" />
        </branch>
        <branch name="XLXN_10">
            <wire x2="544" y1="800" y2="800" x1="512" />
        </branch>
        <instance x="288" y="832" name="XLXI_5" orien="R0" />
        <instance x="3088" y="432" name="XLXI_7" orien="R0" />
        <branch name="XLXN_23">
            <wire x2="1968" y1="832" y2="832" x1="1952" />
            <wire x2="1984" y1="832" y2="832" x1="1968" />
        </branch>
        <instance x="1728" y="864" name="XLXI_6" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="2720" y1="832" y2="832" x1="2672" />
        </branch>
        <instance x="1008" y="848" name="XLXI_13" orien="R0" />
        <instance x="2720" y="1088" name="XLXI_12" orien="R0" />
        <instance x="2448" y="864" name="XLXI_14" orien="R0" />
        <instance x="1808" y="288" name="XLXI_8" orien="R0" />
        <branch name="led4">
            <wire x2="1808" y1="224" y2="224" x1="1744" />
            <wire x2="1744" y1="224" y2="256" x1="1744" />
            <wire x2="3072" y1="256" y2="256" x1="1744" />
            <wire x2="3072" y1="256" y2="304" x1="3072" />
            <wire x2="3088" y1="304" y2="304" x1="3072" />
            <wire x2="3408" y1="224" y2="224" x1="3072" />
            <wire x2="3408" y1="224" y2="832" x1="3408" />
            <wire x2="3072" y1="224" y2="256" x1="3072" />
            <wire x2="3200" y1="832" y2="832" x1="3104" />
            <wire x2="3408" y1="832" y2="832" x1="3200" />
            <wire x2="3200" y1="832" y2="1472" x1="3200" />
        </branch>
        <branch name="XLXN_36">
            <wire x2="240" y1="688" y2="800" x1="240" />
            <wire x2="288" y1="800" y2="800" x1="240" />
            <wire x2="528" y1="688" y2="688" x1="240" />
            <wire x2="528" y1="688" y2="736" x1="528" />
            <wire x2="544" y1="736" y2="736" x1="528" />
            <wire x2="3424" y1="624" y2="624" x1="528" />
            <wire x2="528" y1="624" y2="688" x1="528" />
            <wire x2="3424" y1="336" y2="336" x1="3344" />
            <wire x2="3424" y1="336" y2="624" x1="3424" />
        </branch>
        <branch name="clear">
            <wire x2="352" y1="1024" y2="1024" x1="288" />
            <wire x2="544" y1="1024" y2="1024" x1="352" />
            <wire x2="352" y1="1024" y2="1040" x1="352" />
            <wire x2="1280" y1="1040" y2="1040" x1="352" />
            <wire x2="1296" y1="1040" y2="1040" x1="1280" />
            <wire x2="1296" y1="1040" y2="1056" x1="1296" />
            <wire x2="1888" y1="1056" y2="1056" x1="1296" />
            <wire x2="1984" y1="1056" y2="1056" x1="1888" />
            <wire x2="1888" y1="1056" y2="1072" x1="1888" />
            <wire x2="2720" y1="1072" y2="1072" x1="1888" />
            <wire x2="1312" y1="1040" y2="1040" x1="1296" />
            <wire x2="2720" y1="1056" y2="1072" x1="2720" />
        </branch>
        <iomarker fontsize="28" x="288" y="1024" name="clear" orien="R180" />
        <iomarker fontsize="28" x="320" y="928" name="clock" orien="R180" />
        <iomarker fontsize="28" x="2704" y="368" name="data_word" orien="R180" />
        <iomarker fontsize="28" x="3200" y="1472" name="led4" orien="R90" />
        <iomarker fontsize="28" x="2400" y="1536" name="led3" orien="R90" />
        <iomarker fontsize="28" x="1760" y="1408" name="led2" orien="R180" />
        <iomarker fontsize="28" x="960" y="1392" name="led1" orien="R90" />
        <instance x="1984" y="1088" name="XLXI_11" orien="R0" />
        <branch name="clock">
            <wire x2="448" y1="928" y2="928" x1="320" />
            <wire x2="544" y1="928" y2="928" x1="448" />
            <wire x2="448" y1="928" y2="1104" x1="448" />
            <wire x2="992" y1="1104" y2="1104" x1="448" />
            <wire x2="1760" y1="1104" y2="1104" x1="992" />
            <wire x2="992" y1="944" y2="1104" x1="992" />
            <wire x2="1312" y1="944" y2="944" x1="992" />
            <wire x2="1760" y1="960" y2="1104" x1="1760" />
            <wire x2="1872" y1="960" y2="960" x1="1760" />
            <wire x2="1984" y1="960" y2="960" x1="1872" />
            <wire x2="1872" y1="960" y2="1120" x1="1872" />
            <wire x2="2416" y1="1120" y2="1120" x1="1872" />
            <wire x2="2416" y1="960" y2="1120" x1="2416" />
            <wire x2="2720" y1="960" y2="960" x1="2416" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="1248" y1="816" y2="816" x1="1232" />
            <wire x2="1312" y1="816" y2="816" x1="1248" />
        </branch>
        <branch name="led1">
            <wire x2="960" y1="800" y2="800" x1="928" />
            <wire x2="960" y1="800" y2="816" x1="960" />
            <wire x2="1008" y1="816" y2="816" x1="960" />
            <wire x2="976" y1="800" y2="800" x1="960" />
            <wire x2="976" y1="800" y2="880" x1="976" />
            <wire x2="960" y1="752" y2="800" x1="960" />
            <wire x2="1312" y1="752" y2="752" x1="960" />
            <wire x2="976" y1="880" y2="880" x1="960" />
            <wire x2="960" y1="880" y2="1392" x1="960" />
        </branch>
        <instance x="1312" y="1072" name="XLXI_10" orien="R0" />
        <branch name="led2">
            <wire x2="1712" y1="816" y2="816" x1="1696" />
            <wire x2="1712" y1="816" y2="832" x1="1712" />
            <wire x2="1728" y1="832" y2="832" x1="1712" />
            <wire x2="1712" y1="768" y2="816" x1="1712" />
            <wire x2="1760" y1="768" y2="768" x1="1712" />
            <wire x2="1984" y1="768" y2="768" x1="1760" />
            <wire x2="1760" y1="640" y2="768" x1="1760" />
            <wire x2="3152" y1="640" y2="640" x1="1760" />
            <wire x2="3152" y1="640" y2="1408" x1="3152" />
            <wire x2="3152" y1="1408" y2="1408" x1="1760" />
        </branch>
        <branch name="led3">
            <wire x2="1728" y1="80" y2="160" x1="1728" />
            <wire x2="1808" y1="160" y2="160" x1="1728" />
            <wire x2="2432" y1="80" y2="80" x1="1728" />
            <wire x2="2432" y1="80" y2="832" x1="2432" />
            <wire x2="2400" y1="832" y2="832" x1="2368" />
            <wire x2="2432" y1="832" y2="832" x1="2400" />
            <wire x2="2400" y1="832" y2="1536" x1="2400" />
        </branch>
        <branch name="XLXN_52">
            <wire x2="2384" y1="192" y2="192" x1="2064" />
            <wire x2="2384" y1="192" y2="768" x1="2384" />
            <wire x2="2448" y1="768" y2="768" x1="2384" />
            <wire x2="2720" y1="768" y2="768" x1="2448" />
            <wire x2="2448" y1="768" y2="832" x1="2448" />
        </branch>
    </sheet>
</drawing>