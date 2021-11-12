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
 * Default constructor
 */
Stove::Stove() {

}

/**
 * The Stove constructor takes an id as a parameter subclass to the Sensor
 * class.
 * @param id (unsigned
 */
Stove::Stove(unsigned int id) : Sensor(id) {

}

/**
 *
 * @param isActive
 * @return
 */
Response Stove::handleStoveSwitch(bool isActive) {
    Response response;
    if (isActive) {
        setIsActive(true);
        response.setMessage("Stove is on");
        response.setStatusCode(200);
    } else{
        setIsActive(true);
        response.setMessage("Stove is off");
        response.setStatusCode(200);
    }

    return response;
}

void Stove::readStoveSensor() {
    float value = Stove::readDigitalSensor();
    if (value == 5) {
        handleStoveSwitch(true);
    } else {
        handleStoveSwitch(false);
    }
}
