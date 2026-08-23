#include "../MCAL/RCC/RCC.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/GPIO_DRIVER.h"


void ADC_Init(void);
unsigned int ADC_Read(void);


static void delay(volatile unsigned int count) {
    for (volatile unsigned int i = 0; i < count; i++) {
        __asm volatile ("nop");
    }
}



void setup(){
    RCC_Init();

    SET_BIT(GPIOA_MODER, 0); 
    SET_BIT(GPIOA_MODER, 1); // PA0 as analog

    SET_BIT(GPIOA_MODER, 2);   
    CLEAR_BIT(GPIOA_MODER, 3); // PA1 as output
    SET_BIT(GPIOA_MODER, 4);   
    CLEAR_BIT(GPIOA_MODER, 5); // PA2 as output
    SET_BIT(GPIOA_MODER, 6);   
    CLEAR_BIT(GPIOA_MODER, 7); // PA3 as output

    CLEAR_BIT(GPIOB_MODER, 0); 
    CLEAR_BIT(GPIOB_MODER, 1); // PB0 as Digital input
    CLEAR_BIT(GPIOB_MODER, 2); 
    CLEAR_BIT(GPIOB_MODER, 3); // PB1 as Digital input
    CLEAR_BIT(GPIOB_MODER, 4); 
    CLEAR_BIT(GPIOB_MODER, 5); // PB2 as Digital input

    ADC_Init();

}

void loop(){
    /*
    //ADC Code


    unsigned int adc_val = ADC_Read();

   if (adc_val < 1365) {
        // 0 -> 1.1v : 1 LED ON
        SET_BIT(GPIOA_ODR, 1);
        CLEAR_BIT(GPIOA_ODR, 2);
        CLEAR_BIT(GPIOA_ODR, 3);
    } 
    else if (adc_val >= 1365 && adc_val < 2730) {
        // 1.1v -> 2.2v : 2 LEDs ON
        SET_BIT(GPIOA_ODR, 1);
        SET_BIT(GPIOA_ODR, 2);
        CLEAR_BIT(GPIOA_ODR, 3);
    } 
    else {
        // 2.2v -> 3.3v : 3 LEDs ON
        SET_BIT(GPIOA_ODR, 1);
        SET_BIT(GPIOA_ODR, 2);
        SET_BIT(GPIOA_ODR, 3);
    }
    */
    

    unsigned char sw1 = GET_BIT(GPIOB_IDR, 0);
    unsigned char sw2 = GET_BIT(GPIOB_IDR, 1);
    unsigned char sw3 = GET_BIT(GPIOB_IDR, 2);

    if (sw1) {
        SET_BIT(GPIOA_ODR, 1);
    } else {
        CLEAR_BIT(GPIOA_ODR, 1);
    }

    if (sw2) {
        SET_BIT(GPIOA_ODR, 2);
    } else {
        CLEAR_BIT(GPIOA_ODR, 2);
    }

    if (sw3) {
        SET_BIT(GPIOA_ODR, 3);
    } else {
        CLEAR_BIT(GPIOA_ODR, 3);
    }

    delay(1000);

}

int main(void)
{
    setup();  //as you know the setups is called only once


    while (1)
    {
        loop();   //loop is called continously so it's in the while(1)
    }
}