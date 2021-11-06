//
// Created by Mustafa on 2021-10-18.
//

#ifndef HOMEDORK_DEVICESYSTEM_THERMOMETER_H
#define HOMEDORK_DEVICESYSTEM_THERMOMETER_H

#include "Arduino.h"
#include "Device.h"
#include "../Util/Response.h"

class Thermometer:public Device {
/**
     * An class that represents the Thermometer in a smart home this class inherits from the Abstract Device class.
     *
     * Attributes:
     *      @param id an unsigned integer who's value is the id of a thermometer device.
     *      @param pin an integer who's value is the pin location on the Arduino device.
     *      @param currentTemp a double that stores the realtime value of temperature.
     *
     * Methods:
     *      The Thermometer class also has access to the Device class methods.
     *      getCurrentTemp returns a double whose value is the current temperature.
     *      setCurrentTemp returns a response that takes an integer as a parameter and sets the current temperature.
     *      readTempIn returns the inside temperature value.
     *      readTempOut returns the outside temperature value.
     *
     * **/

private:
    double currentTemp{};
public:
    Thermometer(unsigned int id);
    double getCurrentTemp();
    Response setCurrentTemp(int currentTemp);
    double readTempIn();
    double readTempOut();
};


#endif //HOMEDORK_DEVICESYSTEM_THERMOMETER_H
