//-----------------------------------------------------------------------
// File: Sensor.cpp
// Summary: A class that represents a Sensor in a smart home this class
// inherits from Abstract Device class, either reads digital or analog
// based off the needs of the subclass.
// Version: 1.0
// Owner: Osayomore Edugie
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_SENSOR_H
#define HOMEDORK_DEVICESYSTEM_SENSOR_H
#include "Device.h"
#include "Arduino.h"

class Sensor : public Device{
public :
    Sensor();
    Sensor(unsigned int id);
    float readDigitalSensor();
    float readAnalogSensor();
};

#endif //HOMEDORK_DEVICESYSTEM_SENSOR_H
