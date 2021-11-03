//
// Created by Ibrahim on 10/28/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_STOVE_H
#define HOMEDORK_DEVICESYSTEM_STOVE_H
#include "Device.h"
#include "Arduino.h"
#include "../Util/Response.h"


class Stove: public Device{
/**
    * An class that represent a Stove in a smart home this class inherits from Abstract Device class.
    *
    * Attributes:
    *      @param id an integer who's value is the id of an instance of a subclass device.
    *
    * Methods:
     *       Methods:
     *       handleStoveSwitch: handles when Stove change mode.
    *
    * **/
    Stove(int id);
    Response handleStoveSwitch();
};


#endif //HOMEDORK_DEVICESYSTEM_STOVE_H
