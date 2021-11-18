//-----------------------------------------------------------------------
// File: Sound.h
// Summary: A class that represents a Siren in a smart home this class
// inherits from Abstract Device class and outputs a sound when active.
// Version: 1.0
// Owner: Mustafa
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//-----------------------------------------------------------------------
#ifndef HOMEDORK_DEVICESYSTEM_SOUND_H
#define HOMEDORK_DEVICESYSTEM_SOUND_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>

class Sound:public Device {
/**
     * A class that represents the Thermometer in a smart home this class inherits from the Abstract Device class.
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
    unsigned int id;
    unsigned int muxPins[4];
public:
    Sound(unsigned int id, unsigned int  muxPins[]);

    Response handleSoundSwitch(bool isActive);
};

#endif //HOMEDORK_DEVICESYSTEM_SOUND_H
