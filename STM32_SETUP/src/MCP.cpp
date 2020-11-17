#include "MCP.hpp"
#include "gpio.h"

MCP::MCP(IEventGenerator &eventGenerator, LED &led1, LED &led2, Button &btn1, Button &btn2) : eventGenerator(eventGenerator), led1(led1), led2(led2), btn1(btn1), btn2(btn2)
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
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER3) | (0b01 << GPIO_MODER_MODER3_Pos); //ouput
    GPIOB->OTYPER &= ~GPIO_OTYPER_OT_3;

    //onboard PA5
    GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER5) | (0b01 << GPIO_MODER_MODER5_Pos); //output
    GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5;
}

void MCP::ConfigureInputPins()
{
    //PB5 , PB4
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER5) | (0b00 << GPIO_MODER_MODER5_Pos); //input
    GPIOB->PUPDR = (GPIOB->PUPDR & ~GPIO_PUPDR_PUPDR5) | (0b01 << GPIO_PUPDR_PUPDR5_Pos); //pullup
    GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER4) | (0b00 << GPIO_MODER_MODER4_Pos); //input
    GPIOB->PUPDR = (GPIOB->PUPDR & ~GPIO_PUPDR_PUPDR4) | (0b01 << GPIO_PUPDR_PUPDR4_Pos); //pullup

    //onboard PC13
    GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER13) | (0b00 << GPIO_MODER_MODER13_Pos); //input
    GPIOC->PUPDR = (GPIOC->PUPDR & ~GPIO_PUPDR_PUPDR13) | (0b01 << GPIO_PUPDR_PUPDR13_Pos); //pullup
}

void MCP::ConfigureInterruptPins()
{
    //PB4
    SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] & ~SYSCFG_EXTICR2_EXTI4) | (0b001 << SYSCFG_EXTICR2_EXTI4_Pos);
    EXTI->FTSR = EXTI_FTSR_TR4;
    EXTI->RTSR = EXTI_RTSR_TR4;
    NVIC_EnableIRQ(EXTI4_IRQn);
    EXTI->IMR |= EXTI_IMR_MR4;

    //PB5
    SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] & ~SYSCFG_EXTICR2_EXTI5) | (0b001 << SYSCFG_EXTICR2_EXTI5_Pos);
    EXTI->FTSR |= EXTI_FTSR_TR5;
    EXTI->RTSR |= EXTI_RTSR_TR5;
    NVIC_EnableIRQ(EXTI9_5_IRQn);
    EXTI->IMR |= EXTI_IMR_MR5;

    //onboard PC13
    SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] & ~SYSCFG_EXTICR4_EXTI13) | (0b010 << SYSCFG_EXTICR4_EXTI13_Pos);
    EXTI->FTSR = EXTI_FTSR_TR13;
    EXTI->RTSR = EXTI_RTSR_TR13;
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    EXTI->IMR |= EXTI_IMR_MR13;
}

int MCP::TurnOnLed(LED &led)
{
    led.ON();
}

int MCP::TurnOffLed(LED &led)
{
    led.OFF();
}
