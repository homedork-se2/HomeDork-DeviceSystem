//-----------------------------------------------------------------------
// File: DeviceController.h
// Summary: Reads a command from the hub, determines the device type, the
// id, state, and level. Handles the request returns a response.
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
// 2021-11-10 Revised by Samuel Mcmurray added handle request function.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_DEVICECONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_DEVICECONTROLLER_H
#include "../Models/Alarm.h"
#include "../Models/Curtains.h"
#include "../Models/ElectricityConsumption.h"
#include "../Models/Fan.h"
#include "../Models/Light.h"
#include "../Models/PowerCutOff.h"
#include "../Models/Stove.h"
#include "../Models/Timer.h"
#include "../Util/Response.h"
#include "Arduino.h"
#include "TemperatureController.h"
#include "../Models/TwilightAutomaticSystem.h"
#include "../Models/Window.h"

class DeviceController {
private:
    Alarm securityAlarm;
    Curtains curtains[];
    ElectricityConsumption electricityConsumption;
    Fan fans[];
    Light lights[];
    PowerCutOff powerCutOff;
    Response response;
    Stove stove;
    TemperatureController temperatureController;
    Timer timers[];
    TwilightAutomaticSystem twilightSystem;
    Window windows[];
    Response handleRequest(Request request);

public:
    DeviceController(Alarm securityAlarm, Curtains curtains[], ElectricityConsumption electricityConsumption, Fan fans[], Light lights[], PowerCutOff powerCutOff,
                     Response response, Stove stove, TemperatureController temperatureController, Timer timers[], TwilightAutomaticSystem twilightSystem, Window windows[]);

    void initializeDevices();

    void runListen();

};


#endif //HOMEDORK_DEVICESYSTEM_DEVICECONTROLLER_H
