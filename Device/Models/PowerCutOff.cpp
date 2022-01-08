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
PowerCutOff::PowerCutOff(unsigned int id): Sensor(id){

}

void PowerCutOff::readSensor() {
    int supplyVoltage = readAnalogSensor();
    if (supplyVoltage == 12) {
        handlePowerCutOff();
    }
}

/**
 * The function that will handle the power cut off.
 * @return (Response): A response to be sent back to the server.
 */
void PowerCutOff::handlePowerCutOff(){
<<<<<<< HEAD
    Response response;
    char powerCutOff[11] = {'p', 'o', 'w', 'e', 'r', 'C', 'u', 't', 'O', 'f', 'f'};
    char triggered[9] = {'t', 'r', 'i', 'g', 'g', 'e', 'r', 'e', 'd'};
    response.createMessage(String(powerCutOff), 11, String(getId()), 2, String(triggered), 9);
    delay(100);
=======
    Response response{200, "PowerCutOff:Triggered"};
    delay(10);
>>>>>>> 40d52950655ecf9ddec15aa4122625812e38c356
    response.sendMessage();
}


