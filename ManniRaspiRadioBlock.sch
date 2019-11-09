<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.3.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<modules>
<module name="AM-C/F" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="OUT" side="right" coord="-5.08" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="FM-C/F" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="OUT" side="right" coord="5.08" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="F-SELECT" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="IN_AM" side="left" coord="5.08" direction="io"/>
<port name="IN_FM" side="left" coord="-5.08" direction="io"/>
<port name="OUT" side="right" coord="0" direction="io"/>
<port name="SELECT" side="right" coord="-5.08" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="GRAFIC_EQAULIZER" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="IN" side="top" coord="-2.54" direction="io"/>
<port name="OUT" side="bottom" coord="0" direction="io"/>
<port name="CONTROL" side="left" coord="-5.08" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="AUDIO_SWITCH" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="FM_IN" side="left" coord="5.08" direction="io"/>
<port name="RASPI_IN" side="left" coord="-2.54" direction="io"/>
<port name="OUT" side="right" coord="-2.54" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="AMPLIFIER" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="IN" side="left" coord="-2.54" direction="io"/>
<port name="OUT" side="right" coord="-2.54" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="RASPBERRY_PI" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="FM_RADIO" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="AUDIO" side="bottom" coord="0" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="KEYBOARD" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="LED_STRIP" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="5V_DC/DC" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="HDMI_MONITOR" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="AUDIO" side="top" coord="0" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="3,3V_LDO" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="AUDIO_DELAY" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="IN" side="left" coord="-2.54" direction="io"/>
<port name="OUT" side="right" coord="-2.54" direction="io"/>
<port name="CONTROL" side="bottom" coord="-2.54" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="SPEAKER" prefix="" dx="30.48" dy="20.32">
<ports>
<port name="IN" side="left" coord="-2.54" direction="io"/>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="ARDUINO_CONTROL" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="POWER_OFF_RELAY" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
<module name="SYSTEM_ON_SW" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
</modules>
<parts>
</parts>
<sheets>
<sheet>
<plain>
<text x="10.16" y="170.18" size="13.0048" layer="91">ManniRaspiRadio</text>
<text x="-78.74" y="106.68" size="1.778" layer="91">Shutdown</text>
<text x="-129.54" y="101.6" size="1.778" layer="91">A0</text>
<text x="-129.54" y="106.68" size="1.778" layer="91">A1</text>
<text x="-132.08" y="22.86" size="1.778" layer="91">D10</text>
<text x="-129.54" y="83.82" size="1.778" layer="91">A3</text>
<text x="-160.02" y="68.58" size="1.778" layer="91" rot="R180">LOAD D7
CLOCK D6
DATA D3</text>
<text x="-154.94" y="121.92" size="1.778" layer="91">D5</text>
<text x="-154.94" y="127" size="1.778" layer="91">D4</text>
<text x="-144.78" y="33.02" size="1.778" layer="91" rot="R90">MOSI/CLOCK</text>
<text x="-129.54" y="55.88" size="1.778" layer="91">A7</text>
<text x="-132.08" y="60.96" size="1.778" layer="91">D8/D9</text>
<text x="-129.54" y="66.04" size="1.778" layer="91">D2</text>
<text x="-129.54" y="50.8" size="1.778" layer="91">A2</text>
<text x="-66.04" y="106.68" size="1.778" layer="91">BCM Pin #26</text>
<text x="-66.04" y="101.6" size="1.778" layer="91">BCM Pin #19</text>
<text x="-86.36" y="101.6" size="1.778" layer="91">Shutdown Ready</text>
</plain>
<moduleinsts>
<moduleinst name="AM-C/F1" module="AM-C/F" x="-154.94" y="167.64"/>
<moduleinst name="FM-C/F1" module="FM-C/F" x="-154.94" y="142.24"/>
<moduleinst name="F-SELECT1" module="F-SELECT" x="-101.6" y="154.94"/>
<moduleinst name="GRAFIC_EQAULIZER1" module="GRAFIC_EQAULIZER" x="38.1" y="106.68"/>
<moduleinst name="AUDIO_SWITCH1" module="AUDIO_SWITCH" x="5.08" y="142.24"/>
<moduleinst name="AMPLIFIER1" module="AMPLIFIER" x="68.58" y="142.24"/>
<moduleinst name="RASPBERRY_PI1" module="RASPBERRY_PI" x="-35.56" y="104.14"/>
<moduleinst name="FM_RADIO1" module="FM_RADIO" x="-35.56" y="165.1"/>
<moduleinst name="KEYBOARD1" module="KEYBOARD" x="-162.56" y="35.56" rot="R90"/>
<moduleinst name="LED_STRIP1" module="LED_STRIP" x="-119.38" y="38.1"/>
<moduleinst name="5V_DC/DC1" module="5V_DC/DC" x="-88.9" y="38.1"/>
<moduleinst name="5V_DC/DC2" module="5V_DC/DC" x="-35.56" y="83.82"/>
<moduleinst name="HDMI_MONITOR1" module="HDMI_MONITOR" x="-35.56" y="124.46" smashed="yes">
<attribute name="NAME" x="-35.56" y="124.46" size="2.032" layer="95" align="bottom-center"/>
</moduleinst>
<moduleinst name="3,3V_LDO1" module="3,3V_LDO" x="-35.56" y="185.42"/>
<moduleinst name="AUDIO_DELAY1" module="AUDIO_DELAY" x="116.84" y="142.24"/>
<moduleinst name="SPEAKER1" module="SPEAKER" x="170.18" y="142.24"/>
<moduleinst name="ARDUINO_CONTROL1" module="ARDUINO_CONTROL" x="-154.94" y="86.36"/>
<moduleinst name="POWER_OFF_RELAY1" module="POWER_OFF_RELAY" x="-50.8" y="38.1"/>
<moduleinst name="SYSTEM_ON_SW1" module="SYSTEM_ON_SW" x="-96.52" y="86.36"/>
</moduleinsts>
<instances>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<portref moduleinst="AM-C/F1" port="OUT"/>
<wire x1="-134.62" y1="162.56" x2="-127" y2="162.56" width="0.1524" layer="91"/>
<wire x1="-127" y1="162.56" x2="-127" y2="160.02" width="0.1524" layer="91"/>
<portref moduleinst="F-SELECT1" port="IN_AM"/>
<wire x1="-127" y1="160.02" x2="-121.92" y2="160.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<portref moduleinst="FM-C/F1" port="OUT"/>
<wire x1="-134.62" y1="147.32" x2="-127" y2="147.32" width="0.1524" layer="91"/>
<wire x1="-127" y1="147.32" x2="-127" y2="149.86" width="0.1524" layer="91"/>
<portref moduleinst="F-SELECT1" port="IN_FM"/>
<wire x1="-127" y1="149.86" x2="-121.92" y2="149.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<portref moduleinst="FM_RADIO1" port="AUDIO"/>
<wire x1="-35.56" y1="149.86" x2="-35.56" y2="147.32" width="0.1524" layer="91"/>
<portref moduleinst="AUDIO_SWITCH1" port="FM_IN"/>
<wire x1="-35.56" y1="147.32" x2="-15.24" y2="147.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<portref moduleinst="HDMI_MONITOR1" port="AUDIO"/>
<portref moduleinst="AUDIO_SWITCH1" port="RASPI_IN"/>
<wire x1="-35.56" y1="139.7" x2="-15.24" y2="139.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<portref moduleinst="AUDIO_SWITCH1" port="OUT"/>
<portref moduleinst="AMPLIFIER1" port="IN"/>
<wire x1="25.4" y1="139.7" x2="35.56" y2="139.7" width="0.1524" layer="91"/>
<portref moduleinst="GRAFIC_EQAULIZER1" port="IN"/>
<wire x1="35.56" y1="139.7" x2="48.26" y2="139.7" width="0.1524" layer="91"/>
<wire x1="35.56" y1="121.92" x2="35.56" y2="139.7" width="0.1524" layer="91"/>
<junction x="35.56" y="139.7"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<portref moduleinst="F-SELECT1" port="SELECT"/>
<wire x1="-81.28" y1="149.86" x2="-78.74" y2="149.86" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="149.86" x2="-78.74" y2="127" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="127" x2="-162.56" y2="127" width="0.1524" layer="91"/>
<wire x1="-162.56" y1="127" x2="-162.56" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<portref moduleinst="F-SELECT1" port="OUT"/>
<wire x1="-81.28" y1="154.94" x2="-73.66" y2="154.94" width="0.1524" layer="91"/>
<wire x1="-73.66" y1="154.94" x2="-73.66" y2="121.92" width="0.1524" layer="91"/>
<wire x1="-73.66" y1="121.92" x2="-160.02" y2="121.92" width="0.1524" layer="91"/>
<wire x1="-160.02" y1="121.92" x2="-160.02" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<wire x1="-160.02" y1="50.8" x2="-160.02" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<wire x1="-134.62" y1="30.48" x2="-147.32" y2="30.48" width="0.1524" layer="91"/>
<wire x1="-147.32" y1="30.48" x2="-147.32" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SDA(A4)" class="0">
<segment>
<wire x1="-50.8" y1="165.1" x2="-68.58" y2="165.1" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="165.1" x2="-68.58" y2="116.84" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="116.84" x2="-157.48" y2="116.84" width="0.1524" layer="91"/>
<wire x1="-157.48" y1="116.84" x2="-157.48" y2="96.52" width="0.1524" layer="91"/>
<label x="-152.4" y="116.84" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<wire x1="-139.7" y1="76.2" x2="-139.7" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-139.7" y1="60.96" x2="7.62" y2="60.96" width="0.1524" layer="91"/>
<wire x1="7.62" y1="60.96" x2="7.62" y2="101.6" width="0.1524" layer="91"/>
<portref moduleinst="GRAFIC_EQAULIZER1" port="CONTROL"/>
<wire x1="7.62" y1="101.6" x2="17.78" y2="101.6" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<portref moduleinst="GRAFIC_EQAULIZER1" port="OUT"/>
<wire x1="38.1" y1="91.44" x2="38.1" y2="55.88" width="0.1524" layer="91"/>
<wire x1="38.1" y1="55.88" x2="-142.24" y2="55.88" width="0.1524" layer="91"/>
<wire x1="-142.24" y1="55.88" x2="-142.24" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<portref moduleinst="AUDIO_DELAY1" port="CONTROL"/>
<wire x1="114.3" y1="127" x2="114.3" y2="50.8" width="0.1524" layer="91"/>
<wire x1="114.3" y1="50.8" x2="-144.78" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="50.8" x2="-144.78" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<portref moduleinst="AMPLIFIER1" port="OUT"/>
<portref moduleinst="AUDIO_DELAY1" port="IN"/>
<wire x1="88.9" y1="139.7" x2="96.52" y2="139.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<portref moduleinst="AUDIO_DELAY1" port="OUT"/>
<portref moduleinst="SPEAKER1" port="IN"/>
<wire x1="137.16" y1="139.7" x2="149.86" y2="139.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<wire x1="-5.08" y1="132.08" x2="-5.08" y2="66.04" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="66.04" x2="-137.16" y2="66.04" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="66.04" x2="-137.16" y2="81.28" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="81.28" x2="-139.7" y2="81.28" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<wire x1="-50.8" y1="106.68" x2="-149.86" y2="106.68" width="0.1524" layer="91"/>
<wire x1="-149.86" y1="106.68" x2="-149.86" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<wire x1="-149.86" y1="76.2" x2="-149.86" y2="22.86" width="0.1524" layer="91"/>
<wire x1="-149.86" y1="22.86" x2="-60.96" y2="22.86" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="22.86" x2="-60.96" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<wire x1="-50.8" y1="101.6" x2="-144.78" y2="101.6" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="101.6" x2="-144.78" y2="96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<wire x1="-139.7" y1="83.82" x2="-111.76" y2="83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SCL(A5)" class="0">
<segment>
<wire x1="-154.94" y1="96.52" x2="-154.94" y2="111.76" width="0.1524" layer="91"/>
<wire x1="-154.94" y1="111.76" x2="-63.5" y2="111.76" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="111.76" x2="-63.5" y2="162.56" width="0.1524" layer="91"/>
<wire x1="-63.5" y1="162.56" x2="-50.8" y2="162.56" width="0.1524" layer="91"/>
<label x="-152.4" y="111.76" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
</compatibility>
</eagle>
