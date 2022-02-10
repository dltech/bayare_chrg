EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PWM regulator for power supply"
Date "2022-02-09"
Rev ""
Comp ""
Comment1 ""
Comment2 "Mikhail Belkin (+79609615427, dltech174@gmail.com)"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM8:STM8S003F3P U2
U 1 1 6203E5F3
P 3350 3250
F 0 "U2" H 3700 4150 50  0000 C CNN
F 1 "STM8S003F3P" V 3350 3300 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 3400 4350 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00024550.pdf" H 3300 2850 50  0001 C CNN
	1    3350 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0101
U 1 1 6204000A
P 3350 2200
F 0 "#PWR0101" H 3350 2050 50  0001 C CNN
F 1 "+3.3V" H 3365 2373 50  0000 C CNN
F 2 "" H 3350 2200 50  0001 C CNN
F 3 "" H 3350 2200 50  0001 C CNN
	1    3350 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 6204066C
P 3350 4300
F 0 "#PWR0102" H 3350 4050 50  0001 C CNN
F 1 "GND" H 3355 4127 50  0000 C CNN
F 2 "" H 3350 4300 50  0001 C CNN
F 3 "" H 3350 4300 50  0001 C CNN
	1    3350 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4300 3350 4250
Wire Wire Line
	3350 2250 3350 2200
Wire Wire Line
	3550 6300 3550 6350
Wire Wire Line
	3300 6300 3550 6300
Wire Wire Line
	3300 5950 3300 6300
Wire Wire Line
	3250 5950 3300 5950
Wire Wire Line
	3350 6050 3350 5950
Wire Wire Line
	3250 6050 3350 6050
Wire Wire Line
	3550 6400 3550 6450
Wire Wire Line
	3350 6400 3550 6400
Wire Wire Line
	3350 6150 3350 6400
Wire Wire Line
	3250 6150 3350 6150
Wire Wire Line
	3400 6250 3400 6050
Wire Wire Line
	3250 6250 3400 6250
Wire Wire Line
	3300 6500 3500 6500
Wire Wire Line
	3500 6500 3500 6250
Wire Wire Line
	3300 6550 3300 6500
Wire Wire Line
	3250 6550 3300 6550
Wire Wire Line
	3400 6350 3400 6550
Wire Wire Line
	3250 6350 3400 6350
Wire Wire Line
	3450 6450 3450 6150
Wire Wire Line
	3250 6450 3450 6450
NoConn ~ 2450 6550
NoConn ~ 2450 6450
NoConn ~ 3250 7050
$Comp
L power:+3.3V #PWR01
U 1 1 5F8299A0
P 2400 7100
F 0 "#PWR01" H 2400 6950 50  0001 C CNN
F 1 "+3.3V" H 2415 7273 50  0000 C CNN
F 2 "" H 2400 7100 50  0001 C CNN
F 3 "" H 2400 7100 50  0001 C CNN
	1    2400 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5F82B8A0
P 1900 7550
F 0 "#PWR02" H 1900 7300 50  0001 C CNN
F 1 "GND" H 1905 7377 50  0000 C CNN
F 2 "" H 1900 7550 50  0001 C CNN
F 3 "" H 1900 7550 50  0001 C CNN
	1    1900 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 7250 2400 7250
Wire Wire Line
	2400 7250 2400 7300
Wire Wire Line
	2450 7150 2400 7150
Wire Wire Line
	2400 7150 2400 7100
NoConn ~ 3250 7150
NoConn ~ 3250 7250
$Comp
L local:TM1637 U1
U 1 1 60F48864
P 2850 6650
F 0 "U1" H 3100 7550 50  0000 C CNN
F 1 "TM1637" V 2800 6800 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 2850 6800 50  0001 C CNN
F 3 "" H 2850 6800 50  0001 C CNN
	1    2850 6650
	1    0    0    -1  
$EndComp
$Comp
L local:LED_3digit D1
U 1 1 6204FB42
P 4500 5300
F 0 "D1" H 4750 5750 60  0000 C CNN
F 1 "LED_3digit" H 4550 5600 60  0000 C CNN
F 2 "pwm_module:FYT-3631" H 4500 5300 60  0001 C CNN
F 3 "" H 4500 5300 60  0001 C CNN
	1    4500 5300
	1    0    0    -1  
$EndComp
$Comp
L local:LED_3digit D2
U 1 1 60F4942E
P 4500 6200
F 0 "D2" H 4700 6650 60  0000 C CNN
F 1 "LED_3digit" H 4550 6500 60  0000 C CNN
F 2 "pwm_module:FYT-3631" H 4500 6200 60  0001 C CNN
F 3 "" H 4500 6200 60  0001 C CNN
	1    4500 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4950 3950 4950
Wire Wire Line
	3950 4950 3950 5850
Wire Wire Line
	3250 5850 3950 5850
Connection ~ 3950 5850
Wire Wire Line
	3950 5850 4000 5850
Wire Wire Line
	4000 5050 3900 5050
Wire Wire Line
	3900 5050 3900 5950
Wire Wire Line
	3350 5950 3900 5950
Wire Wire Line
	4000 5950 3900 5950
Connection ~ 3900 5950
Wire Wire Line
	4000 5150 3850 5150
Wire Wire Line
	3850 5150 3850 6050
Wire Wire Line
	3400 6050 3850 6050
Wire Wire Line
	4000 6050 3850 6050
Connection ~ 3850 6050
Wire Wire Line
	4000 5250 3800 5250
Wire Wire Line
	3800 5250 3800 6150
Wire Wire Line
	3450 6150 3800 6150
Wire Wire Line
	4000 6150 3800 6150
Connection ~ 3800 6150
Wire Wire Line
	4000 5350 3750 5350
Wire Wire Line
	3750 5350 3750 6250
Wire Wire Line
	3500 6250 3750 6250
Connection ~ 3750 6250
Wire Wire Line
	3750 6250 4000 6250
Wire Wire Line
	4000 5450 3700 5450
Wire Wire Line
	3700 5450 3700 6350
Wire Wire Line
	3700 6350 3550 6350
Wire Wire Line
	4000 6350 3700 6350
Connection ~ 3700 6350
Wire Wire Line
	4000 5550 3650 5550
Wire Wire Line
	3650 5550 3650 6450
Wire Wire Line
	3650 6450 3550 6450
Wire Wire Line
	4000 6450 3650 6450
Connection ~ 3650 6450
Wire Wire Line
	3600 6550 3600 5650
Wire Wire Line
	3600 5650 4000 5650
Wire Wire Line
	3400 6550 3600 6550
Wire Wire Line
	4000 6550 3600 6550
Connection ~ 3600 6550
Wire Wire Line
	5000 6200 5100 6200
Wire Wire Line
	5100 6200 5100 6850
Wire Wire Line
	3250 6850 5100 6850
Wire Wire Line
	5050 6950 5050 6300
Wire Wire Line
	5050 6300 5000 6300
Wire Wire Line
	3250 6950 5050 6950
Wire Wire Line
	3250 6750 5150 6750
Wire Wire Line
	5150 6750 5150 6100
Wire Wire Line
	5150 6100 5000 6100
Wire Wire Line
	3250 7050 5300 7050
Wire Wire Line
	3250 7150 5250 7150
Wire Wire Line
	3250 7250 5200 7250
Wire Wire Line
	5200 7250 5200 5400
Wire Wire Line
	5200 5400 5000 5400
Wire Wire Line
	5250 7150 5250 5300
Wire Wire Line
	5250 5300 5000 5300
Wire Wire Line
	5300 7050 5300 5200
Wire Wire Line
	5300 5200 5000 5200
$Comp
L Device:C C2
U 1 1 620958A7
P 2700 4150
F 0 "C2" H 2700 4250 50  0000 L CNN
F 1 "1uF" H 2700 4050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2738 4000 50  0001 C CNN
F 3 "~" H 2700 4150 50  0001 C CNN
	1    2700 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 4000 2700 3950
Wire Wire Line
	2700 3950 2750 3950
$Comp
L power:GND #PWR0103
U 1 1 62098585
P 2700 4300
F 0 "#PWR0103" H 2700 4050 50  0001 C CNN
F 1 "GND" H 2705 4127 50  0000 C CNN
F 2 "" H 2700 4300 50  0001 C CNN
F 3 "" H 2700 4300 50  0001 C CNN
	1    2700 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 62099550
P 2400 4050
F 0 "C1" H 2400 4150 50  0000 L CNN
F 1 "0.1uF" H 2400 3950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2438 3900 50  0001 C CNN
F 3 "~" H 2400 4050 50  0001 C CNN
	1    2400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3850 2400 3850
Wire Wire Line
	2400 3850 2400 3900
$Comp
L power:GND #PWR0104
U 1 1 6209EAAF
P 2400 4300
F 0 "#PWR0104" H 2400 4050 50  0001 C CNN
F 1 "GND" H 2405 4127 50  0000 C CNN
F 2 "" H 2400 4300 50  0001 C CNN
F 3 "" H 2400 4300 50  0001 C CNN
	1    2400 4300
	1    0    0    -1  
$EndComp
$Comp
L local:2N60 Q2
U 1 1 620A7265
P 4850 2700
F 0 "Q2" V 4800 2850 50  0000 C CNN
F 1 "6N60" V 5100 2700 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 5050 2625 50  0001 L CIN
F 3 "" H 4850 2700 50  0001 L CNN
	1    4850 2700
	0    1    -1   0   
$EndComp
$Comp
L local:AO3400 Q1
U 1 1 620ABAF0
P 4450 3250
F 0 "Q1" H 4656 3296 50  0000 L CNN
F 1 "AO3400" H 4656 3205 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4450 3250 50  0001 C CNN
F 3 "" H 4450 3250 50  0001 L CNN
	1    4450 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 620AEA05
P 4550 2800
F 0 "R4" H 4600 2850 50  0000 L CNN
F 1 "100k" V 4550 2700 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4480 2800 50  0001 C CNN
F 3 "~" H 4550 2800 50  0001 C CNN
	1    4550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3050 4550 3000
Connection ~ 4550 3000
Wire Wire Line
	4550 3000 4550 2950
Wire Wire Line
	4250 3250 4200 3250
$Comp
L power:GND #PWR0105
U 1 1 620B76D5
P 4500 4100
F 0 "#PWR0105" H 4500 3850 50  0001 C CNN
F 1 "GND" H 4650 4050 50  0000 C CNN
F 2 "" H 4500 4100 50  0001 C CNN
F 3 "" H 4500 4100 50  0001 C CNN
	1    4500 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3000 4850 3000
$Comp
L Device:R_Potentiometer RV1
U 1 1 620D21AF
P 4500 3950
F 0 "RV1" H 4430 3996 50  0000 R CNN
F 1 "." H 4430 3905 50  0000 R CNN
F 2 "pwm_module:SP3-4" H 4500 3950 50  0001 C CNN
F 3 "~" H 4500 3950 50  0001 C CNN
	1    4500 3950
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Potentiometer RV2
U 1 1 620D31F7
P 4500 4500
F 0 "RV2" H 4430 4546 50  0000 R CNN
F 1 "." H 4430 4455 50  0000 R CNN
F 2 "pwm_module:SP3-4" H 4500 4500 50  0001 C CNN
F 3 "~" H 4500 4500 50  0001 C CNN
	1    4500 4500
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 620D6155
P 2400 2700
F 0 "SW2" H 2250 2800 50  0000 C CNN
F 1 "." H 2550 2750 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2400 2900 50  0001 C CNN
F 3 "~" H 2400 2900 50  0001 C CNN
	1    2400 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 620D9E33
P 4200 3050
F 0 "R1" H 4250 3100 50  0000 L CNN
F 1 "100k" V 4200 2950 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4130 3050 50  0001 C CNN
F 3 "~" H 4200 3050 50  0001 C CNN
	1    4200 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0106
U 1 1 620DC8A4
P 4200 2850
F 0 "#PWR0106" H 4200 2700 50  0001 C CNN
F 1 "+3.3V" H 4215 3023 50  0000 C CNN
F 2 "" H 4200 2850 50  0001 C CNN
F 3 "" H 4200 2850 50  0001 C CNN
	1    4200 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2900 4200 2850
Wire Wire Line
	4200 3250 4200 3200
Connection ~ 4200 3250
Wire Wire Line
	4550 3500 4550 3450
Wire Wire Line
	4550 2600 4550 2650
$Comp
L Amplifier_Operational:LM358 U3
U 1 1 621015EC
P 4800 1050
F 0 "U3" H 4800 850 50  0000 C CNN
F 1 "LM358" H 4750 1050 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 4800 1050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 4800 1050 50  0001 C CNN
	1    4800 1050
	-1   0    0    1   
$EndComp
$Comp
L Amplifier_Operational:LM358 U3
U 2 1 62109DDC
P 4800 1750
F 0 "U3" H 4800 1550 50  0000 C CNN
F 1 "LM358" H 4750 1750 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 4800 1750 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 4800 1750 50  0001 C CNN
	2    4800 1750
	-1   0    0    1   
$EndComp
Wire Wire Line
	5100 950  5150 950 
Wire Wire Line
	5150 950  5150 800 
Wire Wire Line
	5150 800  4450 800 
Wire Wire Line
	4450 800  4450 1050
Wire Wire Line
	4450 1050 4500 1050
Wire Wire Line
	5100 1650 5150 1650
Wire Wire Line
	5150 1650 5150 1500
Wire Wire Line
	5150 1500 4450 1500
Wire Wire Line
	4450 1500 4450 1750
Wire Wire Line
	4450 1750 4500 1750
$Comp
L Device:R R5
U 1 1 62070859
P 5150 2000
F 0 "R5" V 5250 2000 50  0000 L CNN
F 1 "0.1R" V 5150 1900 50  0000 L CNN
F 2 "Resistor_SMD:R_1210_3225Metric" V 5080 2000 50  0001 C CNN
F 3 "~" H 5150 2000 50  0001 C CNN
	1    5150 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 1850 5100 1850
$Comp
L power:GND #PWR0107
U 1 1 6208BD4F
P 5150 2200
F 0 "#PWR0107" H 5150 1950 50  0001 C CNN
F 1 "GND" H 5050 2100 50  0000 C CNN
F 2 "" H 5150 2200 50  0001 C CNN
F 3 "" H 5150 2200 50  0001 C CNN
	1    5150 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 62094413
P 5250 950
F 0 "R6" H 5300 1000 50  0000 L CNN
F 1 "100k" V 5250 850 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5180 950 50  0001 C CNN
F 3 "~" H 5250 950 50  0001 C CNN
	1    5250 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 62095C92
P 5250 1300
F 0 "R7" H 5100 1400 50  0000 L CNN
F 1 "10k" V 5250 1200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5180 1300 50  0001 C CNN
F 3 "~" H 5250 1300 50  0001 C CNN
	1    5250 1300
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L78L33_SOT89 U4
U 1 1 62099343
P 8800 3150
F 0 "U4" H 8950 3300 50  0000 C CNN
F 1 "L78L33" H 8700 3300 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-89-3" H 8800 3350 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/15/55/e5/aa/23/5b/43/fd/CD00000446.pdf/files/CD00000446.pdf/jcr:content/translations/en.CD00000446.pdf" H 8800 3100 50  0001 C CNN
	1    8800 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR0108
U 1 1 620A80C2
P 7700 3100
F 0 "#PWR0108" H 7700 2950 50  0001 C CNN
F 1 "+24V" H 7715 3273 50  0000 C CNN
F 2 "" H 7700 3100 50  0001 C CNN
F 3 "" H 7700 3100 50  0001 C CNN
	1    7700 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 3150 8500 3150
$Comp
L Device:C C7
U 1 1 620AFB1A
P 8250 3300
F 0 "C7" H 8250 3400 50  0000 L CNN
F 1 "10uF" H 8250 3200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8288 3150 50  0001 C CNN
F 3 "~" H 8250 3300 50  0001 C CNN
	1    8250 3300
	1    0    0    -1  
$EndComp
Connection ~ 8450 3150
$Comp
L Device:C C8
U 1 1 620B2675
P 8450 3300
F 0 "C8" H 8450 3400 50  0000 L CNN
F 1 "0.1uF" H 8450 3200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8488 3150 50  0001 C CNN
F 3 "~" H 8450 3300 50  0001 C CNN
	1    8450 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 3150 8250 3150
$Comp
L Device:C C9
U 1 1 620C1410
P 9150 3300
F 0 "C9" H 9150 3400 50  0000 L CNN
F 1 "10uF" H 9150 3200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9188 3150 50  0001 C CNN
F 3 "~" H 9150 3300 50  0001 C CNN
	1    9150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 3150 9150 3150
$Comp
L Device:R R8
U 1 1 620CB81D
P 7900 3150
F 0 "R8" V 8000 3000 50  0000 L CNN
F 1 "10R" V 7900 3050 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7830 3150 50  0001 C CNN
F 3 "~" H 7900 3150 50  0001 C CNN
	1    7900 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	7700 3100 7700 3150
Wire Wire Line
	7700 3150 7750 3150
Wire Wire Line
	8050 3150 8100 3150
Connection ~ 8250 3150
Connection ~ 8100 3150
Wire Wire Line
	8100 3150 8250 3150
$Comp
L power:GND #PWR0109
U 1 1 620E93E4
P 9150 3550
F 0 "#PWR0109" H 9150 3300 50  0001 C CNN
F 1 "GND" H 9155 3377 50  0000 C CNN
F 2 "" H 9150 3550 50  0001 C CNN
F 3 "" H 9150 3550 50  0001 C CNN
	1    9150 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3550 9150 3500
Wire Wire Line
	9150 3500 8800 3500
Wire Wire Line
	8800 3500 8800 3450
Connection ~ 9150 3500
Wire Wire Line
	9150 3500 9150 3450
Wire Wire Line
	8800 3500 8450 3500
Wire Wire Line
	8450 3500 8450 3450
Connection ~ 8800 3500
Wire Wire Line
	8450 3500 8250 3500
Wire Wire Line
	8250 3500 8250 3450
Connection ~ 8450 3500
Wire Wire Line
	8250 3500 8100 3500
Connection ~ 8250 3500
$Comp
L power:+VSW #PWR0110
U 1 1 62135C85
P 5250 750
F 0 "#PWR0110" H 5250 600 50  0001 C CNN
F 1 "+VSW" H 5265 923 50  0000 C CNN
F 2 "" H 5250 750 50  0001 C CNN
F 3 "" H 5250 750 50  0001 C CNN
	1    5250 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 800  5250 750 
Wire Wire Line
	5100 1150 5250 1150
Wire Wire Line
	5250 1150 5250 1100
Connection ~ 5250 1150
$Comp
L power:GND #PWR0111
U 1 1 6215E852
P 5400 1500
F 0 "#PWR0111" H 5400 1250 50  0001 C CNN
F 1 "GND" H 5550 1450 50  0000 C CNN
F 2 "" H 5400 1500 50  0001 C CNN
F 3 "" H 5400 1500 50  0001 C CNN
	1    5400 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1500 5250 1450
$Comp
L power:+VSW #PWR0112
U 1 1 6218088D
P 5100 2550
F 0 "#PWR0112" H 5100 2400 50  0001 C CNN
F 1 "+VSW" H 5100 2700 50  0000 C CNN
F 2 "" H 5100 2550 50  0001 C CNN
F 3 "" H 5100 2550 50  0001 C CNN
	1    5100 2550
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR0113
U 1 1 6218BBB0
P 4550 2550
F 0 "#PWR0113" H 4550 2400 50  0001 C CNN
F 1 "+24V" H 4550 2700 50  0000 C CNN
F 2 "" H 4550 2550 50  0001 C CNN
F 3 "" H 4550 2550 50  0001 C CNN
	1    4550 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2600 4550 2550
Connection ~ 4550 2600
Wire Wire Line
	4650 2600 4550 2600
Wire Wire Line
	4850 2900 4850 3000
Wire Wire Line
	5050 2600 5100 2600
Wire Wire Line
	5100 2600 5100 2550
$Comp
L power:+3.3V #PWR0114
U 1 1 622371EC
P 4500 3800
F 0 "#PWR0114" H 4500 3650 50  0001 C CNN
F 1 "+3.3V" H 4650 3900 50  0000 C CNN
F 2 "" H 4500 3800 50  0001 C CNN
F 3 "" H 4500 3800 50  0001 C CNN
	1    4500 3800
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0115
U 1 1 6223863E
P 4500 4350
F 0 "#PWR0115" H 4500 4200 50  0001 C CNN
F 1 "+3.3V" H 4650 4450 50  0000 C CNN
F 2 "" H 4500 4350 50  0001 C CNN
F 3 "" H 4500 4350 50  0001 C CNN
	1    4500 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 6223B2B1
P 4550 3500
F 0 "#PWR0116" H 4550 3250 50  0001 C CNN
F 1 "GND" H 4650 3400 50  0000 C CNN
F 2 "" H 4550 3500 50  0001 C CNN
F 3 "" H 4550 3500 50  0001 C CNN
	1    4550 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 6223B781
P 4500 4650
F 0 "#PWR0117" H 4500 4400 50  0001 C CNN
F 1 "GND" H 4650 4600 50  0000 C CNN
F 2 "" H 4500 4650 50  0001 C CNN
F 3 "" H 4500 4650 50  0001 C CNN
	1    4500 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3950 4300 3950
Wire Wire Line
	4300 3950 4300 3350
Wire Wire Line
	4300 3350 3950 3350
Wire Wire Line
	3950 3450 4250 3450
Wire Wire Line
	4250 3450 4250 4500
Wire Wire Line
	4250 4500 4350 4500
Wire Wire Line
	4100 3150 3950 3150
Wire Wire Line
	3950 3050 4050 3050
Wire Wire Line
	4400 1050 4450 1050
Connection ~ 4450 1050
Wire Wire Line
	3950 3250 4200 3250
Wire Wire Line
	3950 2950 4000 2950
Wire Wire Line
	4000 2950 4000 1050
$Comp
L Connector_Generic:Conn_01x01 J1
U 1 1 62303B70
P 4000 850
F 0 "J1" V 4050 750 50  0000 R CNN
F 1 "SWIMM" V 3950 750 50  0000 R CNN
F 2 "Connector_Wire:SolderWirePad_1x01_SMD_1x2mm" H 4000 850 50  0001 C CNN
F 3 "~" H 4000 850 50  0001 C CNN
	1    4000 850 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 62318E9B
P 2150 2700
F 0 "#PWR0118" H 2150 2450 50  0001 C CNN
F 1 "GND" H 2150 2550 50  0000 C CNN
F 2 "" H 2150 2700 50  0001 C CNN
F 3 "" H 2150 2700 50  0001 C CNN
	1    2150 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 2700 2200 2700
Wire Wire Line
	2750 2950 2150 2950
NoConn ~ 2750 3650
NoConn ~ 2750 3550
NoConn ~ 2750 3450
NoConn ~ 2750 3350
NoConn ~ 2750 3250
NoConn ~ 2750 2750
$Comp
L Amplifier_Operational:LM358 U3
U 3 1 6236F7BC
P 8100 4500
F 0 "U3" H 8100 4300 50  0000 C CNN
F 1 "LM358" H 8050 4500 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 8100 4500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 8100 4500 50  0001 C CNN
	3    8100 4500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C10
U 1 1 62372378
P 8400 4450
F 0 "C10" H 8400 4550 50  0000 L CNN
F 1 "0.1uF" H 8400 4350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8438 4300 50  0001 C CNN
F 3 "~" H 8400 4450 50  0001 C CNN
	1    8400 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 62378139
P 8600 4450
F 0 "C11" H 8600 4550 50  0000 L CNN
F 1 "0.1uF" H 8600 4350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8638 4300 50  0001 C CNN
F 3 "~" H 8600 4450 50  0001 C CNN
	1    8600 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 6237887D
P 8800 4450
F 0 "C12" H 8800 4550 50  0000 L CNN
F 1 "0.1uF" H 8800 4350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8838 4300 50  0001 C CNN
F 3 "~" H 8800 4450 50  0001 C CNN
	1    8800 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 6237ABFD
P 8200 4850
F 0 "#PWR0119" H 8200 4600 50  0001 C CNN
F 1 "GND" H 8205 4677 50  0000 C CNN
F 2 "" H 8200 4850 50  0001 C CNN
F 3 "" H 8200 4850 50  0001 C CNN
	1    8200 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 6237B4E3
P 8400 4650
F 0 "#PWR0120" H 8400 4400 50  0001 C CNN
F 1 "GND" H 8405 4477 50  0000 C CNN
F 2 "" H 8400 4650 50  0001 C CNN
F 3 "" H 8400 4650 50  0001 C CNN
	1    8400 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 6237BCF9
P 8600 4650
F 0 "#PWR0121" H 8600 4400 50  0001 C CNN
F 1 "GND" H 8605 4477 50  0000 C CNN
F 2 "" H 8600 4650 50  0001 C CNN
F 3 "" H 8600 4650 50  0001 C CNN
	1    8600 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 6237C541
P 8800 4650
F 0 "#PWR0122" H 8800 4400 50  0001 C CNN
F 1 "GND" H 8805 4477 50  0000 C CNN
F 2 "" H 8800 4650 50  0001 C CNN
F 3 "" H 8800 4650 50  0001 C CNN
	1    8800 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0123
U 1 1 623818F4
P 9150 3100
F 0 "#PWR0123" H 9150 2950 50  0001 C CNN
F 1 "+3.3V" H 9165 3273 50  0000 C CNN
F 2 "" H 9150 3100 50  0001 C CNN
F 3 "" H 9150 3100 50  0001 C CNN
	1    9150 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3150 9150 3100
Connection ~ 9150 3150
$Comp
L power:+3.3V #PWR0124
U 1 1 6238BC0F
P 8200 4150
F 0 "#PWR0124" H 8200 4000 50  0001 C CNN
F 1 "+3.3V" H 8215 4323 50  0000 C CNN
F 2 "" H 8200 4150 50  0001 C CNN
F 3 "" H 8200 4150 50  0001 C CNN
	1    8200 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0125
U 1 1 6238CE60
P 8400 4250
F 0 "#PWR0125" H 8400 4100 50  0001 C CNN
F 1 "+3.3V" H 8415 4423 50  0000 C CNN
F 2 "" H 8400 4250 50  0001 C CNN
F 3 "" H 8400 4250 50  0001 C CNN
	1    8400 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0126
U 1 1 6238D309
P 8600 4250
F 0 "#PWR0126" H 8600 4100 50  0001 C CNN
F 1 "+3.3V" H 8615 4423 50  0000 C CNN
F 2 "" H 8600 4250 50  0001 C CNN
F 3 "" H 8600 4250 50  0001 C CNN
	1    8600 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0127
U 1 1 6238E1FE
P 8800 4250
F 0 "#PWR0127" H 8800 4100 50  0001 C CNN
F 1 "+3.3V" H 8815 4423 50  0000 C CNN
F 2 "" H 8800 4250 50  0001 C CNN
F 3 "" H 8800 4250 50  0001 C CNN
	1    8800 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 4300 8800 4250
Wire Wire Line
	8600 4300 8600 4250
Wire Wire Line
	8400 4300 8400 4250
Wire Wire Line
	8200 4200 8200 4150
Wire Wire Line
	8200 4850 8200 4800
Wire Wire Line
	8400 4650 8400 4600
Wire Wire Line
	8600 4650 8600 4600
Wire Wire Line
	8800 4650 8800 4600
$Comp
L Device:D_Schottky_Dual_CommonCathode_AKA D5
U 1 1 6205359E
P 6700 3150
F 0 "D5" H 6850 3250 50  0000 C CNN
F 1 "." H 6700 3276 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 6700 3150 50  0001 C CNN
F 3 "~" H 6700 3150 50  0001 C CNN
	1    6700 3150
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky_Dual_CommonCathode_AKA D6
U 1 1 6207CB2A
P 6900 3150
F 0 "D6" H 7050 3250 50  0000 C CNN
F 1 "." H 6900 3276 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 6900 3150 50  0001 C CNN
F 3 "~" H 6900 3150 50  0001 C CNN
	1    6900 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 2850 6900 2800
Wire Wire Line
	6900 2800 6800 2800
Wire Wire Line
	6700 2800 6700 2850
Wire Wire Line
	6800 2800 6800 3500
Wire Wire Line
	6800 3500 6700 3500
Wire Wire Line
	6700 3500 6700 3450
Connection ~ 6800 2800
Wire Wire Line
	6800 2800 6700 2800
Wire Wire Line
	6800 3500 6900 3500
Wire Wire Line
	6900 3500 6900 3450
Connection ~ 6800 3500
$Comp
L power:GND #PWR0128
U 1 1 620B07FE
P 7400 3550
F 0 "#PWR0128" H 7400 3300 50  0001 C CNN
F 1 "GND" H 7405 3377 50  0000 C CNN
F 2 "" H 7400 3550 50  0001 C CNN
F 3 "" H 7400 3550 50  0001 C CNN
	1    7400 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky_Dual_CommonCathode_AKA D7
U 1 1 62058078
P 7150 2800
F 0 "D7" H 7400 2850 50  0000 C CNN
F 1 "." H 7150 2926 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7150 2800 50  0001 C CNN
F 3 "~" H 7150 2800 50  0001 C CNN
	1    7150 2800
	0    -1   1    0   
$EndComp
Wire Wire Line
	7100 3150 7150 3150
Wire Wire Line
	7150 3150 7150 3100
Wire Wire Line
	7150 2500 7150 2450
Wire Wire Line
	6450 2450 6450 3150
Wire Wire Line
	6450 3150 6500 3150
Connection ~ 6450 2450
Wire Wire Line
	7150 3150 7250 3150
Connection ~ 7150 3150
Wire Wire Line
	7350 2800 7400 2800
Wire Wire Line
	7600 3150 7700 3150
Connection ~ 7700 3150
$Comp
L Device:C_Polarized_US C6
U 1 1 62239E1E
P 7400 3300
F 0 "C6" H 7400 3400 50  0000 L CNN
F 1 "1000uF" H 7100 3200 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 7400 3300 50  0001 C CNN
F 3 "~" H 7400 3300 50  0001 C CNN
	1    7400 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3150 7400 3100
Wire Wire Line
	6900 3500 7400 3500
Wire Wire Line
	7400 3500 7400 3450
Connection ~ 6900 3500
Wire Wire Line
	7400 3550 7400 3500
Connection ~ 7400 3500
Wire Wire Line
	7400 3100 7600 3100
Connection ~ 7400 3100
Wire Wire Line
	7400 3100 7400 2800
Wire Wire Line
	7600 3100 7600 3150
Wire Wire Line
	2150 2500 2200 2500
$Comp
L power:GND #PWR0131
U 1 1 62091DF9
P 2150 2500
F 0 "#PWR0131" H 2150 2250 50  0001 C CNN
F 1 "GND" H 2150 2350 50  0000 C CNN
F 2 "" H 2150 2500 50  0001 C CNN
F 3 "" H 2150 2500 50  0001 C CNN
	1    2150 2500
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 62091DF3
P 2400 2500
F 0 "SW1" H 2250 2600 50  0000 C CNN
F 1 "." H 2550 2550 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2400 2700 50  0001 C CNN
F 3 "~" H 2400 2700 50  0001 C CNN
	1    2400 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2700 2700 2700
Wire Wire Line
	2700 2700 2700 2650
Wire Wire Line
	2700 2650 2750 2650
Wire Wire Line
	2750 2550 2700 2550
Wire Wire Line
	2700 2550 2700 2500
Wire Wire Line
	2700 2500 2600 2500
$Comp
L power:-VSW #PWR0132
U 1 1 6210BE8B
P 5300 1800
F 0 "#PWR0132" H 5300 1900 50  0001 C CNN
F 1 "-VSW" H 5300 1950 50  0000 C CNN
F 2 "" H 5300 1800 50  0001 C CNN
F 3 "" H 5300 1800 50  0001 C CNN
	1    5300 1800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 6210ECC3
P 5700 2350
F 0 "J2" H 5780 2342 50  0000 L CNN
F 1 "output" H 5650 2150 50  0000 L CNN
F 2 "Connector_Wire:SolderWire-1sqmm_1x02_P7.8mm_D1.4mm_OD3.9mm" H 5700 2350 50  0001 C CNN
F 3 "~" H 5700 2350 50  0001 C CNN
	1    5700 2350
	1    0    0    -1  
$EndComp
Connection ~ 5100 2600
$Comp
L Device:C_Polarized_US C5
U 1 1 62166329
P 5100 2950
F 0 "C5" H 5100 3050 50  0000 L CNN
F 1 "1000uF" H 4800 2850 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 5100 2950 50  0001 C CNN
F 3 "~" H 5100 2950 50  0001 C CNN
	1    5100 2950
	1    0    0    -1  
$EndComp
$Comp
L power:-VSW #PWR0133
U 1 1 6218E18F
P 5200 3250
F 0 "#PWR0133" H 5200 3350 50  0001 C CNN
F 1 "-VSW" H 5215 3423 50  0000 C CNN
F 2 "" H 5200 3250 50  0001 C CNN
F 3 "" H 5200 3250 50  0001 C CNN
	1    5200 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3100 5100 3300
Wire Wire Line
	5100 3300 5200 3300
Wire Wire Line
	5200 3300 5200 3250
Wire Wire Line
	5100 2800 5100 2600
$Comp
L Device:R R2
U 1 1 621C777D
P 4250 1050
F 0 "R2" V 4350 1050 50  0000 L CNN
F 1 "75" V 4250 950 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4180 1050 50  0001 C CNN
F 3 "~" H 4250 1050 50  0001 C CNN
	1    4250 1050
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 621F5FD6
P 4300 1750
F 0 "R3" V 4400 1750 50  0000 L CNN
F 1 "75" V 4300 1650 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4230 1750 50  0001 C CNN
F 3 "~" H 4300 1750 50  0001 C CNN
	1    4300 1750
	0    1    1    0   
$EndComp
Connection ~ 4450 1750
$Comp
L Diode:BZX84Cxx D4
U 1 1 6223D827
P 5400 1300
F 0 "D4" V 5354 1380 50  0000 L CNN
F 1 "BZX84C5V6" V 5445 1380 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5400 1125 50  0001 C CNN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bzx84c2v4.pdf" H 5400 1300 50  0001 C CNN
	1    5400 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 1150 5250 1150
Wire Wire Line
	5400 1450 5400 1500
Wire Wire Line
	5250 1500 5400 1500
Connection ~ 5400 1500
$Comp
L Diode:BZX84Cxx D3
U 1 1 622739ED
P 5300 2000
F 0 "D3" V 5200 1900 50  0000 L CNN
F 1 "BZX84C5V6" H 5150 2100 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5300 1825 50  0001 C CNN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bzx84c2v4.pdf" H 5300 2000 50  0001 C CNN
	1    5300 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 1850 5300 1850
Connection ~ 5150 1850
Wire Wire Line
	5150 2150 5150 2200
Wire Wire Line
	5300 2150 5300 2200
Wire Wire Line
	5300 2200 5150 2200
Connection ~ 5150 2200
Wire Wire Line
	5300 1850 5450 1850
Wire Wire Line
	5450 1850 5450 2350
Wire Wire Line
	5450 2350 5500 2350
Connection ~ 5300 1850
Wire Wire Line
	5450 2600 5450 2450
Wire Wire Line
	5100 2600 5450 2600
Wire Wire Line
	5450 2450 5500 2450
Wire Wire Line
	4050 1050 4100 1050
Wire Wire Line
	4100 1750 4150 1750
Wire Wire Line
	4100 1750 4100 3150
$Comp
L Device:C C4
U 1 1 623E1443
P 4450 1950
F 0 "C4" H 4450 2050 50  0000 L CNN
F 1 "0.1uF" H 4450 1850 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4488 1800 50  0001 C CNN
F 3 "~" H 4450 1950 50  0001 C CNN
	1    4450 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 623E2AC5
P 4450 2150
F 0 "#PWR0134" H 4450 1900 50  0001 C CNN
F 1 "GND" H 4350 2050 50  0000 C CNN
F 2 "" H 4450 2150 50  0001 C CNN
F 3 "" H 4450 2150 50  0001 C CNN
	1    4450 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2150 4450 2100
Wire Wire Line
	4450 1800 4450 1750
$Comp
L Device:C C3
U 1 1 6244EDB1
P 4450 1200
F 0 "C3" H 4450 1300 50  0000 L CNN
F 1 "0.1uF" H 4450 1100 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4488 1050 50  0001 C CNN
F 3 "~" H 4450 1200 50  0001 C CNN
	1    4450 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 6244F748
P 4450 1350
F 0 "#PWR0135" H 4450 1100 50  0001 C CNN
F 1 "GND" H 4350 1250 50  0000 C CNN
F 2 "" H 4450 1350 50  0001 C CNN
F 3 "" H 4450 1350 50  0001 C CNN
	1    4450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1050 4050 3050
Wire Wire Line
	5300 1850 5300 1800
Wire Wire Line
	2400 4300 2400 4200
Wire Wire Line
	2150 6050 2150 2950
Wire Wire Line
	2150 6050 2450 6050
Wire Wire Line
	2200 5950 2200 3050
Wire Wire Line
	2200 5950 2450 5950
Wire Wire Line
	2200 3050 2750 3050
Wire Wire Line
	6300 2450 6450 2450
Wire Wire Line
	7150 2450 6450 2450
Wire Wire Line
	6450 2300 6450 2450
Wire Wire Line
	7250 2350 7250 3150
Connection ~ 7250 2350
Wire Wire Line
	6300 2350 7250 2350
Wire Wire Line
	7250 2300 7250 2350
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 625A841D
P 6100 2450
F 0 "J3" H 6180 2442 50  0000 L CNN
F 1 "input" H 6050 2550 50  0000 L CNN
F 2 "Connector_Wire:SolderWire-1sqmm_1x02_P7.8mm_D1.4mm_OD3.9mm" H 6100 2450 50  0001 C CNN
F 3 "~" H 6100 2450 50  0001 C CNN
	1    6100 2450
	-1   0    0    1   
$EndComp
$Comp
L power:AC #PWR0130
U 1 1 6218102B
P 7250 2300
F 0 "#PWR0130" H 7250 2200 50  0001 C CNN
F 1 "AC" H 7250 2575 50  0000 C CNN
F 2 "" H 7250 2300 50  0001 C CNN
F 3 "" H 7250 2300 50  0001 C CNN
	1    7250 2300
	1    0    0    -1  
$EndComp
$Comp
L power:AC #PWR0129
U 1 1 62180829
P 6450 2300
F 0 "#PWR0129" H 6450 2200 50  0001 C CNN
F 1 "AC" H 6450 2575 50  0000 C CNN
F 2 "" H 6450 2300 50  0001 C CNN
F 3 "" H 6450 2300 50  0001 C CNN
	1    6450 2300
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D8
U 1 1 6207886C
P 8100 3300
F 0 "D8" V 8000 3200 50  0000 L CNN
F 1 "PESD1CAN" H 8050 3200 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8100 3125 50  0001 C CNN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bzx84c2v4.pdf" H 8100 3300 50  0001 C CNN
	1    8100 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	8100 3500 8100 3450
$EndSCHEMATC
