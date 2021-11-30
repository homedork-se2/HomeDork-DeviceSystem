//-----------------------------------------------------------------------
// File: Sensor.h
// Summary: A class that represents a Input sensor in a smart home this
// class inherits from Abstract Device class.
// Version: 1.0
// Owner: Osayomore Edugie
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_SENSOR_H
#define HOMEDORK_DEVICESYSTEM_SENSOR_H

#include <Arduino.h>
#include <Device.h>

class Sensor : public Device{
public :
    Sensor(unsigned int id);
    float readDigitalSensor();
    float readAnalogSensor();
};

#endif //HOMEDORK_DEVICESYSTEM_SENSOR_H
