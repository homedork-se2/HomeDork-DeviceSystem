//
// Created by Dell on 11/5/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H
#define HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H
#include "Arduino.h"
#include "Device.h"
#include "Response.h"


class ElectricityConsumption : Device {

public:
    ElectricityConsumption(int id);
    Response getElectricUsage()

};


#endif //HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H