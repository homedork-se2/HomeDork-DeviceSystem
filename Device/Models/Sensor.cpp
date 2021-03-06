//-----------------------------------------------------------------------
// File: Sensor.cpp
// Summary: A class that represents a Input sensor in a smart home this
// class inherits from Abstract Device class.
// Version: 1.0
// Owner: Osayomore Edugie
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//-----------------------------------------------------------------------

#include "Sensor.h"

/**
 * Sensor Constructor
 * @param id (unsigned int): Takes the pin of the respective sensor.
 */
Sensor::Sensor(unsigned int pin, int id): Device(pin, id) {
}

/**
 * This function handles the reading of the digital sensors.
 * @return (float): returns the value of the sensor to make calculations based
 * off the use case for the subclass.
 */
float Sensor::readDigitalSensor() {
    return digitalRead(this->getPin());
}

/**
 * This function handles the reading of the analog sensors.
 * @return (float): returns the value of the sensor to make calculations based
 * off the use case for the subclass.
 */
int Sensor::readAnalogSensor() {
    return analogRead(this->getPin());
}
