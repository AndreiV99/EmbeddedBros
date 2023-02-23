#include "adc.h"

void _adcInit(){
    /* Configures Pin 6.0 and 4.4 as ADC input */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN0, GPIO_TERTIARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN4, GPIO_TERTIARY_MODULE_FUNCTION);
    /* Initializing ADC (ADCOSC/64/8) */
    ADC14_enableModule();
    ADC14_initModule(ADC_CLOCKSOURCE_ADCOSC, ADC_PREDIVIDER_64, ADC_DIVIDER_8, 0);
    /* Configuring ADC Memory (ADC_MEM0 - ADC_MEM1 (A15, A14)  with repeat) with internal 2.5v reference */
    ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM1, true);
    ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A15, ADC_NONDIFFERENTIAL_INPUTS);
    ADC14_configureConversionMemory(ADC_MEM1, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A14, ADC_NONDIFFERENTIAL_INPUTS);
    /* Enabling the interrupt when a conversion on channel 1 (end of sequence)  is complete and enabling conversions */
    ADC14_enableInterrupt(ADC_INT1);
    /* Enabling Interrupts */
    Interrupt_enableInterrupt(INT_ADC14);
    Interrupt_enableMaster();
    /* Setting up the sample timer to manually , which is called by the timer interrupt. */
    ADC14_enableSampleTimer(ADC_MANUAL_ITERATION);
    /* Triggering the start of the sample */
    ADC14_enableConversion();
}
