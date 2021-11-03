//
// Created by Osayomore Edugie on 10/21/2021.
//

#include "Sensor.h"

Sensor::Sensor(int id): Device(id) {
    this->id = id;
}

void Sensor::readSensor() {
    digitalRead(id);
}