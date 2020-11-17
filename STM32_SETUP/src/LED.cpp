#include "LED.hpp"
#include "gpio.h"

LED::LED(int ledNumber) : ledNumber(ledNumber)
{
}
LED::~LED()
{
}
void LED::ON()
{
    if (ledNumber == 1)
    {
        GPIOA->ODR |= GPIO_ODR_10;
    }
    else if (ledNumber == 2)
    {
        GPIOA->ODR |= GPIO_ODR_5;
    }
}
void LED::OFF()
{
    if (ledNumber == 1)
    {
        GPIOA->ODR &= ~GPIO_ODR_10;
    }
    else if (ledNumber == 2)
    {
        GPIOA->ODR &= ~GPIO_ODR_5;
    }
}
int LED::GetState()
{
    if (ledNumber == 1)
    {
        if ((GPIOA->IDR & GPIO_IDR_10) == 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else if (ledNumber == 2)
    {
        if ((GPIOA->IDR & GPIO_IDR_5) == 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    return -1;
}
