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
DeviceController::DeviceController(AlarmController alarmController, Alarm securityAlarm, Curtains * curtains,
                                   Fan * fans, Light * lights, SensorController sensorController, Stove stove, TemperatureController temperatureController, Timer * timers, TwilightAutomaticSystem twilightSystem,
                                   Window * windows): _alarmController(alarmController), _securityAlarm(securityAlarm), _sensorController(sensorController), _stove(stove),
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
    noInterrupts();
    for (int i = 0; i < 30; ++i) {
        if (Serial.available() > 0) {
            Request request;
            request.parseRequest();
            handleRequest(request);
        }
        _alarmController.runAlarm();
        delay(100);
    }

    interrupts();

    _sensorController.runSensorController();
    _temperatureController.runTempController();
}

/**
 * This function handles the request from the server.
 * @param request (Request): The request made by the server.
 * @return response (Response): The response is returned and the values based on the completion and
 * success of the command.
 */
void DeviceController::handleRequest(Request request) {
    int key = request.getCommand();
    int size = 0;
    if (key == 11 || key == 20 ) {
        if (key == 11) {
            request.setId(11);
        } else {
            request.setId(20);
        }
        size = 3;
        for (int i = 0; i < size; ++i) {
            if (_lights[i].getId() == request.getId()) {
                _lights[i].handleLightSwitch(request);
                break;
            }
        }
    } else if (key == 10 ) {
        request.setId(10);
        size = 2;
        for (int i = 0; i < size; ++i) {
            if (_fans[i].getId() == request.getId()) {
                _fans[i].handleFanSwitch(request);
                break;
            }
        }
    } else if (key == 69) {
        _securityAlarm.setAlarm(request.isState());
    } else if (key == 70) {
        _twilightSystem.setActive(request.isState());
    }  else if (key == 100) {
        _temperatureController.setDesiredTemp(request.getValue());
    } else {
        Response response{404, "DC:404;"};
        response.sendMessage();
    }

}
