#include "buzzer.h"
#include "../Timer/timer.h"

extern Timer_A_CompareModeConfig compareConfig_PWM;
extern Timer_A_UpModeConfig upConfig;

void _buzzerInit()
{
    /* Configures P2.7 to PM_TA0.4 for using Timer PWM to control the buzzer */
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
    /* Configuring Timer_A0 for Up Mode and starting */
    Timer_A_configureUpMode(TIMER_A0_BASE, &upConfig);
    Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
    /* Initialize compare registers to generate PWM */
    Timer_A_initCompare(TIMER_A0_BASE, &compareConfig_PWM); // For P2.7
}

void _buzzerStop(){
    _delay(100000);
    Timer_A_stopTimer(TIMER_A0_BASE);
}
