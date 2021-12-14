//-----------------------------------------------------------------------
// File: Thermometer.h
// Summary: A class that represents a Light in a smart home this class
// inherits from Abstract Device class.
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//      2021-10-18 Revised by Mustafa Ismail, added functionality to the
//      thermomter reading methods.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_THERMOMETER_H
#define HOMEDORK_DEVICESYSTEM_THERMOMETER_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>
#include <Sensor.h>

class Thermometer:public Sensor {

private:
    float _currentTemp;
    float readTempIn();
    float readTempOut();

public:
    Thermometer(unsigned int id);
    float getCurrentTemp();

};

#endif //HOMEDORK_DEVICESYSTEM_THERMOMETER_H
