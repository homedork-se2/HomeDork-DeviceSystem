//-----------------------------------------------------------------------
// File: PowerCutOff.cpp
// Summary: A class that represents a power cut off sensor in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Mustafa Ismail
//-----------------------------------------------------------------------
// Log: 2021-11-01 Created the file,
//-----------------------------------------------------------------------

#include "PowerCutOff.h"

/**
 * The constructor for the PowerCutOff class.
 * @param id (unsigned int): The id represents the pin value
 * of the power cut off device sensor.
 */
PowerCutOff::PowerCutOff(unsigned int pin, int id): Sensor(pin, id){

}

void PowerCutOff::readSensor() {
    int supplyVoltage = readAnalogSensor();
    if (supplyVoltage < 3) {
        handlePowerCutOff();
    }
}

/**
 * The function that will handle the power cut off.
 * @return (Response): A response to be sent back to the server.
 */
void PowerCutOff::handlePowerCutOff(){
    Response response{500, "ERROR;"};
    response.createMessage(String(getId()), String(1));
    response.sendMessage();
}


