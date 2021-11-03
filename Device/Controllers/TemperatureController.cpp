//
// Created by Samuel Mcmurray on 10/18/2021.
//

#include "TemperatureController.h"
#include "../Models/Thermometer.h"

TemperatureController::TemperatureController(Thermometer thermometerIn1, Radiator radiator1, Radiator radiator2) {
    this->thermometerIn1 = thermometerIn1;
    this->radiator1 = radiator1;
    this->radiator2 = radiator2;
}

void TemperatureController::setDesiredTemp(double desiredTemp) {
    this->desiredTemp = desiredTemp;
}
