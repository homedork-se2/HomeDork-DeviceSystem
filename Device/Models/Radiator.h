//
// Created by Samuel Mcmurray on 10/20/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_RADIATOR_H
#define HOMEDORK_DEVICESYSTEM_RADIATOR_H
#include "Device.h"
#include "Arduino.h"

class Radiator: public Device {
    /**
     * An class that represent a Curtains in a smart home this class inherits from Abstract Device class.
     *
     * Attributes:
     *      @param id an integer who's value is the id of an instance of a subclass device.
     *      @param muxPins This is the multiplexor pin array.
     *       Methods:
     *       handleCurtainSwitch: handles when curtain switch position
     *
     * **/
private:
    unsigned int muxPins[4];
public:
    Radiator(unsigned int id, unsigned int * muxPins);
    Response adjustTemp(): Response
};


#endif //HOMEDORK_DEVICESYSTEM_RADIATOR_H
