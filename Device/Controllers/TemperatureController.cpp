//
// Created by Samuel Mcmurray on 10/18/2021.
//

#include "TemperatureController.h"
#include "../Models/Thermometer.h"

/**
 *
 * @param thermometersIn (Thermometer)[]: The thermometers array for the indoors.
 * @param radiators (Radiators)[]: The radiators array.
 * @param thermometerOut (Thermometer): The outdoors thermometer.
 */
TemperatureController::TemperatureController(Thermometer thermometersIn[], Radiator radiators[], Thermometer thermometerOut) {
    int size = sizeof(&thermometersIn)/ sizeof(&thermometersIn[0]);
    for (int i = 0; i < size; ++i) {
        TemperatureController::thermometersIn[i] = &thermometersIn[i];
        TemperatureController::radiators[i] = &radiators[i];
        TemperatureController::desiredTemp = 20;
    }
    TemperatureController::thermometerOut = thermometerOut;
}

/**
 * A setter function fot the desireTemp variable.
 * @param temp (double): The users desired temperature for the corresponding room
 * @return (Response): A response to send back to the server.
 */
Response TemperatureController::setDesiredTemp(double temp) {
    TemperatureController::desiredTemp = temp;
    Response response{200, "Success"};
    return response;
}

/**
 * A getter function for the desiredTemp variable.
 * @return (double): returns a double of the current desired temp value.
 */
double TemperatureController::getDesiredTemp() {
    return desiredTemp;
}

/**
 * This function handles the control of the radiators according to desired temp and the current temp
 * within the smart house, the indexs of the arrays correspond to one another.
 * @return (Response): A response is returned based on the
 */
Response TemperatureController::runTempController() {

}
