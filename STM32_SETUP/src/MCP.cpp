#include "MCP.hpp"
#include "gpio.h"

MCP::MCP()
{
    this->ConfigureOutputPins();
    this->ConfigureInputPins();
    this->ConfigureInterruptPins();
}

MCP::~MCP()
{
}

void MCP::ConfigureOutputPins()
{
    //PA10 , PB3
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER10) | (0b01 << GPIO_MODER_MODER10_Pos); //output
    GPIOA->OTYPER &= ~GPIO_OTYPER_OT_10;
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER3) | (0b01 << GPIO_MODER_MODER3_Pos); //output
    GPIOB->OTYPER &= ~GPIO_OTYPER_OT_3;
}

void MCP::ConfigureInputPins()
{
    //PB5 , PB4
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER5) | (0b00 << GPIO_MODER_MODER5_Pos); //input
    GPIOB->PUPDR = (GPIOB->PUPDR & ~GPIO_PUPDR_PUPDR5) | (0b01 << GPIO_PUPDR_PUPDR5_Pos); //pullup
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER4) | (0b00 << GPIO_MODER_MODER4_Pos); //input
    GPIOB->PUPDR = (GPIOB->PUPDR & ~GPIO_PUPDR_PUPDR4) | (0b01 << GPIO_PUPDR_PUPDR4_Pos); //pullup
}

void MCP::ConfigureInterruptPins()
{
    //PB5
    SYSCFG->EXTICR[2] = (SYSCFG->EXTICR[2] & ~SYSCFG_EXTICR2_EXTI5_PB) | (0b001 << SYSCFG_EXTICR2_EXTI5_Pos);
    EXTI->FTSR = EXTI_FTSR_TR2;
    EXTI->IMR = EXTI_IMR_MR2;
    NVIC_EnableIRQ(EXTI1_IRQn);
}

void MCP::TurnOnLed(int LEDNumber)
{
    if (LEDNumber == 1)
    {
        GPIOA->ODR |= GPIO_ODR_10;
    }
    else if (LEDNumber == 2)
    {
        GPIOB->ODR |= GPIO_ODR_3;
    }
}

void MCP::TurnOffLed(int LEDNumber)
{
    if (LEDNumber == 1)
    {
        GPIOA->ODR &= ~GPIO_ODR_10;
    }
    else if (LEDNumber == 2)
    {
        GPIOB->ODR &= ~GPIO_ODR_3;
    }
}
