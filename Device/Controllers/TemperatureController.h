//-----------------------------------------------------------------------
// File: TemperatureController.cpp
// Summary: Monitors the te,perature read by the thermometers and sends
// a request to the server for updates state changes.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-18 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H

#include <Arduino.h>
#include <DeviceController.h>
#include <Radiator.h>
#include <Response.h>
#include <Thermometer.h>

class TemperatureController {
private:
    float _desiredTemp;
    Thermometer * _thermometersIn;
    Thermometer _thermometerOut;
    Radiator * _radiators;

public:
    TemperatureController(Thermometer * thermometersIn, Radiator * radiators, Thermometer thermometerOut);
    void setDesiredTemp(float desiredTemp);
    float getDesiredTemp();
    void runTempController();
    bool shouldRun();
};

#endif //HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
