#ifndef TIMER_H_
#define TIMER_H_

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdio.h>
#include <stdlib.h>

#define TIMER_PERIOD1    0xFFFF //period1 value 65536
#define TIMER_PERIOD2    0xE666 //period2 value 58982

/*************************************************************************
*
* _timerInit() – Initializes the configuration of the timer, by
*                configuring every timer used with a stuct
*                enables the interrupts of the timers and of the master
*                goes to LPM once finished executing the ISR
*
**************************************************************************/

void _timerInit();

/***************************************************************
*
* _timerStop() – Stops all the timers used within the program
*
****************************************************************/

void _timerStop();

/*************************************************************************************
*
* _timerClearCCI() – Clears all the capture-compares registers of the used timers
*
**************************************************************************************/

void _timerClearCCI();

/****************************************************************************************
*
* _delay() – Takes an unsigned 32 bit integer and applies a delay with that given number
* uint32_t x : number of times the for iterates
*
*****************************************************************************************/

void _delay(uint32_t x);

#endif /* TIMER_H_ */
