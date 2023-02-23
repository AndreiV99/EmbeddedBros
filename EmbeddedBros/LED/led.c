#include "led.h"
#include "../Timer/timer.h"

void allColors(){
    _setLEDLow();
    int j;
    for(j=0; j<3;j++){
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
        _delay(100000);
        GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
        _delay(100000);
        GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
        GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
        _delay(100000);
        GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
        _delay(1000000);
    }
}

void _setLEDLow(){
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

void _LEDInit(){
    GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P2,GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P2,GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P2,GPIO_PIN2);
    _setLEDLow();
}
