//-----------------------------------------------------------------------
// File: TemperatureController.cpp
// Summary: Monitors the te,perature read by the thermometers and sends
// a request to the server for updates state changes.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-18 Created the file,
//-----------------------------------------------------------------------

#include "TemperatureController.h"

/**
 *
 * @param thermometersIn (Thermometer)[]: The thermometers array for the indoors.
 * @param radiators (Radiators)[]: The radiators array.
 * @param thermometerOut (Thermometer): The outdoors thermometer.
 */
TemperatureController::TemperatureController(Thermometer * thermometersIn, Radiator * radiators, Thermometer thermometerOut) : _thermometerOut(thermometerOut), _desiredTemp(20),
                                            _thermometersIn(thermometersIn), _radiators(radiators){
}

/**
 * A setter function fot the desireTemp variable.
 * @param temp (double): The users desired temperature for the corresponding room
 * @return (Response): A response to send back to the server.
 */
void TemperatureController::setDesiredTemp(float temp) {
    _desiredTemp = temp;
    char tempString[4];
    dtostrf(temp, 2, 2, tempString);
    char desiredTemp[11] = {'d', 'e', 's', 'i', 'r', 'e', 'd', 'T', 'e', 'm', 'p'};
    char house[5] = {'h', 'o', 'u', 's', 'e'};
    Response response;
    response.createMessage(String(desiredTemp), 11, String(house), 2, String(tempString), 4);
}

/**
 * A getter function for the desiredTemp variable.
 * @return (double): returns a double of the current desired temp value.
 */
float TemperatureController::getDesiredTemp() {
    return _desiredTemp;
}

/**
 * This function handles the control of the radiators according to desired temp and the current temp
 * within the smart house, the indexs of the arrays correspond to one another.
 * @return (Response): A response is returned based on the
 */
void TemperatureController::runTempController() {
    Response response;
    if (TemperatureController::shouldRun()) {
        char name[4] = {'t', 'e', 'm', 'p'};
        float temp = _thermometerOut.getCurrentTemp();
        char idOut[8] = {'o', 'u', 't', 'd', 'o', 'o', 'r', 's'};
        response.createMessage(String(name), 4, String(idOut), 8, String(temp), 4);
        response.sendMessage();
    }

    int size = 2;
    for (int i = 0; i < size; ++i) {
        temp = _thermometersIn[i].getCurrentTemp();
        if (TemperatureController::shouldRun()) {
            response.createMessage(String(name), 4, String(i+1), 2, String(temp), 4);
            if (temp > _desiredTemp) {
                deviceController->shouldRun();
                _radiators[i].adjustTemp(false);
            } else if (temp < _desiredTemp) {
                deviceController->shouldRun();
                _radiators[i].adjustTemp(true);
            }
            response.sendMessage();
        }

    }
}

bool shouldRun() {
    if (Serial.available() > 0) {
        return false;
    }
    return true;
}
