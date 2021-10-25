//
// Created by Osayomore Edugie on 10/21/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_SENSOR_H
#define HOMEDORK_DEVICESYSTEM_SENSOR_H
#include "Device.h"
#include "Arduino.h"

class Sensor : public Device{
    /**
   * An class that represent a Sensor in a smart home this class inherits from Abstract Device class.
   *
   * Attributes:
   *      @param id an integer who's value is the id of an instance of a subclass device.
   *
   * Methods:
   * **/
public :
    Sensor( int id);
    void readSensor();
};

#endif //HOMEDORK_DEVICESYSTEM_SENSOR_H
