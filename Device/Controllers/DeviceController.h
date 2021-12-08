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
    Alarm _securityAlarm;
    Curtains  * _curtains;
    Fan * _fans;
    Light *_lights;
    Response _response;
    Stove _stove;
    TemperatureController _temperatureController;
    Timer * _timers;
    TwilightAutomaticSystem _twilightSystem;
    Window * _windows;



public:
    DeviceController(Alarm securityAlarm, Curtains * curtains, Fan * fans, Light * lights, Response response, Stove stove,
                     TemperatureController temperatureController, Timer * timers, TwilightAutomaticSystem twilightSystem, Window * windows);
    void initializeDevices();
    void runListen();
    Response handleRequest(Request request);
};

#endif //HOMEDORK_DEVICESYSTEM_DEVICECONTROLLER_H
