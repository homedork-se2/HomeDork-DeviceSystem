//-----------------------------------------------------------------------
// File: Stove.h
// Summary: A class that represents a Stove in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim
//-----------------------------------------------------------------------
// Log: 2021-10-28 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_STOVE_H
#define HOMEDORK_DEVICESYSTEM_STOVE_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>
#include <Sensor.h>

class Stove: public Sensor{
private:
    void handleStoveSwitch(bool isActive);
public:
    explicit Stove(unsigned int pin, int id);
    void readStoveSensor();

};

#endif //HOMEDORK_DEVICESYSTEM_STOVE_H
