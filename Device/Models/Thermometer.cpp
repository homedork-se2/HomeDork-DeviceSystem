//-----------------------------------------------------------------------
// File: Thermometer.cpp
// Summary: A class that represents a Light in a smart home this class
// inherits from Abstract Device class.
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//      2021-10-18 Revised by Mustafa Ismail, added functionality to the
//      thermomter reading methods.
//-----------------------------------------------------------------------

#include "Thermometer.h"

/**
 * The constructor of the Thermometer class
 * @param id (unsigned int): an unsigned integer who's value is the id
 * of a thermometer device.
 */
Thermometer::Thermometer(unsigned int id) :Sensor(id){
}

double Thermometer::getCurrentTemp() {
    if (getId() == A1 || getId() == A2){

        _currentTemp = readTempIn();
        _currentTemp = _currentTemp * 0.48828125;
    } else {
        _currentTemp = readTempOut();
        _currentTemp = _currentTemp * 0.48828125;
    }

    return _currentTemp;
}

/**
 * The function that handles the reading of the sensor for one of the
 * inside thermometers.
 * @return
 */
double Thermometer::readTempIn() {
    float value = readAnalogSensor();
    return value;
}

/**
 * Handles the reading of the sensor for the outside thermometer.
 * @return The outdoor temperature value as a double.
 */
double Thermometer::readTempOut() {
    float value = readDigitalSensor();
    return value;
}
