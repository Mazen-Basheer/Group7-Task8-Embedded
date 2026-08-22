#ifndef PRIVATE_H
#define PRIVATE_H



#define ADC1_BASE_ADDRESS      0x40012000

#define ADC1_CR1               volatile uint32_t *(ADC1_BASE_ADDRESS + 0x04))
#define ADC1_CR2               volatile uint32_t *(ADC1_BASE_ADDRESS + 0x08))
#define ADC1_SMPR2             volatile uint32_t *(ADC1_BASE_ADDRESS + 0x10))
#define ADC1_SQR1              volatile uint32_t *(ADC1_BASE_ADDRESS + 0x2C))
#define ADC1_SQR3              volatile uint32_t *(ADC1_BASE_ADDRESS + 0x34))
#define ADC1_DR                volatile uint32_t *(ADC1_BASE_ADDRESS + 0x4C))





#endif