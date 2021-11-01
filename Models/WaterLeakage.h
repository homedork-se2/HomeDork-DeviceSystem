//
// Created by Mustafa on 2021-11-01.
//

#ifndef HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
#define HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H

#include "Sensor.h"
#include "../Util/Response.h"
#include "Arduino.h"

class WaterLeakage {
    /**
   * An class that represent a Sensor in a smart home this class inherits from Abstract Device class.
   *
   * Attributes:
   *      @param id an integer who's value is the id of an instance of a subclass device.
   *
   * Methods:
   * **/
public :
    WaterLeakage(unsigned int id, Sensor sensor);
    Response handleWaterLeakage();

    Sensor sensor;
};

#endif //HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
