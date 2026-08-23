#include "private.h"
#include "BIT_MATH.h"

void ADC_Init(void)
{
    // Enable ADC clock
    SET_BIT(RCC_APB2ENR,8) ;

    // Configure ADC clock




    // Configure ADC resolution

    // Configure sampling time

    // Select channel

    // Number of conversions
    CLEAR_BIT(ADC1_SQR1 ,20) ;
    CLEAR_BIT(ADC1_SQR1 ,21) ;
    CLEAR_BIT(ADC1_SQR1 ,22) ;
    CLEAR_BIT(ADC1_SQR1 ,23) ;

    // Enable ADC
    SET_BIT(ADC1_CR2,0) ;
}


