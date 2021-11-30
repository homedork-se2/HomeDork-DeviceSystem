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
DeviceController::DeviceController(Alarm securityAlarm, Curtains (&curtains)[2], ElectricityConsumption electricityConsumption, Fan (&fans)[2], Light (&lights)[3], PowerCutOff powerCutOff,
                                   Response response, Stove stove, TemperatureController temperatureController, Timer (&timers)[2], TwilightAutomaticSystem twilightSystem, Window (&windows)[2])
                                   : _securityAlarm(securityAlarm), _electricityConsumption(electricityConsumption), _powerCutOff(powerCutOff), _response(response), _stove(stove),
                                     _temperatureController(temperatureController), _twilightSystem(twilightSystem), _curtains(curtains), _fans(fans), _lights(lights), _timers(timers),
                                     _windows(windows){

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
            request.parseRequest(&buf[BUFFER_SIZE]);
            _response = handleRequest(request);
            return _response;
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
    _response.setStatusCode(404);
    _response.setMessage("Device Does Not Exist");
    int size = 0;
    switch (request.getDeviceType()) {
        case 1:
            size = sizeof(_lights) / sizeof(_lights[0]);
            for (int i = 0; i < size; ++i) {
                if (_lights[i].getId() == request.getId()) {
                    _response = _lights[i].handleLightSwitch(request);
                    break;
                }
            }
            break;
        case 2:
            size = sizeof(_fans) / sizeof(_fans[0]);
            for (int i = 0; i < size; ++i) {
                if (_fans[i].getId() == request.getId()) {
                    _response = _fans[i].handleFanSwitch(request.isState());
                    break;
                }
            }
            break;
        case 3:
            size = sizeof(_curtains) / sizeof(_curtains[0]);
            for (int i = 0; i < size; ++i) {
                if (_curtains[i].getId() == request.getId()) {
                    _response = _curtains[i].handleCurtainSwitch(request.isState());
                    break;
                }
            }
            break;
        case 4:
            _response = _securityAlarm.setAlarm(request);
            break;
        case 5:
            _response = _temperatureController.setDesiredTemp(request.getValue());
            break;
        case 6:
            _response = _twilightSystem.handleTwilightSystem(request);
            break;
        case 7:
            size = sizeof(_timers) / sizeof(_timers[0]);
            for (int i = 0; i < size; ++i) {
                if (_timers[i].getId() == request.getId()) {
                    //add timer call
                    break;
                }
            }
        case 8:
            size = sizeof(_windows) / sizeof(_windows[0]);
            for (int i = 0; i < size; ++i) {
                if (_windows[i].getId() == request.getId()) {
                    _response = _windows[i].handleWindowSwitch();
                    break;
                }
            }
            break;
        case 9:
            _response = _electricityConsumption.getElectricUsage();
            break;
        case 10:
            _response = _powerCutOff.handlePowerCutOff();
            break;
    }

    return _response;
}


