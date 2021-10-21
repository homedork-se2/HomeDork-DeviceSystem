//
// Created by Mustafa on 2021-10-18.
//

#include "Thermometer.h"

Thermometer::Thermometer(unsigned int id) :Device(id){

}

double Thermometer::getCurrentTemp() {
    return 0;
}

Response Thermometer::setCurrentTemp(int currentTemp) {

    return Response response(200, "Success");
}

