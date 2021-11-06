//
// Created by Dell on 11/5/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
#define HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
#include "Arduino.h"
#include "Device.h"
#include "Sensor.h"


class TwilightAutomaticSystem : public Device{
    /**
 * An class that represent a TwilightAutomaticSystem in a smart home this class inherits from Abstract Device class.
 *
 * Attributes:
 *      @param id an integer who's value is the id of an instance of a subclass device.
 * Methods:
**/


private:
    Sensor lightSensor;

public:
    TwilightAutomaticSystem(int id);
    bool getSensorState();
    Response handleTwilightSystem();

};


#endif //HOMEDORK_DEVICESYSTEM_TWILIGHTAUTOMATICSYSTEM_H
