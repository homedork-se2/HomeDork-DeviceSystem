//-----------------------------------------------------------------------
// File: ElectricityConsumption.cpp
// Summary: A class that handles the reading of the electricity
// consumption in the smart home.
// Version: 1.0
// Owner: Osayamore Edugie
//-----------------------------------------------------------------------
// Log: 2021-11-5 Created the file.
//-----------------------------------------------------------------------

#include "ElectricityConsumption.h"

/**
 * The constructor for the ElectricityConsumption class a subclass of the
 * Sensor class.
 * @param id (unsigned int): The pin of the device represented as an id.
 */
ElectricityConsumption::ElectricityConsumption(unsigned int id) : Sensor(id) {

}

/**
 * The function handles the reading of the electricty consumption in the
 * home.
 * @return (Response): A response is returned to the server.
 */
float ElectricityConsumption::getElectricUsage() {
    int value = readAnalogSensor();
    float voltage = value * (5000 / 1024.0);
    float kwH = voltage * 4;

    return kwH;
}

void ElectricityConsumption::readSensor() {
    Response response{400, "ERROR"};
    response.createMessage("Electricity:", String(getId()), String(getElectricUsage()));
    response.sendMessage();
}