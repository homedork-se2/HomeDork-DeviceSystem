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
Response DeviceController::runListen() {
    Request request;
    while (true) {
        int BUFFER_SIZE = Serial.available();
        char buf[BUFFER_SIZE];
        if (BUFFER_SIZE > 0) {
            for (int i = 0; i < BUFFER_SIZE; ++i) {
                int length = Serial.readBytes(buf, BUFFER_SIZE);

            }
            request.parseRequest(buf);
            _response = handleRequest(request);
            return _response;
            break;
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
            size = 3;
            for (int i = 0; i < size; ++i) {
                if (_lights[i].getId() == request.getId()) {
                    _response = _lights[i].handleLightSwitch(request);
                    int length = _response.getMessage().length();
                    byte buf[length];
                    String string = _response.getMessage();
                    string.getBytes(buf, length);

                    Serial.write(buf, length);
                    break;
                }
            }
            break;
        case 2:
            size = 2;
            for (int i = 0; i < size; ++i) {
                if (_fans[i].getId() == request.getId()) {
                    _response = _fans[i].handleFanSwitch(request.isState());
                    break;
                }
            }
            break;
        case 3:
            size = 2;
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
                    _response = _windows[i].handleWindowSwitch();
                    break;
                }
            }
            break;
    }

    return _response;
}
