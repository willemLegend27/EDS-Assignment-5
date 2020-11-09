#ifndef MCP_HPP
#define MCP_HPP

#include <vector>
#include <string>

class MCP
{

private:
    std::vector<std::string> LEDPins = {"PA10,PB3"};
    std::vector<std::string> ButtonPins;

public:
    MCP();
    ~MCP();
    void TurnOnLed(int LEDNumber);
    void TurnOffLed(int LEDNumber);

private:
    void ConfigureOutputPins();
    void ConfigureInputPins();
};

#endif