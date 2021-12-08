//-----------------------------------------------------------------------
// File: Radiator.h
// Summary: A class that represents a heating element in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-20 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_RADIATOR_H
#define HOMEDORK_DEVICESYSTEM_RADIATOR_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>

class Radiator: public Device {
private:
    unsigned int (&_muxPins)[4];
public:
    Radiator(unsigned int id, unsigned int (&muxPins)[4]);
    void adjustTemp(bool isCold);
};

#endif //HOMEDORK_DEVICESYSTEM_RADIATOR_H
