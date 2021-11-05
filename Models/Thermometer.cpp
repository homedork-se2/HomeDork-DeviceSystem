//
// Created by Mustafa on 2021-10-18.
//

#include "Thermometer.h"

Thermometer::Thermometer(unsigned int id) :Device(id){
    this->id = id;
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

Response Thermometer::setCurrentTemp(int currentTemp) {

    return Response response(200, "Success");
}

double Thermometer::readTempIn() {

}

double thermometer::readTempOut() {

}

