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
    Thermometer thermometerIn1;
    Radiator radiator1;
    Radiator radiator2;
public:
    TemperatureController(Thermometer thermometerIn1, Radiator radiator1, Radiator radiator2);
    void setDesiredTemp(double desiredTemp);
};


#endif //HOMEDORK_DEVICESYSTEM_TEMPERATURECONTROLLER_H
