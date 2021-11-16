//-----------------------------------------------------------------------
// File: Sensor.cpp
// Summary: A class that represents a Siren in a smart home this class
// inherits from Abstract Device class and outputs a sound when active.
// Version: 1.0
// Owner: Osayomore Edugie
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//-----------------------------------------------------------------------
#include "Sensor.h"

/**
 * Default Constructor
 */
Sensor::Sensor() {

}

/**
 * Sensor Constructor
 * @param id (unsigned int): Takes the pin of the respective sensor.
 */
Sensor::Sensor(unsigned int id): Device(id) {
}

/**
 * This function handles the reading of the digital sensors.
 * @return (float): returns the value of the sensor to make calculations based
 * off the use case for the subclass.
 */
float Sensor::readDigitalSensor() {
    return digitalRead(getId());
}

/**
 * This function handles the reading of the analog sensors.
 * @return (float): returns the value of the sensor to make calculations based
 * off the use case for the subclass.
 */
float Sensor::readAnalogSensor() {
    return analogRead(getId());
}
