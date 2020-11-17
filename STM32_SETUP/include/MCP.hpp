#ifndef MCP_HPP
#define MCP_HPP

#include "LED.hpp"
#include "Button.hpp"
#include "IEventGenerator.hpp"
#include "States.hpp"

class MCP
{

private:
    IEventGenerator &eventGenerator;
    LED &led1;
    LED &led2;
    Button &btn1;
    Button btn2;
    State currentState;

public:
    MCP(IEventGenerator &eventGenerator, LED &led1, LED &led2, Button &btn1, Button &btn2);
    ~MCP();
    void TurnOnLed(LED &led);
    void TurnOffLed(LED &led);
    int GetLedState(LED &led);
    void HandleStateMachine1(Events ev);
    void HandleStateMachine2(Events ev);

private:
    void ConfigureOutputPins();
    void ConfigureInputPins();
    void ConfigureInterruptPins();
};

#endif