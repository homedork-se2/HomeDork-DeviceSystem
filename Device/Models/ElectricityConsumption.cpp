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
    float kw = voltage * 4;

    return kw;
}

void ElectricityConsumption::readSensor() {
<<<<<<< HEAD
    Response response;
    char electricity[11] = {'e', 'l', 'e', 'c', 't', 'r', 'i', 'c', 'i', 't', 'y'};
    float electricUsage = getElectricUsage();
    response.createMessage(String(electricity), 11, String(getId()), 2, String(electricUsage),3);
    delay(100);
=======
    Response response{400, "ERROR"};
    response.createMessage("Electricity:", String(getId()), String(getElectricUsage()));
    delay(10);
>>>>>>> 40d52950655ecf9ddec15aa4122625812e38c356
    response.sendMessage();
}