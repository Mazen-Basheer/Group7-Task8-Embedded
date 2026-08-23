#ifndef PRIVATE_H
#define PRIVATE_H

#define ADC1_BASE_ADDRESS 0x40012000

#define ADC1_CR1 (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x04))
#define ADC1_CR2 (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x08))
#define ADC1_SMPR2 (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x10))
#define ADC1_SQR1 (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x2C))
#define ADC1_SQR3 (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x34))
#define RCC_APB2ENR (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x44))
#define ADC_CCR (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x04))
#define ADC_DR (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x4C))
#define ADC_SR (*(volatile unsigned int *)(ADC1_BASE_ADDRESS + 0x00))
#endif