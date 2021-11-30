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
    Sensor _lightSensor;
    Light _outdoorLight;
public:
    TwilightAutomaticSystem(Sensor sensor, Light outdoorLight);
    bool getSensorState();
    Response handleTwilightSystem(Request request);

};

#endif //HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
