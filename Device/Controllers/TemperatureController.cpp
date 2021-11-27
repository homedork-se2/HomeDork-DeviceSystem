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
TemperatureController::TemperatureController(Thermometer thermometersIn[], Radiator radiators[], Thermometer thermometerOut) : _thermometerOut(thermometerOut)  {
    int size = sizeof(&thermometersIn)/ sizeof(&thermometersIn[0]);
    for (int i = 0; i < size; ++i) {
        _thermometersIn[i] = &thermometersIn[i];
        _radiators[i] = &radiators[i];
        _desiredTemp = 20;
    }
}

/**
 * A setter function fot the desireTemp variable.
 * @param temp (double): The users desired temperature for the corresponding room
 * @return (Response): A response to send back to the server.
 */
Response TemperatureController::setDesiredTemp(double temp) {
    _desiredTemp = temp;
    Response response{200, "Success"};
    return response;
}

/**
 * A getter function for the desiredTemp variable.
 * @return (double): returns a double of the current desired temp value.
 */
double TemperatureController::getDesiredTemp() {
    return _desiredTemp;
}

/**
 * This function handles the control of the radiators according to desired temp and the current temp
 * within the smart house, the indexs of the arrays correspond to one another.
 * @return (Response): A response is returned based on the
 */
Response TemperatureController::runTempController() {
    Response response{500, "Unknown Error Exited Loop"};
    while (true) {

        int size = sizeof(thermometersIn) / sizeof(thermometersIn[0]);
        for (int i = 0; i < size; ++i) {
            Response temp = thermometersIn[i].getCurrentTemp();
            if (temp.getStatusCode() > _desiredTemp) {
                _radiators[i].adjustTemp(false);
                //Serial.print("radiator off..");
            } else if (temp.getStatusCode() < desiredTemp) {
                _radiators[i].adjustTemp(true);
                //Serial.print("radiator on..");
            }

            delay(1000);
            if (_fiveMinutes <= millis()) {
                _fiveMinutes = millis() + 300000L;
            }
        }
    }

    return response;
}
