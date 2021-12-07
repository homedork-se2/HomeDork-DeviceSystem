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

class Sound: public Device {
private:
    unsigned int * _muxPins;

public:
    Sound(unsigned int id, unsigned int * muxPins);
    Response handleSoundSwitch(bool isActive);

};

#endif //HOMEDORK_DEVICESYSTEM_SOUND_H
