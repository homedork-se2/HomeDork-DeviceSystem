//-----------------------------------------------------------------------
// File: DeviceController.cpp
// Summary: Reads a command from the hub, determines the device type, the
// id, state, and level. Handles the request by
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
// 2021-11-10 Revised by Samuel Mcmurray added handle request function.
//-----------------------------------------------------------------------


#include "DeviceController.h"

/**
 * Device Controller Constructor
 * @param securityAlarm (Alarm): The device systems security alarm.
 * @param curtains (Curtains)[]: This is an array of the curtains in the device system.
 * @param electricityConsumption  (ElectricityConsumption): The device systems electricy consumption monitor.
 * @param fans (Fan)[]: This is an array of the fans in the device system.
 * @param lights (Light)[]: This is an array of the lights in the device system.
 * @param powerCutOff (PowerCutOff): This device systems power cut off device.
 * @param response (Response): The response for any request that is handled by the system.
 * @param stove (Stove): The device systems stove.
 * @param temperatureController (TemperatureController): The device systems Temperature contol unit.
 * @param timers (Timer)[]: This is an array of the timers in the device system.
 * @param twilightSystem (TwilightAutomaticSystem): The twilight automatic system for the smart house.
 * @param windows (Curtains)[]: This is an array of the curtains in the device system.
 */
DeviceController::DeviceController(Alarm securityAlarm, Curtains curtains[], ElectricityConsumption electricityConsumption, Fan fans[], Light lights[], PowerCutOff powerCutOff,
                                   Response response, Stove stove, TemperatureController temperatureController, Timer timers[], TwilightAutomaticSystem twilightSystem, Window windows[]) {
    DeviceController::securityAlarm = securityAlarm;
    DeviceController::electricityConsumption = electricityConsumption;
    DeviceController::powerCutOff = powerCutOff;
    DeviceController::response = response;
    DeviceController::stove = stove;
    DeviceController::temperatureController = temperatureController;
    DeviceController::twilightSystem = twilightSystem;
    int count = 0;
    for (Curtains curtain: curtains) {
        DeviceController::curtains[count] = curtain;
        count++;
    }
    //TODO: Either Figure out a way to create a generic function to assign the arrays or do each individually
}

/**
 * TODO: set up the all of the devices states on startup. By requesting from the DB
 */
void DeviceController::initializeDevices() {

}

/**
 * This function listens for a request from the server
 * @return response (Response): A response is returned upon completion of the command.
 */
Response DeviceController::runListen() {
    Request request;
    while (true) {
        const int BUFFER_SIZE = 50;
        char buf[BUFFER_SIZE];

        if (Serial.available() > 0) {
            int len = Serial.readBytes(buf, BUFFER_SIZE);
            request.createRequest(&buf);
            response = handleRequest(request);
            return response;
        }
    }
}

/**
 * This function handles the request from the server.
 * @param request (Request): The request made by the server.
 * @return response (Response): The response is returned and the values based on the completion and
 * success of the command.
 */
Response DeviceController::handleRequest(Request request) {
    response.setStatusCode(404);
    response.setMessage("Device Does Not Exist");
    switch (request.getDeviceType().toLowerCase()) {
        case "lamp":
            for (Light light: lights) {
                if (light.getId() == request.getId()) {
                    response = light.handleLightSwitch(request);
                    break;
                }
            }
            break;
        case "fan":
            for (Fan fan: fans) {
                if (fan.getId() == request.getId()) {
                    response = fan.handleFanSwitch();
                    break;
                }
            }
            break;
        case "curtain":
            for (Curtains curtain: curtains) {
                if (curtain.getId() == request.getId()) {
                    response = curtain.handleCurtainSwitch();
                    break;
                }
            }
            break;
        case "alarm":
            response = securityAlarm.setAlarm();
            break;
        case "tempcontrol":
            response = temperatureController.setDesiredTemp(request.getValue());
            break;
        case "twilight":
            response = twilightSystem.handleTwilightSystem(request.isState());
            break;
        case "timer":
            for (Timer timer: timers) {
                if (timer.getId() == request.getId()) {
                    //add timer call
                    break;
                }
            }
        case "window":
            for (Window window: windows) {
                if (window.getId() == request.getId()) {
                    response = window.handleWindowSwitch();
                    break;
                }
            }
            break;
        case "electricty":
            response = electricityConsumption.getElectricUsage();
            break;
        case "power":
            response = powerCutOff.handlePowerCutOff();
            break;
    }

    return response;
}


