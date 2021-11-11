//
// Created by Ibrahim on 10/18/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_CURTAINS_H
#define HOMEDORK_DEVICESYSTEM_CURTAINS_H
#include "Device.h"
#include "../Util/Response.h"
#include "Arduino.h"


class Curtains: public Device{
    /**
     * An class that represent a Curtains in a smart home this class inherits from Abstract Device class.
     *
     * Attributes:
     *      @param id an integer who's value is the id of an instance of a subclass device.
     *
     *       Methods:
     *       handleCurtainSwitch: handles when curtain switch position
     *
     * **/
public:

    Curtains(int id);
    Response handleCurtainSwitch();
};


#endif //HOMEDORK_DEVICESYSTEM_CURTAINS_H
