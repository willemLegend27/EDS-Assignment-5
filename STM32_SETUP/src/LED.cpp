#include "LED.hpp"
#include "gpio.h"

LED::LED(int ledNumber) : ledNumber(ledNumber)
{
}
LED::~LED()
{
}
int LED::On()
{
    if (ledNumber == 0)
    {
        GPIOA->ODR |= GPIO_ODR_10;
        return 0;
    }
    else if (ledNumber == 1)
    {
        GPIOB->ODR |= GPIO_ODR_3;
        return 0;
    }
    return -1;
}
int LED::Off()
{
    if (ledNumber == 0)
    {
        GPIOA->ODR &= ~GPIO_ODR_10;
        return 0;
    }
    else if (ledNumber == 1)
    {
        GPIOB->ODR &= ~GPIO_ODR_3;
        return 0;
    }
    return -1;
}
States LED::GetState()
{
    States ledState = LED_OFF;
    return ledState;
}
