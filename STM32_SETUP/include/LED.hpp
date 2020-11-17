#ifndef LED_HPP
#define LED_HPP

class LED
{
private:
    int ledNumber;

public:
    LED(int ledNumber);
    ~LED();
    void ON();
    void OFF();
    int GetState();

private:
};

#endif