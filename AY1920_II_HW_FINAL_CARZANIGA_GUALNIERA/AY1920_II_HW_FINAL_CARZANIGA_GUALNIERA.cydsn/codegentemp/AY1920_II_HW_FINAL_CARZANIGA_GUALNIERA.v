// ======================================================================
// AY1920_II_HW_FINAL_CARZANIGA_GUALNIERA.v generated from TopDesign.cysch
// 05/22/2020 at 11:38
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC5LP 2
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 3
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_TMA4 4
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 5
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC6ABLE2 6
`define CYDEV_CHIP_REV_PSOC6ABLE2_ES 17
`define CYDEV_CHIP_REV_PSOC6ABLE2_PRODUCTION 33
`define CYDEV_CHIP_REV_PSOC6ABLE2_NO_UDB 33
`define CYDEV_CHIP_DIE_VOLANS 7
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 8
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 9
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 10
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 11
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 15
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 16
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 17
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 18
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 19
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 20
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 21
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 22
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 23
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 24
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 25
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 26
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 27
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 28
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 29
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 30
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 31
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 32
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 33
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 35
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 36
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 0
// Component: Debouncer_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0\Debouncer_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Debouncer_v1_0\Debouncer_v1_0.v"
`endif

// Component: B_PWM_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=false, Compare1_8=false, Compare2_16=false, Compare2_8=true, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=127, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=false, Period=255, PWMMode=1, PWMModeCenterAligned=0, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=true, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=true, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=false, TermVisibility_pwm1=true, TermVisibility_pwm2=true, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=false, UDB8=true, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=PWM_v3_30, CY_CONFIG_TITLE=PWM_RG, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_RG, CY_INSTANCE_SHORT_NAME=PWM_RG, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=PWM_RG, )
module PWM_v3_30_0 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 8;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v3_30 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 1;
    defparam PWMUDB.Resolution = 8;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 1;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=false, Compare1_8=true, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=127, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=255, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=true, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=true, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=false, UDB8=true, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=PWM_v3_30, CY_CONFIG_TITLE=PWM_B, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_B, CY_INSTANCE_SHORT_NAME=PWM_B, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=PWM_B, )
module PWM_v3_30_1 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 8;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v3_30 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 8;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 1;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: B_UART_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`endif

// UART_v2_50(Address1=0, Address2=0, BaudRate=115200, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=true, InternalClock=true, InternalClockToleranceMinus=3.93736842105263, InternalClockTolerancePlus=3.93736842105263, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=0, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=false, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=921600, RXAddressMode=0, RXBufferSize=4, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=4, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=UART_v2_50, CY_CONFIG_TITLE=UART, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=UART, )
module UART_v2_50_2 (
    cts_n,
    tx,
    rts_n,
    tx_en,
    clock,
    reset,
    rx,
    tx_interrupt,
    rx_interrupt,
    tx_data,
    tx_clk,
    rx_data,
    rx_clk);
    input       cts_n;
    output      tx;
    output      rts_n;
    output      tx_en;
    input       clock;
    input       reset;
    input       rx;
    output      tx_interrupt;
    output      rx_interrupt;
    output      tx_data;
    output      tx_clk;
    output      rx_data;
    output      rx_clk;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 1;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("1085069444.44444"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_50 BUART (
        .cts_n(cts_n),
        .tx(tx),
        .rts_n(rts_n),
        .tx_en(tx_en),
        .clock(Net_61),
        .reset(reset),
        .rx(rx),
        .tx_interrupt(tx_interrupt),
        .rx_interrupt(rx_interrupt),
        .tx_data(tx_data),
        .tx_clk(tx_clk),
        .rx_data(rx_data),
        .rx_clk(rx_clk));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 1;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 0;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 1;



endmodule

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Timer_v2_80(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeviceFamily=PSoC5, EnableMode=2, FF16=false, FF8=true, FixedFunction=true, FixedFunctionUsed=1, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=true, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=1, NumberOfCaptures=1, param45=1, Period=199, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=rstSts, RunMode=1, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=1, VerilogSectionReplacementString=sT8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Timer_v2_80, CY_CONFIG_TITLE=BUTTON_TIMER, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=BUTTON_TIMER, CY_INSTANCE_SHORT_NAME=BUTTON_TIMER, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=80, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=BUTTON_TIMER, )
module Timer_v2_80_3 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 1;
    parameter Resolution = 8;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    cy_psoc3_timer_v1_0 TimerHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_266),
        .kill(Net_260),
        .clock(clock),
        .tc(Net_51),
        .compare(Net_261),
        .interrupt(Net_57));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_57;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_51;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = enable;



endmodule

// Component: B_SPI_Master_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50\B_SPI_Master_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50\B_SPI_Master_v2_50.v"
`endif

// SPI_Master_v2_50(BidirectMode=false, ClockInternal=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DesiredBitRate=1000000, HighSpeedMode=false, InternalClockUsed=1, InternalInterruptEnabled=0, InternalRxInterruptEnabled=1, InternalTxInterruptEnabled=1, InterruptOnByteComplete=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=true, InterruptOnRXOverrun=false, InterruptOnSPIDone=false, InterruptOnSPIIdle=false, InterruptOnTXEmpty=false, InterruptOnTXNotFull=true, IntOnByteComp=0, IntOnRXFull=0, IntOnRXNotEmpty=1, IntOnRXOver=0, IntOnSPIDone=0, IntOnSPIIdle=0, IntOnTXEmpty=0, IntOnTXNotFull=1, Mode=4, ModeUseZero=0, NumberOfDataBits=8, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, RxBufferSize=8, ShiftDir=0, TxBufferSize=8, UseInternalInterrupt=false, UseRxInternalInterrupt=true, UseTxInternalInterrupt=true, VerilogSectionReplacementString=sR8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SPI_Master_v2_50, CY_CONFIG_TITLE=SPIM, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SPIM, CY_INSTANCE_SHORT_NAME=SPIM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=SPIM, )
module SPI_Master_v2_50_4 (
    mosi,
    sclk,
    ss,
    miso,
    clock,
    reset,
    rx_interrupt,
    sdat,
    tx_interrupt);
    output      mosi;
    output      sclk;
    output      ss;
    input       miso;
    input       clock;
    input       reset;
    output      rx_interrupt;
    inout       sdat;
    output      tx_interrupt;

    parameter BidirectMode = 0;
    parameter HighSpeedMode = 0;
    parameter NumberOfDataBits = 8;
    parameter ShiftDir = 0;

          wire  Net_289;
          wire  Net_257;
          wire  Net_288;
          wire  Net_294;
          wire  Net_161;
          wire  Net_244;
          wire  Net_273;
          wire  Net_276;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_276 = Net_288;


	cy_clock_v1_0
		#(.id("15cb15b3-05f2-49b1-a67e-9f121bc62871/426fcbe0-714d-4404-8fa8-581ff40c30f1"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("500000000"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_288));



	cy_isr_v1_0
		#(.int_type(2'b10))
		RxInternalInterrupt
		 (.int_signal(rx_interrupt));


    B_SPI_Master_v2_50 BSPIM (
        .sclk(sclk),
        .ss(ss),
        .miso(Net_244),
        .clock(Net_276),
        .reset(Net_273),
        .rx_interpt(rx_interrupt),
        .tx_enable(Net_294),
        .mosi(mosi),
        .tx_interpt(tx_interrupt));
    defparam BSPIM.BidirectMode = 0;
    defparam BSPIM.HighSpeedMode = 0;
    defparam BSPIM.ModeCPHA = 1;
    defparam BSPIM.ModePOL = 1;
    defparam BSPIM.NumberOfDataBits = 8;
    defparam BSPIM.ShiftDir = 0;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_244 = miso;


	cy_isr_v1_0
		#(.int_type(2'b10))
		TxInternalInterrupt
		 (.int_signal(tx_interrupt));


	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_273 = Net_289;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_289));



endmodule

// Timer_v2_80(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeviceFamily=PSoC5, EnableMode=0, FF16=false, FF8=true, FixedFunction=true, FixedFunctionUsed=1, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=true, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=1, NumberOfCaptures=1, param45=1, Period=9, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=rstSts, RunMode=0, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=0, VerilogSectionReplacementString=sT8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Timer_v2_80, CY_CONFIG_TITLE=NOTIFY_TIMER, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=NOTIFY_TIMER, CY_INSTANCE_SHORT_NAME=NOTIFY_TIMER, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=80, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=NOTIFY_TIMER, )
module Timer_v2_80_5 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 1;
    parameter Resolution = 8;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    cy_psoc3_timer_v1_0 TimerHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_266),
        .kill(Net_260),
        .clock(clock),
        .tc(Net_51),
        .compare(Net_261),
        .interrupt(Net_57));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_57;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_51;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// top
module top ;

          wire  Net_18560;
          wire  Net_18027;
          wire  Net_18026;
          wire  Net_18025;
          wire  Net_18024;
          wire  Net_17904;
          wire  Net_18127;
          wire  Net_17342;
          wire  Net_17341;
          wire  Net_17340;
          wire  Net_17339;
          wire  Net_17338;
          wire  Net_17337;
    electrical  Net_18556;
    electrical  Net_18555;
    electrical  Net_18554;
    electrical  Net_18553;
    electrical  Net_18552;
    electrical [1:0] Net_18551;
    electrical  Net_18550;
    electrical  Net_18549;
    electrical  Net_18548;
    electrical  Net_18547;
    electrical  Net_18546;
    electrical  Net_18545;
    electrical  Net_18544;
    electrical  Net_18543;
    electrical  Net_18542;
    electrical  Net_18541;
    electrical  Net_18540;
    electrical  Net_18539;
    electrical  Net_18538;
    electrical  Net_18536;
    electrical  Net_18535;
    electrical  Net_18534;
    electrical  Net_18533;
    electrical  Net_18532;
    electrical  Net_18531;
    electrical  Net_18530;
    electrical  Net_18529;
    electrical  Net_18528;
    electrical  Net_18527;
    electrical  Net_18526;
    electrical  Net_18525;
    electrical  Net_18524;
    electrical  Net_18523;
    electrical  Net_18522;
    electrical  Net_18521;
    electrical  Net_18520;
    electrical  Net_18519;
    electrical  Net_18518;
    electrical  Net_18517;
    electrical  Net_18516;
    electrical  Net_18515;
    electrical  Net_18514;
    electrical  Net_18513;
    electrical  Net_18512;
    electrical  Net_18511;
    electrical  Net_18510;
    electrical  Net_18509;
    electrical  Net_18508;
    electrical  Net_18507;
    electrical  Net_18506;
    electrical  Net_18505;
    electrical  Net_18504;
    electrical  Net_18503;
          wire  Net_17682;
          wire  Net_17681;
          wire  Net_17680;
          wire  Net_17811;
          wire  Net_10177;
          wire  Net_10176;
          wire  Net_10175;
          wire  Net_10174;
          wire  Net_10173;
          wire  Net_10172;
          wire  Net_10171;
          wire  Net_10170;
          wire  Net_10169;
          wire  Net_10168;
          wire  Net_10167;
          wire  Net_10166;
    electrical  Net_18502;
    electrical  Net_18501;
    electrical  Net_18500;
    electrical  Net_18499;
    electrical  Net_18498;
    electrical [1:0] Net_18497;
    electrical  Net_18496;
    electrical  Net_18495;
    electrical  Net_18494;
    electrical  Net_18493;
    electrical  Net_18492;
    electrical  Net_18491;
    electrical  Net_18490;
    electrical  Net_18489;
    electrical  Net_18488;
    electrical  Net_18487;
    electrical  Net_18486;
    electrical  Net_18485;
    electrical  Net_18484;
    electrical  Net_18483;
    electrical  Net_18482;
    electrical  Net_18481;
    electrical  Net_18480;
    electrical  Net_18479;
    electrical  Net_18478;
    electrical  Net_18477;
    electrical  Net_18476;
    electrical  Net_18475;
    electrical  Net_18474;
    electrical  Net_18473;
    electrical  Net_18472;
    electrical  Net_18471;
    electrical  Net_18470;
    electrical  Net_18469;
    electrical  Net_18468;
    electrical  Net_18467;
    electrical  Net_18466;
    electrical  Net_18465;
    electrical  Net_18464;
    electrical  Net_18463;
    electrical  Net_18462;
    electrical  Net_18461;
    electrical  Net_18460;
    electrical  Net_18459;
    electrical  Net_18458;
    electrical  Net_18457;
    electrical  Net_18456;
    electrical  Net_18455;
    electrical  Net_18454;
    electrical  Net_18453;
    electrical  Net_18452;
    electrical  Net_18451;
    electrical  Net_18450;
    electrical  Net_18449;
    electrical  Net_18448;
    electrical  Net_18447;
    electrical  Net_453;
    electrical  Net_3543;
    electrical  Net_138;
    electrical  Net_18446;
    electrical  Net_18445;
    electrical  Net_18444;
    electrical  Net_18443;
    electrical  Net_18442;
    electrical [1:0] Net_18441;
    electrical  Net_18440;
    electrical  Net_18439;
    electrical  Net_18438;
    electrical  Net_18437;
    electrical  Net_18436;
    electrical  Net_18435;
    electrical  Net_18434;
    electrical  Net_18433;
    electrical  Net_18432;
    electrical  Net_18431;
    electrical  Net_18430;
    electrical  Net_18429;
    electrical  Net_18428;
    electrical  Net_18427;
    electrical  Net_18426;
    electrical  Net_18425;
    electrical  Net_18424;
    electrical  Net_18423;
    electrical  Net_18422;
    electrical  Net_18421;
    electrical  Net_18420;
    electrical  Net_18419;
    electrical  Net_18418;
    electrical  Net_18417;
    electrical  Net_18416;
    electrical  Net_18415;
    electrical  Net_18414;
    electrical  Net_18413;
    electrical  Net_18412;
    electrical  Net_18411;
    electrical  Net_18410;
    electrical  Net_18409;
    electrical  Net_18408;
    electrical  Net_18407;
    electrical  Net_18406;
    electrical  Net_18405;
    electrical  Net_18404;
    electrical  Net_18403;
    electrical  Net_18402;
    electrical  Net_18401;
    electrical  Net_18400;
    electrical  Net_18399;
    electrical  Net_18398;
    electrical  Net_18397;
    electrical  Net_18396;
    electrical  Net_18395;
    electrical  Net_18394;
    electrical  Net_18393;
    electrical  Net_667;
    electrical  Net_140;
          wire  Net_17115;
          wire  Net_17114;
          wire  Net_17113;
          wire  Net_17112;
          wire  Net_17111;
          wire  Net_17110;
          wire  Net_17109;
          wire  Net_17108;
          wire  Net_17107;
          wire  Net_17106;
          wire  Net_17105;
          wire  Net_18335;
          wire  Net_18334;
          wire  Net_18333;
          wire  Net_18332;
          wire  Net_18331;
          wire  Net_18330;
          wire  Net_18329;
          wire  Net_18328;
          wire  Net_18327;
          wire  Net_18326;
          wire  Net_562;
          wire  Net_18125;
          wire  Net_18124;
          wire  Net_18117;
    electrical  Net_18392;
    electrical  Net_18391;
    electrical  Net_18390;
    electrical  Net_18389;
    electrical  Net_18388;
    electrical [1:0] Net_18387;
    electrical  Net_18386;
    electrical  Net_18385;
    electrical  Net_18384;
    electrical  Net_18383;
    electrical  Net_18382;
    electrical  Net_18381;
    electrical  Net_18380;
    electrical  Net_18379;
    electrical  Net_18378;
    electrical  Net_18377;
    electrical  Net_18376;
    electrical  Net_18375;
    electrical  Net_18374;
    electrical  Net_18373;
    electrical  Net_18372;
    electrical  Net_18371;
    electrical  Net_18370;
    electrical  Net_18369;
    electrical  Net_18368;
    electrical  Net_18367;
    electrical  Net_18366;
    electrical  Net_18365;
    electrical  Net_18364;
    electrical  Net_18363;
    electrical  Net_18362;
    electrical  Net_18361;
    electrical  Net_18360;
    electrical  Net_18359;
    electrical  Net_18358;
    electrical  Net_18357;
    electrical  Net_18356;
    electrical  Net_18355;
    electrical  Net_18354;
    electrical  Net_18353;
    electrical  Net_18352;
    electrical  Net_18351;
    electrical  Net_18350;
    electrical  Net_18349;
    electrical  Net_18348;
    electrical  Net_18347;
    electrical  Net_18346;
    electrical  Net_18345;
    electrical  Net_18344;
    electrical  Net_18343;
    electrical  Net_18342;
    electrical  Net_18341;
    electrical  Net_18340;
    electrical  Net_18339;
    electrical  Net_18338;
    electrical  Net_18337;
    electrical  Net_18336;
    electrical  Net_18537;
          wire  Net_18163;
          wire  Net_18162;
          wire  Net_17093;
          wire  Net_18164;
          wire  Net_17104;
    electrical  Net_17870;
          wire  Net_18120;
          wire  Net_17679;
          wire  Net_17683;
          wire  Net_18028;
    electrical  Net_18112;
    electrical  Net_7443;
          wire  Net_17855;
          wire  Net_17852;
          wire  Net_18158;
    electrical  Net_191;
    electrical  Net_17268;
    electrical  Net_117;
    electrical  Net_116;
    electrical  Net_184;
          wire  Net_25;
          wire  Net_19;
          wire  Net_23;
    electrical  Net_10073;
          wire  Net_9807;
    electrical  Net_123;
    electrical  Net_18048;
    electrical  Net_18047;
    electrical  Net_18049;
          wire  Net_2111;

    cy_annotation_universal_v1_0 KIT_059_1 (
        .connect({
            Net_18336,
            Net_18337,
            Net_18338,
            Net_18339,
            Net_18340,
            Net_18341,
            Net_18342,
            Net_18343,
            Net_18384,
            Net_18383,
            Net_18382,
            Net_18369,
            Net_18370,
            Net_18371,
            Net_18372,
            Net_18373,
            Net_18374,
            Net_18375,
            Net_18376,
            Net_18381,
            Net_18380,
            Net_18379,
            Net_18344,
            Net_18345,
            Net_18346,
            Net_18347,
            Net_18348,
            Net_18349,
            Net_18378,
            Net_18377,
            Net_18368,
            Net_18367,
            Net_17870,
            Net_18366,
            Net_18365,
            Net_18364,
            Net_18363,
            Net_18362,
            Net_18350,
            Net_18351,
            Net_18352,
            Net_18353,
            Net_18354,
            Net_18355,
            Net_18356,
            Net_18357,
            Net_18388,
            Net_18389,
            Net_18390,
            Net_18391,
            Net_18392,
            Net_18360,
            Net_18386,
            Net_18358,
            Net_18359,
            Net_18361,
            Net_18385,
            Net_18387[1:0]
        })
    );
    defparam KIT_059_1.comp_name = "KIT_059_v1_0";
    defparam KIT_059_1.port_names = "P_00, P_01, P_02, P_03, P_04, P_05, P_06, P_07, P_10, P_11, P_12, P_120, P_121, P_122, P_123, P_124, P_125, P_126, P_127, P_13, P_14, P_15, P_150, P_151, P_152, P_153, P_154, P_155, P_16, P_17, P_20, P_21, P_22, P_23, P_24, P_25, P_26, P_27, P_30, P_31, P_32, P_33, P_34, P_35, P_36, P_37, P_59, P_60, P_61, P_62, P_63, P_GND_0, P_GND_1, P_GND_3, P_RST_0, P_VDD_0, P_VDDIO, USB_1_1, USB_1_0";
    defparam KIT_059_1.width = 59;


	cy_clock_v1_0
		#(.id("f352711a-bcd5-4347-a3f7-46c8a71310e7"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		BUTTON_CLOCK
		 (.clock_out(Net_18158));


    Debouncer_v1_0 DEBOUNCER (
        .d(Net_18120),
        .clock(Net_18158),
        .q(Net_17852),
        .neg(Net_18124),
        .either(Net_18125),
        .pos(Net_17679));
    defparam DEBOUNCER.EitherEdgeDetect = 0;
    defparam DEBOUNCER.NegEdgeDetect = 0;
    defparam DEBOUNCER.PosEdgeDetect = 1;
    defparam DEBOUNCER.SignalWidth = 1;


	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_CONFIG
		 (.int_signal(Net_17683));



	cy_clock_v1_0
		#(.id("7ec52678-bf3a-4e40-936f-cd1e471837ac"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000"),
		  .is_direct(0),
		  .is_digital(1))
		PWM_CLOCK
		 (.clock_out(Net_18164));


    PWM_v3_30_0 PWM_RG (
        .reset(Net_17093),
        .clock(Net_18164),
        .tc(Net_18326),
        .pwm1(Net_18162),
        .pwm2(Net_18163),
        .interrupt(Net_18327),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_18333),
        .ph1(Net_18334),
        .ph2(Net_18335));
    defparam PWM_RG.Resolution = 8;

    PWM_v3_30_1 PWM_B (
        .reset(Net_17104),
        .clock(Net_18164),
        .tc(Net_17105),
        .pwm1(Net_17106),
        .pwm2(Net_17107),
        .interrupt(Net_17108),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_2111),
        .ph1(Net_17114),
        .ph2(Net_17115));
    defparam PWM_B.Resolution = 8;

    cy_annotation_universal_v1_0 R_3 (
        .connect({
            Net_140,
            Net_667
        })
    );
    defparam R_3.comp_name = "Resistor_v1_0";
    defparam R_3.port_names = "T1, T2";
    defparam R_3.width = 2;

    cy_annotation_universal_v1_0 KIT_059_2 (
        .connect({
            Net_18393,
            Net_18394,
            Net_18395,
            Net_18396,
            Net_18397,
            Net_18398,
            Net_18399,
            Net_18400,
            Net_18438,
            Net_18437,
            Net_18436,
            Net_18423,
            Net_18424,
            Net_18425,
            Net_18426,
            Net_18427,
            Net_18428,
            Net_18429,
            Net_18430,
            Net_18435,
            Net_18434,
            Net_18433,
            Net_18401,
            Net_18402,
            Net_18403,
            Net_18404,
            Net_18405,
            Net_18406,
            Net_18432,
            Net_18431,
            Net_18422,
            Net_18112,
            Net_18421,
            Net_18420,
            Net_18419,
            Net_18418,
            Net_18417,
            Net_18416,
            Net_18407,
            Net_18408,
            Net_18409,
            Net_18410,
            Net_18411,
            Net_18047,
            Net_18048,
            Net_18049,
            Net_18442,
            Net_18443,
            Net_18444,
            Net_18445,
            Net_18446,
            Net_18414,
            Net_18440,
            Net_18412,
            Net_18413,
            Net_18415,
            Net_18439,
            Net_18441[1:0]
        })
    );
    defparam KIT_059_2.comp_name = "KIT_059_v1_0";
    defparam KIT_059_2.port_names = "P_00, P_01, P_02, P_03, P_04, P_05, P_06, P_07, P_10, P_11, P_12, P_120, P_121, P_122, P_123, P_124, P_125, P_126, P_127, P_13, P_14, P_15, P_150, P_151, P_152, P_153, P_154, P_155, P_16, P_17, P_20, P_21, P_22, P_23, P_24, P_25, P_26, P_27, P_30, P_31, P_32, P_33, P_34, P_35, P_36, P_37, P_59, P_60, P_61, P_62, P_63, P_GND_0, P_GND_1, P_GND_3, P_RST_0, P_VDD_0, P_VDDIO, USB_1_1, USB_1_0";
    defparam KIT_059_2.width = 59;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_138,
            Net_3543
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_123,
            Net_453
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 RED (
        .connect({
            Net_18047,
            Net_140
        })
    );
    defparam RED.comp_name = "LED_v1_0";
    defparam RED.port_names = "A, K";
    defparam RED.width = 2;

	wire [0:0] tmpOE__GREEN_PIN_net;
	wire [0:0] tmpFB_0__GREEN_PIN_net;
	wire [0:0] tmpIO_0__GREEN_PIN_net;
	wire [0:0] tmpINTERRUPT_0__GREEN_PIN_net;
	electrical [0:0] tmpSIOVREF__GREEN_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("98012a64-82d4-425a-8ac5-6703c96dc3d9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		GREEN_PIN
		 (.oe(tmpOE__GREEN_PIN_net),
		  .y({Net_18163}),
		  .fb({tmpFB_0__GREEN_PIN_net[0:0]}),
		  .io({tmpIO_0__GREEN_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__GREEN_PIN_net),
		  .interrupt({tmpINTERRUPT_0__GREEN_PIN_net[0:0]}),
		  .annotation({Net_18048}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__GREEN_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GREEN (
        .connect({
            Net_18048,
            Net_138
        })
    );
    defparam GREEN.comp_name = "LED_v1_0";
    defparam GREEN.port_names = "A, K";
    defparam GREEN.width = 2;

    cy_annotation_universal_v1_0 BLUE (
        .connect({
            Net_18049,
            Net_123
        })
    );
    defparam BLUE.comp_name = "LED_v1_0";
    defparam BLUE.port_names = "A, K";
    defparam BLUE.width = 2;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_3543
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

	wire [0:0] tmpOE__RED_PIN_net;
	wire [0:0] tmpFB_0__RED_PIN_net;
	wire [0:0] tmpIO_0__RED_PIN_net;
	wire [0:0] tmpINTERRUPT_0__RED_PIN_net;
	electrical [0:0] tmpSIOVREF__RED_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		RED_PIN
		 (.oe(tmpOE__RED_PIN_net),
		  .y({Net_18162}),
		  .fb({tmpFB_0__RED_PIN_net[0:0]}),
		  .io({tmpIO_0__RED_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__RED_PIN_net),
		  .interrupt({tmpINTERRUPT_0__RED_PIN_net[0:0]}),
		  .annotation({Net_18047}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RED_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_667
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

	wire [0:0] tmpOE__BLUE_PIN_net;
	wire [0:0] tmpFB_0__BLUE_PIN_net;
	wire [0:0] tmpIO_0__BLUE_PIN_net;
	wire [0:0] tmpINTERRUPT_0__BLUE_PIN_net;
	electrical [0:0] tmpSIOVREF__BLUE_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("b8a23720-2d2c-4d66-ac61-d3fcd0077017"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BLUE_PIN
		 (.oe(tmpOE__BLUE_PIN_net),
		  .y({Net_2111}),
		  .fb({tmpFB_0__BLUE_PIN_net[0:0]}),
		  .io({tmpIO_0__BLUE_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__BLUE_PIN_net),
		  .interrupt({tmpINTERRUPT_0__BLUE_PIN_net[0:0]}),
		  .annotation({Net_18049}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BLUE_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_453
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;

    cy_annotation_universal_v1_0 R_4 (
        .connect({
            Net_7443,
            Net_17870
        })
    );
    defparam R_4.comp_name = "Resistor_v1_0";
    defparam R_4.port_names = "T1, T2";
    defparam R_4.width = 2;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_7443
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;


	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_START
		 (.int_signal(Net_17679));


	wire [0:0] tmpOE__BUTTON_PIN_net;
	wire [0:0] tmpIO_0__BUTTON_PIN_net;
	wire [0:0] tmpINTERRUPT_0__BUTTON_PIN_net;
	electrical [0:0] tmpSIOVREF__BUTTON_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BUTTON_PIN
		 (.oe(tmpOE__BUTTON_PIN_net),
		  .y({1'b0}),
		  .fb({Net_18120}),
		  .io({tmpIO_0__BUTTON_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__BUTTON_PIN_net),
		  .interrupt({tmpINTERRUPT_0__BUTTON_PIN_net[0:0]}),
		  .annotation({Net_17870}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BUTTON_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 KIT_059_3 (
        .connect({
            Net_18447,
            Net_18448,
            Net_18449,
            Net_18450,
            Net_18451,
            Net_18452,
            Net_18453,
            Net_18454,
            Net_18494,
            Net_18493,
            Net_18492,
            Net_18481,
            Net_18482,
            Net_18483,
            Net_18484,
            Net_18485,
            Net_18486,
            Net_17268,
            Net_10073,
            Net_18491,
            Net_18490,
            Net_18489,
            Net_18455,
            Net_18456,
            Net_18457,
            Net_18458,
            Net_18459,
            Net_18460,
            Net_18488,
            Net_18487,
            Net_18480,
            Net_18479,
            Net_18478,
            Net_18477,
            Net_18476,
            Net_18475,
            Net_18474,
            Net_18473,
            Net_18461,
            Net_18462,
            Net_18463,
            Net_18464,
            Net_18465,
            Net_18466,
            Net_18467,
            Net_18468,
            Net_18498,
            Net_18499,
            Net_18500,
            Net_18501,
            Net_18502,
            Net_18471,
            Net_18496,
            Net_18469,
            Net_18470,
            Net_18472,
            Net_18495,
            Net_18497[1:0]
        })
    );
    defparam KIT_059_3.comp_name = "KIT_059_v1_0";
    defparam KIT_059_3.port_names = "P_00, P_01, P_02, P_03, P_04, P_05, P_06, P_07, P_10, P_11, P_12, P_120, P_121, P_122, P_123, P_124, P_125, P_126, P_127, P_13, P_14, P_15, P_150, P_151, P_152, P_153, P_154, P_155, P_16, P_17, P_20, P_21, P_22, P_23, P_24, P_25, P_26, P_27, P_30, P_31, P_32, P_33, P_34, P_35, P_36, P_37, P_59, P_60, P_61, P_62, P_63, P_GND_0, P_GND_1, P_GND_3, P_RST_0, P_VDD_0, P_VDDIO, USB_1_1, USB_1_0";
    defparam KIT_059_3.width = 59;

    UART_v2_50_2 UART (
        .cts_n(1'b0),
        .tx(Net_9807),
        .rts_n(Net_10167),
        .tx_en(Net_10168),
        .clock(1'b0),
        .reset(1'b0),
        .rx(Net_10171),
        .tx_interrupt(Net_10172),
        .rx_interrupt(Net_10173),
        .tx_data(Net_10174),
        .tx_clk(Net_10175),
        .rx_data(Net_10176),
        .rx_clk(Net_10177));
    defparam UART.Address1 = 0;
    defparam UART.Address2 = 0;
    defparam UART.EnIntRXInterrupt = 0;
    defparam UART.EnIntTXInterrupt = 0;
    defparam UART.FlowControl = 0;
    defparam UART.HalfDuplexEn = 0;
    defparam UART.HwTXEnSignal = 1;
    defparam UART.NumDataBits = 8;
    defparam UART.NumStopBits = 1;
    defparam UART.ParityType = 0;
    defparam UART.RXEnable = 1;
    defparam UART.TXEnable = 1;


    assign Net_17855 = ~Net_17852;

	wire [0:0] tmpOE__TX_PIN_net;
	wire [0:0] tmpFB_0__TX_PIN_net;
	wire [0:0] tmpIO_0__TX_PIN_net;
	wire [0:0] tmpINTERRUPT_0__TX_PIN_net;
	electrical [0:0] tmpSIOVREF__TX_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		TX_PIN
		 (.oe(tmpOE__TX_PIN_net),
		  .y({Net_9807}),
		  .fb({tmpFB_0__TX_PIN_net[0:0]}),
		  .io({tmpIO_0__TX_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__TX_PIN_net),
		  .interrupt({tmpINTERRUPT_0__TX_PIN_net[0:0]}),
		  .annotation({Net_10073}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TX_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Timer_v2_80_3 BUTTON_TIMER (
        .reset(Net_17852),
        .interrupt(Net_17811),
        .enable(Net_17855),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_17682),
        .tc(Net_17683),
        .clock(Net_18158));
    defparam BUTTON_TIMER.CaptureCount = 2;
    defparam BUTTON_TIMER.CaptureCounterEnabled = 0;
    defparam BUTTON_TIMER.DeviceFamily = "PSoC5";
    defparam BUTTON_TIMER.InterruptOnCapture = 0;
    defparam BUTTON_TIMER.InterruptOnTC = 1;
    defparam BUTTON_TIMER.Resolution = 8;
    defparam BUTTON_TIMER.SiliconRevision = "0";

    cy_annotation_universal_v1_0 KIT_059_4 (
        .connect({
            Net_18503,
            Net_18504,
            Net_18505,
            Net_18506,
            Net_18507,
            Net_18508,
            Net_18509,
            Net_18510,
            Net_18548,
            Net_18547,
            Net_18546,
            Net_184,
            Net_116,
            Net_117,
            Net_191,
            Net_18537,
            Net_18538,
            Net_18539,
            Net_18540,
            Net_18545,
            Net_18544,
            Net_18543,
            Net_18511,
            Net_18512,
            Net_18513,
            Net_18514,
            Net_18515,
            Net_18516,
            Net_18542,
            Net_18541,
            Net_18536,
            Net_18535,
            Net_18534,
            Net_18533,
            Net_18532,
            Net_18531,
            Net_18530,
            Net_18529,
            Net_18517,
            Net_18518,
            Net_18519,
            Net_18520,
            Net_18521,
            Net_18522,
            Net_18523,
            Net_18524,
            Net_18552,
            Net_18553,
            Net_18554,
            Net_18555,
            Net_18556,
            Net_18527,
            Net_18550,
            Net_18525,
            Net_18526,
            Net_18528,
            Net_18549,
            Net_18551[1:0]
        })
    );
    defparam KIT_059_4.comp_name = "KIT_059_v1_0";
    defparam KIT_059_4.port_names = "P_00, P_01, P_02, P_03, P_04, P_05, P_06, P_07, P_10, P_11, P_12, P_120, P_121, P_122, P_123, P_124, P_125, P_126, P_127, P_13, P_14, P_15, P_150, P_151, P_152, P_153, P_154, P_155, P_16, P_17, P_20, P_21, P_22, P_23, P_24, P_25, P_26, P_27, P_30, P_31, P_32, P_33, P_34, P_35, P_36, P_37, P_59, P_60, P_61, P_62, P_63, P_GND_0, P_GND_1, P_GND_3, P_RST_0, P_VDD_0, P_VDDIO, USB_1_1, USB_1_0";
    defparam KIT_059_4.width = 59;

	wire [0:0] tmpOE__MISO_net;
	wire [0:0] tmpIO_0__MISO_net;
	wire [0:0] tmpINTERRUPT_0__MISO_net;
	electrical [0:0] tmpSIOVREF__MISO_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MISO
		 (.oe(tmpOE__MISO_net),
		  .y({1'b0}),
		  .fb({Net_19}),
		  .io({tmpIO_0__MISO_net[0:0]}),
		  .siovref(tmpSIOVREF__MISO_net),
		  .interrupt({tmpINTERRUPT_0__MISO_net[0:0]}),
		  .annotation({Net_117}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MISO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MOSI_net;
	wire [0:0] tmpFB_0__MOSI_net;
	wire [0:0] tmpIO_0__MOSI_net;
	wire [0:0] tmpINTERRUPT_0__MOSI_net;
	electrical [0:0] tmpSIOVREF__MOSI_net;

	cy_psoc3_pins_v1_10
		#(.id("8593873b-05de-4935-8f7b-25fff2c6e2ef"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MOSI
		 (.oe(tmpOE__MOSI_net),
		  .y({Net_23}),
		  .fb({tmpFB_0__MOSI_net[0:0]}),
		  .io({tmpIO_0__MOSI_net[0:0]}),
		  .siovref(tmpSIOVREF__MOSI_net),
		  .interrupt({tmpINTERRUPT_0__MOSI_net[0:0]}),
		  .annotation({Net_116}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MOSI_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SCLK_net;
	wire [0:0] tmpFB_0__SCLK_net;
	wire [0:0] tmpIO_0__SCLK_net;
	wire [0:0] tmpINTERRUPT_0__SCLK_net;
	electrical [0:0] tmpSIOVREF__SCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("83b2fde2-60ad-45b6-9e5c-cb3baa6e3f9a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SCLK
		 (.oe(tmpOE__SCLK_net),
		  .y({Net_25}),
		  .fb({tmpFB_0__SCLK_net[0:0]}),
		  .io({tmpIO_0__SCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__SCLK_net),
		  .interrupt({tmpINTERRUPT_0__SCLK_net[0:0]}),
		  .annotation({Net_184}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SPI_Master_v2_50_4 SPIM (
        .mosi(Net_23),
        .sclk(Net_25),
        .ss(Net_17337),
        .miso(Net_19),
        .clock(1'b0),
        .reset(1'b0),
        .rx_interrupt(Net_17340),
        .sdat(Net_17341),
        .tx_interrupt(Net_17342));
    defparam SPIM.BidirectMode = 0;
    defparam SPIM.HighSpeedMode = 0;
    defparam SPIM.NumberOfDataBits = 8;
    defparam SPIM.ShiftDir = 0;

	wire [0:0] tmpOE__RX_PIN_net;
	wire [0:0] tmpIO_0__RX_PIN_net;
	wire [0:0] tmpINTERRUPT_0__RX_PIN_net;
	electrical [0:0] tmpSIOVREF__RX_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("7b09c831-1bc9-4a9e-a9b1-7ceeeadbb500"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		RX_PIN
		 (.oe(tmpOE__RX_PIN_net),
		  .y({1'b0}),
		  .fb({Net_10171}),
		  .io({tmpIO_0__RX_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__RX_PIN_net),
		  .interrupt({tmpINTERRUPT_0__RX_PIN_net[0:0]}),
		  .annotation({Net_17268}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__RX_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__CS_net;
	wire [0:0] tmpFB_0__CS_net;
	wire [0:0] tmpIO_0__CS_net;
	wire [0:0] tmpINTERRUPT_0__CS_net;
	electrical [0:0] tmpSIOVREF__CS_net;

	cy_psoc3_pins_v1_10
		#(.id("a3dfdc56-b23c-4b1b-b32c-4f2a2e9399e9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		CS
		 (.oe(tmpOE__CS_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__CS_net[0:0]}),
		  .io({tmpIO_0__CS_net[0:0]}),
		  .siovref(tmpSIOVREF__CS_net),
		  .interrupt({tmpINTERRUPT_0__CS_net[0:0]}),
		  .annotation({Net_191}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__CS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__ONBOARD_LED_net;
	wire [0:0] tmpFB_0__ONBOARD_LED_net;
	wire [0:0] tmpIO_0__ONBOARD_LED_net;
	wire [0:0] tmpINTERRUPT_0__ONBOARD_LED_net;
	electrical [0:0] tmpSIOVREF__ONBOARD_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("8f8e3cfd-20af-4025-a72e-9dcbdf102978"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		ONBOARD_LED
		 (.oe(tmpOE__ONBOARD_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__ONBOARD_LED_net[0:0]}),
		  .io({tmpIO_0__ONBOARD_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__ONBOARD_LED_net),
		  .interrupt({tmpINTERRUPT_0__ONBOARD_LED_net[0:0]}),
		  .annotation({Net_18112}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ONBOARD_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Timer_v2_80_5 NOTIFY_TIMER (
        .reset(Net_18127),
        .interrupt(Net_17904),
        .enable(1'b1),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_18027),
        .tc(Net_18028),
        .clock(Net_18158));
    defparam NOTIFY_TIMER.CaptureCount = 2;
    defparam NOTIFY_TIMER.CaptureCounterEnabled = 0;
    defparam NOTIFY_TIMER.DeviceFamily = "PSoC5";
    defparam NOTIFY_TIMER.InterruptOnCapture = 0;
    defparam NOTIFY_TIMER.InterruptOnTC = 1;
    defparam NOTIFY_TIMER.Resolution = 8;
    defparam NOTIFY_TIMER.SiliconRevision = "0";


	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_NOTIFY
		 (.int_signal(Net_18028));


    assign Net_18127 = 1'h0;

    assign Net_17093 = 1'h0;

    assign Net_17104 = 1'h0;

	wire [0:0] tmpOE__INT1_PIN_net;
	wire [0:0] tmpIO_0__INT1_PIN_net;
	wire [0:0] tmpINTERRUPT_0__INT1_PIN_net;
	electrical [0:0] tmpSIOVREF__INT1_PIN_net;

	cy_psoc3_pins_v1_10
		#(.id("5fa90865-77bd-469c-b29d-70b5f243a5e6"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		INT1_PIN
		 (.oe(tmpOE__INT1_PIN_net),
		  .y({1'b0}),
		  .fb({Net_18560}),
		  .io({tmpIO_0__INT1_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__INT1_PIN_net),
		  .interrupt({tmpINTERRUPT_0__INT1_PIN_net[0:0]}),
		  .annotation({Net_18537}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__INT1_PIN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_IMU
		 (.int_signal(Net_18560));




endmodule

