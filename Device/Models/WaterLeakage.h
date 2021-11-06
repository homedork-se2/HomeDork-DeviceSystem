//
// Created by Mustafa on 2021-11-01.
//

#ifndef HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
#define HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H

#include "Sensor.h"
#include "Response.h"
#include "Arduino.h"

class WaterLeakage {
    /**
   * An class that represent a WaterLeakage in a smart home.
   *
   * Attributes:
   *      @param id an integer who's value is the id of an instance of a subclass device.
   *
   * Methods:
   *      The Waterleakage class.
   *      handleWaterLeakage returns a response.
   *
   * **/
public :
    WaterLeakage(unsigned int id, Sensor sensor);
    Response handleWaterLeakage();

    Sensor sensor;
};

#endif //HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
