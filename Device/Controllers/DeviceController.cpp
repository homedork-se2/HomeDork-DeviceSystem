//-----------------------------------------------------------------------
// File: DeviceController.cpp
// Summary: Reads a command from the hub, determines the device type, the
// id, state, and level. Handles the request by
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//      2021-11-10 Revised by Samuel Mcmurray added handle request function.
//      2021-12-06 Revised by Samuel Mcmurray fixed errors with
//-----------------------------------------------------------------------

#include "DeviceController.h"

/**
 * Device Controller Constructor
 * @param securityAlarm (Alarm): The device systems security alarm.
 * @param curtains (Curtains)[]: This is an array of the curtains in the device system.
 * @param fans (Fan)[]: This is an array of the fans in the device system.
 * @param lights (Light)[]: This is an array of the lights in the device system.
 * @param response (Response): The response for any request that is handled by the system.
 * @param stove (Stove): The device systems stove.
 * @param temperatureController (TemperatureController): The device systems Temperature contol unit.
 * @param timers (Timer)[]: This is an array of the timers in the device system.
 * @param twilightSystem (TwilightAutomaticSystem): The twilight automatic system for the smart house.
* @param windows (Window)[]: This is an array of the windows in the device system.
 */
DeviceController::DeviceController(Alarm securityAlarm, Curtains * curtains, Fan * fans, Light * lights, Response response, Stove stove,
                                   TemperatureController temperatureController, Timer * timers, TwilightAutomaticSystem twilightSystem,
                                   Window * windows): _securityAlarm(securityAlarm), _response(response), _stove(stove),
                                   _temperatureController(temperatureController), _twilightSystem(twilightSystem), _curtains(curtains), _fans(fans), _lights(lights),
                                    _timers(timers), _windows(windows){


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
void DeviceController::runListen() {
    Request request;
    int count = 0;
    while (Serial.available() > 0) {
        byte incomingByte = 0;
        byte buf[65];
        incomingByte = Serial.read();
        buf[count] = incomingByte;
    }
    request.parseRequest(buf);
    handleRequest(request);

}

/**
 * This function handles the request from the server.
 * @param request (Request): The request made by the server.
 * @return response (Response): The response is returned and the values based on the completion and
 * success of the command.
 */
void DeviceController::handleRequest(Request request) {
    int size = 0;
    switch (request.getDeviceType()) {
        case 1:
            size = 3;
            for (int i = 0; i < size; ++i) {
                if (_lights[i].getId() == request.getId()) {
                    _lights[i].handleLightSwitch(request);
                    break;
                }
            }
            break;
        case 2:
            size = 2;
            for (int i = 0; i < size; ++i) {
                if (_fans[i].getId() == request.getId()) {
                    _fans[i].handleFanSwitch(request);
                    break;
                }
            }
            break;
        case 3:
            size = 2;
            for (int i = 0; i < size; ++i) {
                if (_curtains[i].getId() == request.getId()) {
                    _curtains[i].handleCurtainSwitch(request.isState());
                    break;
                }
            }
            break;
        case 4:
            _securityAlarm.setAlarm(request.isState());
            break;
        case 5:
            _temperatureController.setDesiredTemp(request.getValue());
            break;
        case 6:
            //twilight
            break;
        case 7:
            size = 2;
            for (int i = 0; i < size; ++i) {
                if (_timers[i].getId() == request.getId()) {
                    //add timer call
                    break;
                }
            }
        case 8:
            size = 2;
            for (int i = 0; i < size; ++i) {
                if (_windows[i].getId() == request.getId()) {
                    _windows[i].handleWindowSwitch(request.isState());
                    break;
                }
            }
            break;
    }
}
