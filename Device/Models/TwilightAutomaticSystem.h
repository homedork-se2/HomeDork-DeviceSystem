//-----------------------------------------------------------------------
// File: TwilightAutomaticSystem.h
// Summary: A class that represent a TwilightAutomaticSystem in a smart
// home this class is a composite class that represents an automatic
// light control for the outdoor light.
// Version: 1.0
// Owner: Osayamore Edugie
//-----------------------------------------------------------------------
// Log: 2021-11-05 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
#define HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H

#include <Arduino.h>
#include <Device.h>
#include <Light.h>
#include <Response.h>
#include <Request.h>
#include <Sensor.h>

class TwilightAutomaticSystem {
private:
    bool _isActive;
    bool change = false;
    Sensor _lightSensor;
    Light _outdoorLight;

    void handleTwilightSystem(bool state);
public:
    TwilightAutomaticSystem(Sensor sensor, Light outdoorLight);
    void readLightSensor();
    bool isActive();
    void setActive(bool isActive);
};

#endif //HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
