# include "private.h"
# include "BIT_MATH.h"


unsigned int ADC_Read(void)
{
    // Start conversion
    SET_BIT(ADC1_CR2,30);

    // Wait until conversion is complete
    while (GET_BIT(ADC_SR,1) == 0);

    // Return ADC result
    return ADC_DR;
}