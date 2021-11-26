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

#include <Alarm.h>
#include <Arduino.h>
#include <Curtains.h>
#include <ElectricityConsumption.h>
#include <Fan.h>
#include <Light.h>
#include <PowerCutOff.h>
#include <Response.h>
#include <Stove.h>
#include <TemperatureController.h>
#include <Timer.h>
#include <TwilightAutomaticSystem.h>
#include <Window.h>

class DeviceController {
private:
    Alarm securityAlarm;
    Curtains curtains[2];
    ElectricityConsumption electricityConsumption;
    Fan fans[2];
    Light lights[2];
    PowerCutOff powerCutOff;
    Response response;
    Stove stove;
    TemperatureController temperatureController;
    Timer timers[2];
    TwilightAutomaticSystem twilightSystem;
    Window windows[2];

    Response handleRequest(Request request);

public:
    DeviceController(Alarm securityAlarm, Curtains curtains[], ElectricityConsumption electricityConsumption, Fan fans[], Light lights[], PowerCutOff powerCutOff,
                     Response response, Stove stove, TemperatureController temperatureController, Timer timers[], TwilightAutomaticSystem twilightSystem, Window windows[]);
    void initializeDevices();
    void runListen();
};

#endif //HOMEDORK_DEVICESYSTEM_DEVICECONTROLLER_H
