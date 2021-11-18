//
// Created by Dell on 11/5/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H
#define HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H
#include <Arduino.h>
#include <Device.h>
#include <Response.h>
#include <Sensor.h>


class ElectricityConsumption : public Sensor {
public:

    explicit ElectricityConsumption(unsigned int id);
    Response getElectricUsage();

};


#endif //HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H