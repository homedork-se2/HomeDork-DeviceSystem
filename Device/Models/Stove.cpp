//-----------------------------------------------------------------------
// File: Stove.cpp
// Summary: A class that represents a Stove in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim
//-----------------------------------------------------------------------
// Log: 2021-10-28 Created the file,
//-----------------------------------------------------------------------

#include "Stove.h"

/**
 * The Stove constructor takes an id as a parameter subclass to the Sensor
 * class.
 * @param id (unsigned int): An integer who's value is the id of an instance of the subclass sensor.
 */
Stove::Stove(unsigned int id) : Sensor(id) {

}

/**
 * A function which handles when Stove changes states.
 * @param isActive (boolean): The new state is either active or inactive.
 * @return A response that will be sent to the server.
 */
Response Stove::handleStoveSwitch(bool isActive) {
    Response response{500, "Fail"};
    if (getIsActive()) {
        setIsActive(isActive);
        response.setMessage("Stove is on");
        response.setStatusCode(200);
    } else{
        setIsActive(isActive);
        response.setMessage("Stove is off");
        response.setStatusCode(200);
    }

    return response;
}

/**
 * This function handles the reading of the stove sensor.
 */
void Stove::readStoveSensor() {
    float value = Stove::readDigitalSensor();
    if (value == HIGH) {
        handleStoveSwitch(true);
    } else {
        handleStoveSwitch(false);
    }
}
