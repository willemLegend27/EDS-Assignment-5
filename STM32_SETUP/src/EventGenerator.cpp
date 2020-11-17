#include "EventGenerator.hpp"

EventGenerator::EventGenerator()
{
}

Events EventGenerator::GetEvent()
{
    Events event = ButtonLongPress;
    return event;
}