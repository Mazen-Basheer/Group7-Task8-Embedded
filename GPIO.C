#include "GPIO.h"
#include "BIT_MATH.h"

#define GPIOA_BASE_ADDR        0x40020000

#define GPIO_MODER_OFFSET      0x00
#define GPIO_OTYPER_OFFSET     0x04
#define GPIO_OSPEEDR_OFFSET    0x08
#define GPIO_PUPDR_OFFSET      0x0C
#define GPIO_IDR_OFFSET        0x10
#define GPIO_ODR_OFFSET        0x14

#define GPIOA_MODER       ((unsigned int *)(GPIOA_BASE_ADDR + GPIO_MODER_OFFSET))
#define GPIOA_OTYPER      ((unsigned int *)(GPIOA_BASE_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOA_OSPEEDR     ((unsigned int *)(GPIOA_BASE_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOA_PUPDR       ((unsigned int *)(GPIOA_BASE_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOA_IDR         ((unsigned int *)(GPIOA_BASE_ADDR + GPIO_IDR_OFFSET))
#define GPIOA_ODR         ((unsigned int *)(GPIOA_BASE_ADDR + GPIO_ODR_OFFSET))

void GPIO_init(){

}
