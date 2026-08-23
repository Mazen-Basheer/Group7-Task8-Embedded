#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

//base
#define GPIOA_BASE_ADDR         0x40020000
#define GPIOB_BASE_ADDR         0x40020400
#define GPIOC_BASE_ADDR         0x40020800
#define RCC_BASE_ADDR           0x40023800

//offsets
#define GPIO_MODER_OFFSET       0x00
#define GPIO_OTYPER_OFFSET      0x04
#define GPIO_OSPEEDR_OFFSET     0x08
#define GPIO_PUPDR_OFFSET       0x0C
#define GPIO_IDR_OFFSET         0x10
#define GPIO_ODR_OFFSET         0x14
#define GPIO_BSRR_OFFSET        0x18

#define RCC_AHB1ENR_OFFSET      0x30

//a
#define GPIOA_MODER     ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_MODER_OFFSET))
#define GPIOA_OTYPER    ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOA_OSPEEDR   ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOA_PUPDR     ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOA_IDR       ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_IDR_OFFSET))
#define GPIOA_ODR       ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_ODR_OFFSET))
#define GPIOA_BSRR      ((volatile unsigned int*)(GPIOA_BASE_ADDR + GPIO_BSRR_OFFSET))

//b
#define GPIOB_MODER     ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_MODER_OFFSET))
#define GPIOB_OTYPER    ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOB_OSPEEDR   ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOB_PUPDR     ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOB_IDR       ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_IDR_OFFSET))
#define GPIOB_ODR       ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_ODR_OFFSET))
#define GPIOB_BSRR      ((volatile unsigned int*)(GPIOB_BASE_ADDR + GPIO_BSRR_OFFSET))

//c
#define GPIOC_MODER     ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_MODER_OFFSET))
#define GPIOC_OTYPER    ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_OTYPER_OFFSET))
#define GPIOC_OSPEEDR   ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_OSPEEDR_OFFSET))
#define GPIOC_PUPDR     ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_PUPDR_OFFSET))
#define GPIOC_IDR       ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_IDR_OFFSET))
#define GPIOC_ODR       ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_ODR_OFFSET))
#define GPIOC_BSRR      ((volatile unsigned int*)(GPIOC_BASE_ADDR + GPIO_BSRR_OFFSET))

//clock enable register + bits
#define RCC_AHB1ENR     ((volatile unsigned int*)(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET))

#define RCC_AHB1ENR_GPIOAEN     0
#define RCC_AHB1ENR_GPIOBEN     1
#define RCC_AHB1ENR_GPIOCEN     2

//mode function
typedef enum {
    GPIO_MODE_INPUT  = 0x0,
    GPIO_MODE_OUTPUT = 0x1,
    GPIO_MODE_AF     = 0x2,
    GPIO_MODE_ANALOG = 0x3
} GPIO_Mode_t;

//otype function
typedef enum {
    GPIO_OTYPE_PP = 0x0,
    GPIO_OTYPE_OD = 0x1
} GPIO_OType_t;

//speed function
typedef enum {
    GPIO_SPEED_LOW    = 0x0,
    GPIO_SPEED_MEDIUM = 0x1,
    GPIO_SPEED_HIGH   = 0x2,
    GPIO_SPEED_VHIGH  = 0x3
} GPIO_Speed_t;

//pull-up pull-down function
typedef enum {
    GPIO_PUPD_NONE = 0x0,
    GPIO_PUPD_UP   = 0x1,
    GPIO_PUPD_DOWN = 0x2
} GPIO_PuPd_t;

//pin state function
typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET   = 1
} GPIO_PinState_t;

//port type, pass GPIOA_BASE_ADDR / GPIOB_BASE_ADDR / GPIOC_BASE_ADDR
typedef unsigned int GPIO_Port_t;

//enables clock for the given port
void GPIO_ClockEnable(GPIO_Port_t port);

//configures mode, otype, speed, pupd for a pin
void GPIO_Init(GPIO_Port_t port, unsigned char pin,
GPIO_Mode_t mode, GPIO_OType_t otype,
GPIO_Speed_t speed, GPIO_PuPd_t pupd);

//sets pin high or low
void GPIO_WritePin(GPIO_Port_t port, unsigned char pin, GPIO_PinState_t state);

//flips pin state
void GPIO_TogglePin(GPIO_Port_t port, unsigned char pin);

//reads current pin state
GPIO_PinState_t GPIO_ReadPin(GPIO_Port_t port, unsigned char pin);

#endif
