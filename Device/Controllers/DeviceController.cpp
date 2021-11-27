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
                                   Response response, Stove stove, TemperatureController temperatureController, Timer timers[], TwilightAutomaticSystem twilightSystem, Window windows[])
                                   : _securityAlarm(securityAlarm), _electricityConsumption(electricityConsumption), _powerCutOff(powerCutOff), _response(response), _stove(stove),
                                     _temperatureController(temperatureController), _twilightSystem(twilightSystem) {

    int size = sizeof(&curtains) / sizeof(&curtains[0]);
    for (int i = 0; i < size; ++i) {
        _curtains[i] = curtains[i];
        _fans[i] = fans[i];
        _lights[i] = lights[i];
        _timers[i] = timers[i];
        _windows[i] = windows[i];
    }
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
            request.parseRequest(&buf);
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
    int size = 0;
    switch (request.getDeviceType()) {
        case 1:
            size = sizeof(&lights) / sizeof(&lights[0]);
            for (int i = 0; i < size; ++i) {
                if (lights[i].getId() == request.getId()) {
                    response = lights[i].handleLightSwitch(request);
                    break;
                }
            }
            break;
        case 2:
            size = sizeof(&fans) / sizeof(&fans[0]);
            for (int i = 0; i < size; ++i) {
                if (fans[i].getId() == request.getId()) {
                    response = fans[i].handleFanSwitch();
                    break;
                }
            }
            break;
        case 3:
            size = sizeof(&curtains) / sizeof(&curtains[0]);
            for (int i = 0; i < size; ++i) {
                if (curtains[i].getId() == request.getId()) {
                    response = curtains[i].handleCurtainSwitch();
                    break;
                }
            }
            break;
        case 4:
            response = securityAlarm.setAlarm(request);
            break;
        case 5:
            response = temperatureController.setDesiredTemp(request.getValue());
            break;
        case 6:
            response = twilightSystem.handleTwilightSystem(request);
            break;
        case 7:
            for (Timer timer: timers) {
                if (timer.getId() == request.getId()) {
                    //add timer call
                    break;
                }
            }
        case 8:
            size = sizeof(&windows) / sizeof(&windows[0]);
            for (int i = 0; i < size; ++i) {
                if (windows[i].getId() == request.getId()) {
                    response = window.handleWindowSwitch();
                    break;
                }
            }
            break;
        case 9:
            response = electricityConsumption.getElectricUsage();
            break;
        case 10:
            response = powerCutOff.handlePowerCutOff();
            break;
    }

    return response;
}


