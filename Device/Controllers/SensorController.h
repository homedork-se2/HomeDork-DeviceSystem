//-----------------------------------------------------------------------
// File: SensorController.cpp
// Summary: Monitors the sensors of the devices and sends a request to
// the server when a devices state has changed.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_TWILIGHTCONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_TWILIGHTCONTROLLER_H

#include <ElectricityConsumption.h>
#include <PowerCutOff.h>
#include <Response.h>
#include <Stove.h>
#include <TwilightAutomaticSystem.h>
#include <WaterLeakage.h>
#include <Window.h>


class SensorController {
private:
    ElectricityConsumption _electricityConsumption;
    PowerCutOff _powerCutOff;
    Stove _stove;
    TwilightAutomaticSystem _twilightAutomaticSystem;
    WaterLeakage _waterLeakage;
    Window * _windows;
    unsigned long timeCounter = 0;

public:
    SensorController(ElectricityConsumption electricityConsumption, PowerCutOff powerCutOff,
                     Stove stove, TwilightAutomaticSystem twilightAutomaticSystem,
                     WaterLeakage waterLeakage, Window * windows);
    void runSensorController();

};

#endif //HOMEDORK_DEVICESYSTEM_TWILIGHTCONTROLLER_H
