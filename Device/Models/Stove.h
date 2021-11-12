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
#include "Device.h"
#include "Arduino.h"
#include "../Util/Response.h"
#include "Sensor.h"


class Stove: public Sensor{
/**
    * A class that represent a Stove in a smart home this class inherits from Abstract Device class.
    *
    * Attributes:
    *      @param id an integer who's value is the id of an instance of a subclass device.
    *
    * Methods:
     *       Methods:
     *       handleStoveSwitch: handles when Stove change mode.
    *
    * **/
public:
    Stove();
    explicit Stove(unsigned int id);
    Response handleStoveSwitch(bool isActive);
};


#endif //HOMEDORK_DEVICESYSTEM_STOVE_H
