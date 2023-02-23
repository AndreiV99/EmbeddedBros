#ifndef BUZZER_H_
#define BUZZER_H_

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


/***************************************************************
*
* _buzzerInit() – Initializes the configuration of the buzzer
*
****************************************************************/

void _buzzerInit();

/***************************************************************
*
* _buzzerStop() – this function delays and than stops the timer
*                 related to the buzzer
*
****************************************************************/

void _buzzerStop();

#endif /* BUZZER_H_ */
