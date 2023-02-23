#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "Crystalfontz128x128_ST7735.h"
#include "HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include "HAL_I2C.h"
#include "HAL_TMP006.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "display.h"
#include "buzzer.h"
#include "timer.h"
#include "led.h"
#include "adc.h"

/* MACROS */
#define INITX 41 // x coordinate of the initial character position
#define INITY 57 // y coordinate of the initial character position
#define TIMER_PERIOD3    0xC000 // period3 with value 49152
#define TIMER_PERIOD4    0xACCC //period4 with value44236

/* Graphic library context */
extern Graphics_Context g_sContext;
extern Graphics_Context dev;

/* Timer structs */
extern Timer_A_UpModeConfig upConfig1;
extern Timer_A_UpModeConfig upConfig2;
extern Timer_A_CompareModeConfig compareConfig_PWM;
extern Timer_A_UpModeConfig upConfig;

/* Variables used inside the program functions */
volatile static int points; //current points
volatile static int play; //if playing or not
volatile static int jump; //if jumping or not
volatile static int goingUp; //while jumping if going up or down
volatile static int upDown; //random value to move boo up or down
volatile static int booGoomba;// random value to generate the "bad character"
volatile static int bestScore = 0; //global variable that holds the best score
volatile static int charX; //character x coordinate
volatile static int charY; //character y coordinate
volatile static int badCharY; //"bad character" y coordinate
volatile static int badCharX; //"bad character" x coordinate
volatile static int mini; //if the character is mini or not
volatile Graphics_Image * character = NULL; //pointer to the chosen character
volatile Graphics_Image * characterMini = NULL; //pointer to the mini of the chosen character
volatile Graphics_Image * badChar = NULL; //pointer to the random "bad character"

/* States enumeration */
typedef enum {
    STATE_INIT,
    STATE_MARIO,
    STATE_TOAD,
    STATE_SONIC,
    STATE_YOSHI,
    STATE_START,
    STATE_PLAY,
    STATE_GAMEOVER,
    NUM_STATES
}State_t;

/* FSM struct */
typedef struct{
    State_t state;
    void (*state_function)(void);
} StateMachine_t;

/* functions related to the states */
void fn_INIT(void);
void fn_MARIO(void);
void fn_TOAD(void);
void fn_SONIC(void);
void fn_YOSHI(void);
void fn_START(void);
void fn_PLAY(void);
void fn_GAMEOVER(void);

/* initial state */
State_t current_state = STATE_INIT;

/* FSM vector */
StateMachine_t fsm[] = {
                      {STATE_INIT, fn_INIT},
                      {STATE_MARIO, fn_MARIO},
                      {STATE_TOAD, fn_TOAD},
                      {STATE_SONIC, fn_SONIC},
                      {STATE_YOSHI, fn_YOSHI},
                      {STATE_START, fn_START},
                      {STATE_PLAY, fn_PLAY},
                      {STATE_GAMEOVER, fn_GAMEOVER},
};

/*********************************************************************************************
*
* draw() – Takes as input a pointer to a Graphics_Image, and two unsigned 16 bit integers,
*          draws the image pointed in the position given by the two integers
* Graphics_Image * c : pointer to a struct holding an image characteristics
* uint16_t x : x position
* uint16_t y : y position
*
**********************************************************************************************/

void draw(Graphics_Image * c, uint16_t x, uint16_t y){
    Graphics_drawImage(&g_sContext, c, x, y);
}

/*********************************************************************************************
*
* drawRectBooGoomba() – This function draws a black rectangle at the current position of the
*                       "badChar", in order to cover it (and not clearing the entire screen)
*                       before every movement
*
**********************************************************************************************/

void drawRectBooGoomba(){
    Graphics_Rectangle rect = {badCharX, badCharY, (badCharX+45), (badCharY+45)};
    Graphics_fillRectangleOnDisplay(&g_sCrystalfontz128x128 ,&rect,0x0000);
}

/*********************************************************************************************
*
* drawRectChar() – This function draws a black rectangle at the current position of the
*                  character, in order to cover it (and not clearing the entire screen)
*                  before every movement, the dimension of the rectangle is based on the
*                  size of the character (mini or not)
*
**********************************************************************************************/

void drawRectChar(){
    Graphics_Rectangle rect = {charX, charY, (charX+45), (charY+45)};
    if(mini){
        Graphics_Rectangle rect = {charX, charY, (charX+30), (charY+30)};
    }
    Graphics_fillRectangleOnDisplay(&g_sCrystalfontz128x128 ,&rect,0x0000);
}

/*********************************************************************************************
*
* drawRectChar() – This function generates a random number (between 0 and 1), and based on
*                  this number generates the "badChar" (Boo or Goomba)
*
**********************************************************************************************/

void createBadChar(){
    extern Graphics_Image goomba;
    extern Graphics_Image boo;
    booGoomba = random(0,1);
    if(booGoomba == 0){
        badChar = &goomba;
        badCharY = 83;
    }else{
        badChar = &boo;
        badCharY = 45;
    }
}

void fn_INIT(){ // current_state = 0
    _setDisplay();
    //sets the initial values of the variables, in order to reset them at each end of the game
    points = 0;
    play = 1;
    jump = 0;
    mini = 0;
    Timer_A_startCounter(TIMER_A2_BASE, TIMER_A_UP_MODE);
    current_state = 1;
    (*fsm[current_state].state_function)();
}

void fn_MARIO(){  // current_state = 1
    extern Graphics_Image mario;
    extern Graphics_Image marioMini;
    character  = &mario;
    characterMini  = &marioMini;
    draw(character, INITX, INITY);
}

void fn_TOAD(){ // current_state = 2
    extern Graphics_Image toad;
    extern Graphics_Image toadMini;
    character  = &toad;
    characterMini  = &toadMini;
    draw(character, INITX, INITY);
}

void fn_SONIC(){ // current_state = 3
    extern Graphics_Image sonic;
    extern Graphics_Image sonicMini;
    character  = &sonic;
    characterMini  = &sonicMini;
    draw(character, INITX, INITY);
}

void fn_YOSHI(){ // current_state = 4
    extern Graphics_Image yoshi;
    extern Graphics_Image yoshiMini;
    character  = &yoshi;
    characterMini  = &yoshiMini;
    draw(character, INITX, INITY);
}

void fn_START(){ // current_state = 5
    extern Graphics_Image three;
    extern Graphics_Image two;
    extern Graphics_Image one;
    extern Graphics_Image go;
    //starts and stops the buzzer while showing the images (1-2-3)
    _delay(750000);
    int i;
    for(i=0;i<3;i++){
        _buzzerInit();
        Graphics_clearDisplay(&dev);
        switch (i){
        case 0:
            _setLEDLow();
            Graphics_drawImage(&g_sContext, &three, 14 , 14);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
            break;
        case 1:
            _setLEDLow();
            Graphics_drawImage(&g_sContext, &two, 21 , 21);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
            break;
        case 2:
            _setLEDLow();
            Graphics_drawImage(&g_sContext, &one, 25 , 25);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
            break;
        }
        _delay(1000000);
        _buzzerStop();
        _delay(1000000);
    }
    _buzzerInit();
    //changes the timer's period, to make a different sound, while showing the "go" image
    TIMER_A0->CCR[0] = 27999;
    TIMER_A0->CCR[4] = 999;
    Graphics_clearDisplay(&dev);
    Graphics_drawImage(&g_sContext, &go, 14 , 42);
    _setLEDLow();
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    _delay(1225000);
    _buzzerStop();
    _delay(750000);
    _setLEDLow();
    current_state = 6;
    (*fsm[current_state].state_function)();
}

void fn_PLAY(){ // current_state = 6
    badCharX = 128;
    charX = 0;
    charY = 83;
    goingUp = 1;
    badCharY = 83;
    booGoomba = 0;
    createBadChar();
    Graphics_clearDisplay(&g_sContext);
    Graphics_clearDisplay(&dev);
    Graphics_drawImage(&g_sContext, character, charX, charY);
    Graphics_drawImage(&g_sContext, badChar, badCharX, badCharY);
    Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);
    Timer_A_startCounter(TIMER_A3_BASE, TIMER_A_UP_MODE);
}

void fn_GAMEOVER(){ // current_state = 7
    _timerStop();
    Graphics_clearDisplay(&g_sContext);
    Graphics_clearDisplay(&dev);
    Graphics_drawStringCentered(&g_sContext, (int8_t *)"GAMEOVER!!", AUTO_STRING_LENGTH, 64, 64, OPAQUE_TEXT);
    //if current score is better than the previous best score, sets the bestScore variable with the current and toggles the LEDs
    if(bestScore < points){
        bestScore = points;
        allColors();
    }
    char string[30];
    sprintf(string, "Points: %d",points);
    Graphics_drawStringCentered(&dev, (int8_t *)string, AUTO_STRING_LENGTH, 64, 80, OPAQUE_TEXT);
    char string1[30];
    sprintf(string1, "BestScore: %d ",bestScore);
    Graphics_drawStringCentered(&dev, (int8_t *)string1, AUTO_STRING_LENGTH, 64, 91, OPAQUE_TEXT);
    _delay(10000000);
    current_state = 0;
    (*fsm[current_state].state_function)();
}

void _hwInit()
{
    /* Halting WDT and disabling master interrupts */
    WDT_A_holdTimer();
    /* Set the core voltage level to VCORE1 */
    PCM_setCoreVoltageLevel(PCM_VCORE1);
    /* Set 2 flash wait states for Flash bank 0 and 1*/
    FlashCtl_setWaitState(FLASH_BANK0, 2);
    FlashCtl_setWaitState(FLASH_BANK1, 2);
    /* Initializes Clock System */
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
    //initializes each peripheral
    _graphicsInit();
    _adcInit();
    _timerInit();
    _LEDInit();
}

/*******************************************************************************************************************************
*
* random(uint16_t min, uint16_t max) – This function generates a random number between the two unsigned 16 bit integer inputs
* uint16_t min : minimum value
* uint16_t max : maximum value
*
********************************************************************************************************************************/

int random(uint16_t min, uint16_t max){
   return min + rand() % (max+1 - min);
}


/*******************************************************************************************************************************
*
* drawBig() – This function covers the character, draws the bigger version and sets "mini" to 0
*             the if inside the function sets the y position to the ground (since the two characters have different sizes)
*
********************************************************************************************************************************/

void drawBig(){
    drawRectChar();
    if(charY == 93){
        charY = 83;
    }
    Graphics_drawImage(&g_sContext, character, charX , charY);
    mini = 0;
}

/*******************************************************************************************************************************
*
* drawSmall() – This function covers the character, draws the smaller version and sets "mini" to 1
*               the if inside the function sets the y position to the ground (since the two characters have different sizes)
*
********************************************************************************************************************************/

void drawSmall(){
    drawRectChar();
    if(charY == 83){
        charY = 93;
    }
    Graphics_drawImage(&g_sContext, characterMini, charX , charY);
    mini = 1;
}

/*
 * Main function
 */
int main(void)
{
    _hwInit();
    if(current_state < NUM_STATES){
        (*fsm[current_state].state_function)();
    }

    while (1)
    {
        PCM_gotoLPM0();
    }
}

void TA1_0_IRQHandler(void)
{
    //at each timer interrupt covers the current "badChar" and moves it to the next position
    drawRectBooGoomba();
    badCharX-=10;
    char string[10];
    sprintf(string, "Points: %d", points);
    Graphics_drawStringCentered(&dev, (int8_t *)string, AUTO_STRING_LENGTH, 95, 5, OPAQUE_TEXT);
    //when the "badChar" is not visible anymore, creates a new random one
    if(badCharX <-40){
        createBadChar();
        drawBig();
        badCharX=random(256, 384);
        ++points;
        if(!points%5){
            //toggles a BLUE LED when a multiple of 5 is reached
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
            _delay(400000);
            _setLEDLow();
        }
    }
    //moves Boo randomly up and down while passing
    if(booGoomba){
        if(badCharY >= 55){
            badCharY-=5;
        }else{
            if(badCharY <= 5){
                badCharY+=5;
            }else{
                upDown = random(0,1);
                switch(upDown){
                case 0:
                    badCharY -=5;
                    break;
                case 1:
                    badCharY +=5;
                    break;
                }
            }
        }
    }
    Graphics_drawImage(&g_sContext, badChar, badCharX, badCharY);
    Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

void TA3_0_IRQHandler(void)
{
    if(current_state == 6){
        //at each timer interrupt if covers the current character, and if the character is jumping, it is shifted up or down based on the "goingUp" variable
        if(jump){
            drawRectChar();
            if(goingUp){
                charY-=10;
                if(charY==3){
                    goingUp = 0;
                }
            }else{
                charY+=10;
                if((mini && charY == 93) || ((!mini) && charY == 83) ){
                    goingUp=1;
                    jump = 0;
                }
            }
        }
        if(mini){
            Graphics_drawImage(&g_sContext, characterMini, charX, charY);
        }else{
            Graphics_drawImage(&g_sContext, character, charX, charY);
        }
    }
    Timer_A_clearCaptureCompareInterrupt(TIMER_A3_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

void TA2_0_IRQHandler(void)
{
    ADC14_toggleConversionTrigger();
    if(current_state == 6){
        //checks if the character and the "badChar" are in collision
        if(booGoomba){
            if((abs(badCharX-(charX)) <= 42) && (abs(badCharY-(charY)) <= 35)){
                //printf("unsigned %d\n", (abs(pos-(charX))));
                _timerClearCCI();
                current_state = STATE_GAMEOVER;
                (*fsm[current_state].state_function)();
            }
        }else{
            //same check, but for the "mini" version
            if((abs((badCharX+4)-(charX)) <= 40) && (charY>63)){
                //printf("unsigned %d\n", (abs(pos-(charX))));
                _timerClearCCI();
                current_state = STATE_GAMEOVER;
                (*fsm[current_state].state_function)();
            }
        }
    }
    Timer_A_clearCaptureCompareInterrupt(TIMER_A2_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

/*the handler is fired manually at each timer2 interrupt */
void ADC14_IRQHandler(void){
    uint64_t status;
    uint16_t resultsBuffer[2];

    status = ADC14_getEnabledInterruptStatus();
    ADC14_clearInterruptFlag(status);

    /* ADC_MEM1 conversion completed */
    if(status & ADC_INT1)
    {
        /* Store ADC14 conversion results */
        resultsBuffer[0] = ADC14_getResult(ADC_MEM0); //stores the conversion of the Joystick X axis
        resultsBuffer[1] = ADC14_getResult(ADC_MEM1); // stores the conversion of the X value of the accelerometer

        if(play && current_state<5){
            //if choosing the character loops around them using the Joystick X axis
            if(resultsBuffer[0]> 14900 && resultsBuffer[0]< 16400){
                if(current_state == 4){
                    current_state = 1;
                }else{
                    current_state = (++current_state)%5;
                }
                if(current_state < NUM_STATES){
                    (*fsm[current_state].state_function)();
                }
            }

            if(resultsBuffer[0]> 0 && resultsBuffer[0]< 1500){
                if(current_state == 1){
                    current_state = 4;
                }else {
                    current_state = (--current_state)%5;
                }
                if(current_state < NUM_STATES){
                    (*fsm[current_state].state_function)();
                }
            }

            /* Determine if JoyStick button is pressed, to start the game */
            if (!(P4IN & GPIO_PIN1)){
                play = 0;
                current_state = 5;
                (*fsm[current_state].state_function)();
            }
        }

        if(current_state == 6){
            //if tilting the Boosterpack to the right, change timer periods to make it faster
            if(resultsBuffer[1]>8500){
                TIMER_A1->CCR[0] = TIMER_PERIOD4;
                TIMER_A3->CCR[0] = TIMER_PERIOD3;
            }else{
                TIMER_A1->CCR[0] = TIMER_PERIOD2;
                TIMER_A3->CCR[0] = TIMER_PERIOD1;
            }
            //if button2 is pressed, set the "jump" variable to 1 (to make the character jump)
            if (!(P3IN & GPIO_PIN5)){
                jump = 1;
            }
            //if button1 is pressed, toggle the character (big to small and small to big)
            if (!(P5IN & GPIO_PIN1)){
                if(mini){
                    drawBig();
                }else{
                    drawSmall();
                }
            }
       }
    }
}
