//
// Created by Samuel Mcmurray on 10/18/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
#include "../Models/Thermometer.h"
#include "../Models/Radiator.h"
#include "Arduino.h"

class TemperatureController {
private:
    double desiredTemp;
    Thermometer thermometersIn[];
    Thermometer thermometerOut;
    Radiator radiators[];

public:
    TemperatureController(Thermometer thermometersIn[], Radiator radiators[], Thermometer thermometerOut);

    Response setDesiredTemp(double desiredTemp);

    double getDesiredTemp();

    Response runTempController();
};


#endif //HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
