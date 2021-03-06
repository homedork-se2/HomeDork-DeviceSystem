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
#include <Response.h>
#include <Sensor.h>

class PowerCutOff : public Sensor{
private:
    void handlePowerCutOff();
public :
    explicit PowerCutOff(unsigned int pin, int id);
    void readSensor();


};

#endif //HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H
