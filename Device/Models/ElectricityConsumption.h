//-----------------------------------------------------------------------
// File: ElectricityConsumption.h
// Summary: A class that handles the reading of the electricity
// consumption in the smart home.
// Version: 1.0
// Owner: Osayamore Edugie
//-----------------------------------------------------------------------
// Log: 2021-11-5 Created the file.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H
#define HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>
#include <Sensor.h>

class ElectricityConsumption : public Sensor {
private:
    float getElectricUsage();

public:
    ElectricityConsumption(unsigned int id);
    void readSensor();

};

#endif //HOMEDORK_DEVICESYSTEM_ELECTRICITYCONSUMPTION_H
