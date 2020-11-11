#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include "Events.hpp"
#include "IEventGenerator.hpp"

class EventGenerator : public IEventGenerator
{
public:
    EventGenerator();

    Events GetEvent();

private:
};

#endif