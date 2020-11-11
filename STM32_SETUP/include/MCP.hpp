#ifndef MCP_HPP
#define MCP_HPP

#include "LED.hpp"
#include "Button.hpp"
#include "IEventGenerator.hpp"

class MCP
{

private:
    IEventGenerator &eventGenerator;
    LED &led1;
    LED &led2;
    Button &btn1;
    Button btn2;

public:
    MCP(IEventGenerator &eventGenerator, LED &led1, LED &led2, Button &btn1, Button &btn2);
    ~MCP();
    int TurnOnLed(LED &led);
    int TurnOffLed(LED &led);
    int GetLedState(LED &led);

private:
    void ConfigureOutputPins();
    void ConfigureInputPins();
    void ConfigureInterruptPins();
};

#endif