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
//      2021-12-07 Revised added a check for time.
//-----------------------------------------------------------------------

#include "Thermometer.h"

/**
 * The constructor of the Thermometer class
 * @param id (unsigned int): an unsigned integer who's value is the id
 * of a thermometer device.
 */
Thermometer::Thermometer(unsigned int id) :Sensor(id){
}

float Thermometer::getCurrentTemp() {
    unsigned int thermometer = A1, window = A2;
    if (getId() == thermometer || getId() == window){
        _currentTemp = readTempIn();
    } else {
        _currentTemp = readTempOut();
    }

    return _currentTemp;
}

/**
 * The function that handles the reading of the sensor for one of the
 * inside thermometers.
 * @return
 */
float Thermometer::readTempIn() {
    int value = readAnalogSensor();
    float voltage = value * (5000 / 1024.0);
    _currentTemp = (voltage - 500) / 10;
}

/**
 * Handles the reading of the sensor for the outside thermometer.
 * @return The outdoor temperature value as a double.
 */
float Thermometer::readTempOut() {
    float dutyCycle = 0;
    unsigned long temperature = 0;
    unsigned long squareWaveHighTime = 0;
    unsigned long squareWaveLowTime = 0;

    const uint8_t beginning  = readDigitalSensor();
    while (readDigitalSensor() == beginning);

    const uint32_t start = micros();
    while (readDigitalSensor() != beginning);

    const uint32_t middle = micros();
    while (readDigitalSensor() == beginning);

    const uint32_t end = micros();
    squareWaveHighTime = beginning?(end-middle):(middle-start);
    squareWaveLowTime = (!beginning)?(end-middle):(middle-start) ;

    dutyCycle = squareWaveHighTime;
    dutyCycle /= (squareWaveHighTime + squareWaveLowTime);

    temperature = (dutyCycle - 0.320) / 0.00470;
    return (float) temperature;
}
