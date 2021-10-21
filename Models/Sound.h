//
// Created by Mustafa on 2021-10-21.
//

#ifndef HOMEDORK_DEVICESYSTEM_SOUND_H
#define HOMEDORK_DEVICESYSTEM_SOUND_H

#include "Arduino.h"
#include "Device.h"
#include "Response.h"

class Sound:public Device {
/**
     * An class that represents the Thermometer in a smart home this class inherits from the Abstract Device class.
     *
     * Attributes:
     *      @param id an unsigned integer who's value is the id of a thermometer device.
     *      @param pin an integer who's value is the pin location on the Arduino device.
     *
     * Methods:
     *      The Sound class also has access to the Device class methods.
     *      handleSoundSwitch returns a response that determines the state of the Sound device.
     *
     * **/

private:

public:
    Sound(unsigned int id);
    Response handleSoundOn();
    Response handleSoundOff();
};

#endif //HOMEDORK_DEVICESYSTEM_SOUND_H
