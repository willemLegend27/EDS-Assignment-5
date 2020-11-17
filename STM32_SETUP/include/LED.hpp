#ifndef LED_HPP
#define LED_HPP

#include "States.hpp"

class LED
{
private:
    int ledNumber;

public:
    LED(int ledNumber);
    ~LED();
    int On();
    int Off();
    States GetState();
private:
};

#endif