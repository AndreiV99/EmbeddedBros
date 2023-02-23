#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <ti/grlib/grlib.h>
#include "Crystalfontz128x128_ST7735.h"
#include "HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include "HAL_I2C.h"
#include "HAL_TMP006.h"


/***************************************************************
*
* _graphicsInit() – Initializes the configuration of the LCD screen
*
****************************************************************/

void _graphicsInit();

/***************************************************************
*
* _setDisplay() – Sets the initial screen configuration of the game
*
****************************************************************/

void _setDisplay();

#endif /* DISPLAY_H_ */
