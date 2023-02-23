#include "timer.h"

/* Timer_A Up Configuration Parameter */
const Timer_A_UpModeConfig upConfig1 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK = 3 MHZ
        TIMER_A_CLOCKSOURCE_DIVIDER_64,         // SMCLK/64 = 46875Hz
        TIMER_PERIOD1,                          // until reaches 65536 value
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};
/* Timer_A Up Configuration Parameter */
const Timer_A_UpModeConfig upConfig2 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK = 3 MHZ
        TIMER_A_CLOCKSOURCE_DIVIDER_64,         // SMCLK/64 = 46875Hz
        TIMER_PERIOD2,                          // until reaches 58982 value
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};

/* Timer_A Compare Configuration Parameter  (PWM) */
const Timer_A_CompareModeConfig compareConfig_PWM = {
        TIMER_A_CAPTURECOMPARE_REGISTER_4,         // Use CCR3
        TIMER_A_CAPTURECOMPARE_INTERRUPT_DISABLE,  // Disable CCR interrupt
        TIMER_A_OUTPUTMODE_RESET_SET,              // used Reset-Set output mode
        999                                        // 10% Duty Cycle initially
};

/* Timer_A Up Configuration Parameter */
const Timer_A_UpModeConfig upConfig = {
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK = 3 MHZ
        TIMER_A_CLOCKSOURCE_DIVIDER_1,          // SMCLK/1 = 3MHZ
        39999,                                  // until reaches 39999 value
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE,    // Disable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};

void _timerInit(){
    Timer_A_configureUpMode(TIMER_A1_BASE, &upConfig2);
    Timer_A_configureUpMode(TIMER_A3_BASE, &upConfig1);
    Timer_A_configureUpMode(TIMER_A2_BASE, &upConfig1);
    Interrupt_enableSleepOnIsrExit();
    Interrupt_enableInterrupt(INT_TA1_0);
    Interrupt_enableInterrupt(INT_TA3_0);
    Interrupt_enableInterrupt(INT_TA2_0);
    Interrupt_enableMaster();
}

void _timerStop(){
    Timer_A_stopTimer(TIMER_A3_BASE);
    Timer_A_stopTimer(TIMER_A1_BASE);
    Timer_A_stopTimer(TIMER_A2_BASE);
}

void _timerClearCCI(){
    Timer_A_clearCaptureCompareInterrupt(TIMER_A3_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
    Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
    Timer_A_clearCaptureCompareInterrupt(TIMER_A2_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

void _delay(uint32_t x){
    uint32_t i;
    for(i=0; i<x; i++);
}
