//-----------------------------------------------------------------------
// File: Thermometer.cpp
// Summary: A class that represents a Light in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//-----------------------------------------------------------------------
#include "Thermometer.h"
#include "Arduino.h"

Thermometer::Thermometer(unsigned int id) :Device(id){
    Thermometer::id = id;
}

double Thermometer::getCurrentTemp() {
    Response response;
    if (id == A1){

        int temp = analogRead(id);
        temp = temp*0.48828125;

        response.setMessage("Temperature is " + temp);

        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.println("C");

    }

    return response;
}


double Thermometer::readTempIn() {

}

double thermometer::readTempOut() {

}

