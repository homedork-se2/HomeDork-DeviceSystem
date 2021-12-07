//-----------------------------------------------------------------------
// File: PowerCutOff.h
// Summary: A class that represents a power cut off sensor in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Mustafa Ismail
//-----------------------------------------------------------------------
// Log: 2021-11-01 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H
#define HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>

class PowerCutOff : public Device{
public :
    explicit PowerCutOff(unsigned int id);
    Response handlePowerCutOff();
    void readPowerCutOffSensor();

};

#endif //HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H
