# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Manu\Desktop\github\PSoC-Final-Project\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA.cydsn\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA.cyprj
# Date: Mon, 25 May 2020 14:36:25 GMT
#set_units -time ns
create_clock -name {ADC_DELSIG_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {ADC_DELSIG_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {SPIM_IMU_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 25} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {SPIM_EEPROM_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 25} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {UART_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {ADC_DELSIG_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 189 377} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {PWM_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 241 481} [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {MAIN_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 24000001 48000001} [list [get_pins {ClockBlock/dclk_glb_7}]]
create_generated_clock -name {NOTIFY_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 240001 480001} [list [get_pins {ClockBlock/dclk_glb_5}]]
create_generated_clock -name {BUTTON_CLOCK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 240001 480001} [list [get_pins {ClockBlock/dclk_glb_6}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Manu\Desktop\github\PSoC-Final-Project\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Manu\Desktop\github\PSoC-Final-Project\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA.cydsn\AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA.cyprj
# Date: Mon, 25 May 2020 14:36:09 GMT
