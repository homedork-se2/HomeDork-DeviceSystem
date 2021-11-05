//
// Created by Mustafa on 2021-11-01.
//

#include "WaterLeakage.h"


WaterLeakage::WaterLeakage(unsigned int id, Sensor sensor) : sensor(0) {
    this->sensor = sensor;
}

Response WaterLeakage::handleWaterLeakage(){
    sensor.readSensor();

}

Sensor::Sensor(unsigned int id) : Device(id) {}
