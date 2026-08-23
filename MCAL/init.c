#include "private.h"
#include "BIT_MATH.h"

void ADC_Init(void)
{
    // Enable ADC clock
    SET_BIT(RCC_APB2ENR,8) ;

    // Configure ADC clock
    CLEAR_BIT(ADC_CCR,16);
    CLEAR_BIT(ADC_CCR,17);
    SET_BIT(ADC_CCR,16);

    // Configure ADC resolution
    CLEAR_BIT(ADC1_CR1,24);
    CLEAR_BIT(ADC1_CR1,25);

    // Configure sampling time
    CLEAR_BIT(ADC1_SMPR2,0) ;
    CLEAR_BIT(ADC1_SMPR2,1) ;
    SET_BIT(ADC1_SMPR2,2) ;

    // Select channel
    CLEAR_BIT(ADC1_SQR3,0);
    CLEAR_BIT(ADC1_SQR3,1);
    CLEAR_BIT(ADC1_SQR3,2);
    CLEAR_BIT(ADC1_SQR3,3);
    CLEAR_BIT(ADC1_SQR3,4);

    // Number of conversions
    CLEAR_BIT(ADC1_SQR1 ,20) ;
    CLEAR_BIT(ADC1_SQR1 ,21) ;
    CLEAR_BIT(ADC1_SQR1 ,22) ;
    CLEAR_BIT(ADC1_SQR1 ,23) ;

    // Enable ADC
    SET_BIT(ADC1_CR2,0) ;

    // cont. mode
    SET_BIT(ADC1_CR2,1);
}


