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
#include "../Models/ElectricityConsumption.h"
#include "../Models/PowerCutOff.h"
#include "../Models/Stove.h"
#include "../Models/TwilightAutomaticSystem.h"
#include "../Models/WaterLeakage.h"
#include "../Models/Window.h"
#include "../Util/Response.h"

class SensorController {
private:
    ElectricityConsumption electricityConsumption;
    PowerCutOff powerCutOff;
    Stove stove;
    TwilightAutomaticSystem twilightAutomaticSystem;
    WaterLeakage waterLeakage;
    Window windows[];
public:
    SensorController(ElectricityConsumption electricityConsumption, PowerCutOff powerCutOff,
                     Stove stove, TwilightAutomaticSystem twilightAutomaticSystem,
                     WaterLeakage waterLeakage, Window windows[]);

    Response runSensorController();
};


#endif //HOMEDORK_DEVICESYSTEM_TWILIGHTCONTROLLER_H
