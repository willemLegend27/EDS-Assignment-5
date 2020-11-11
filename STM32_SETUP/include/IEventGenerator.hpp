#ifndef IEVENTGENERATOR_HPP
#define IEVENTGENERATOR_HPP

#include "Events.hpp"

class IEventGenerator
{
public:
    virtual ~IEventGenerator(){};

    virtual Events GetEvent() = 0;
};

#endif