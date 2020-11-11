#ifndef LED_HPP
#define LED_HPP

class LED
{
private:
    int ledNumber;

public:
    LED(int ledNumber);
    ~LED();
    int ON();
    int OFF();
    int GetState();

private:
};

#endif