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
    Response response{200, "desiredtemp:" + _thermometersIn[i].getId() + ":" + _desiredTemp};
    response.sendMessage();
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
    Response response{500, "ERROR"};
    float temp = _thermometerOut.getCurrentTemp();
    response.setMessage("temp:" + _thermometersOut.getId() + ":" + temp);
    response.sendMessage();
        int size = 2;
        for (int i = 0; i < size; ++i) {
            temp = _thermometersIn[i].getCurrentTemp();
            response.setMessage("temp:" + _thermometersIn[i].getId() + ":" + temp);
            response.sendMessage();
            if (temp > _desiredTemp) {
                _radiators[i].adjustTemp(false);
            } else if (temp < _desiredTemp) {
                _radiators[i].adjustTemp(true);
            }

        }
    }
}
