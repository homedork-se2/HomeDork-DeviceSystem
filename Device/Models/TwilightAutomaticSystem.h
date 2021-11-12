//-----------------------------------------------------------------------
// File: TwilightAutomaticSystem.h
// Summary: A class that represents a water leakage sensor in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Osas
//-----------------------------------------------------------------------
// Log: 2021-11-05 Created the file,
//-----------------------------------------------------------------------
#ifndef HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
#define HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
#include "Arduino.h"
#include "Device.h"
#include "Sensor.h"
#include "Light.h"


class TwilightAutomaticSystem {
/**
 * A class that represent a TwilightAutomaticSystem in a smart home this class is a composite class
 * that represents an automatic light control for the outdoor light.
 *
 * Attributes:
 *      @param id an integer who's value is the id of an instance of a subclass device.
 * Methods:
**/


private:
    Sensor lightSensor;
    Light outdoorLight;
public:
    TwilightAutomaticSystem(Sensor sensor, Light outdoorLight);
    bool getSensorState();
    Response handleTwilightSystem();

};


#endif //HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
