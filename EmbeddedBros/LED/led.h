#ifndef LED_H_
#define LED_H_

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


/*****************************************************************
*
* _LEDInit() – This function initializes all the LEDs, by setting
*              the following ports as GPIO output:
*                   - P1.1 RED
*                   - P2.0 RED
*                   - P2.1 GREEN
*                   - P2.2 BLUE
*             and turns all LEDs off
*
******************************************************************/

void _LEDInit();

/***************************************************************
*
* _setLEDLow() – Turns off all the LEDs()
*
****************************************************************/

void _setLEDLow();

/***************************************************************
*
* allColors() – This function firstly turns off all the LEDs,
*               then repeats for three times the following steps:
*                   -turn on RED - delays - turn off RED
*                   -turn on GREEN - delays - turn off GREEN
*                   -turn on BLUE - delays - turn off BLUE
*                   -lastly does a longer delay, in order to
*                    identify the three loops
****************************************************************/

void allColors();

#endif /* LED_H_ */
