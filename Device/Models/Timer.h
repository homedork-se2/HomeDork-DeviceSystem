//-----------------------------------------------------------------------
// File: Timer.h
// Summary: A class that represents a Timer system in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-25 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_TIMER_H
#define HOMEDORK_DEVICESYSTEM_TIMER_H

#include "Device.h"

class Timer: public Device {
private:
    unsigned int muxPins[4]{};
public:
    Timer(unsigned int id, const unsigned int * muxPins);

};

#endif //HOMEDORK_DEVICESYSTEM_TIMER_H
