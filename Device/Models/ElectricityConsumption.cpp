//
// Created by Dell on 11/5/2021.
//

#include "ElectricityConsumption.h"


ElectricityConsumption::ElectricityConsumption(unsigned int id) : Sensor(id) {

}

Response ElectricityConsumption::getElectricUsage() {
    ElectricityConsumption::readAnalogSensor();
    Response response{200, "Success"};
    return response;
}