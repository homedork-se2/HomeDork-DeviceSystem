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
void Stove::handleStoveSwitch(bool isActive) {
    Response response;
    char stove[5] = {'s', 't', 'o', 'v', 'e'};
    if(isActive && !getIsActive()){
        char state[2] = {'O', 'N'};
        response.createMessage(String(stove), 5, String(getId()), 2, String(state), 2);
        setIsActive(isActive);
    } else if (!isActive && getIsActive()){
        char state[3] = {'O', 'F', 'F'};
        response.createMessage(String(stove), 5, String(getId()), 2, String(state), 3);
        setIsActive(isActive);
    }
    delay(100);
    response.sendMessage();
}

/**
 * This function handles the reading of the stove sensor.
 */
void Stove::readStoveSensor() {
    if (readDigitalSensor() == HIGH && !getIsActive()) {
        handleStoveSwitch(true);
    } else if (readDigitalSensor() == LOW && getIsActive()){
        handleStoveSwitch(false);
    }
}
