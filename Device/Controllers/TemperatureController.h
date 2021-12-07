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
#include <Radiator.h>
#include <Response.h>
#include <Thermometer.h>

class TemperatureController {
private:
    double _desiredTemp;
    Thermometer * _thermometersIn;
    Thermometer _thermometerOut;
    Radiator * _radiators;
    unsigned long _fiveMinutes;

public:
    TemperatureController(Thermometer * thermometersIn, Radiator * radiators, Thermometer thermometerOut);
    Response setDesiredTemp(double desiredTemp);
    double getDesiredTemp();
    Response runTempController();

};

#endif //HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
