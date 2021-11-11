//-----------------------------------------------------------------------
// File: Sound.cpp
// Summary: A class that represents a Siren in a smart home this class
// inherits from Abstract Device class and outputs a sound when active.
// Version: 1.0
// Owner: Mustafa
//-----------------------------------------------------------------------
// Log: 2021-10-21 Created the file,
//-----------------------------------------------------------------------
#include "Sound.h"

Sound::Sound(unsigned int id, unsigned int muxPins[]): Device(id){
    for (int i = 0; i < 4; ++i) {
        Sound::muxPins[i] = muxPins[i];
    }
}

Response Sound::handleSoundSwitch(bool isActive) {
    Response response{500, "Error Sound not set"};
    setIsActive(isActive);
    if (getIsActive()) {
        digitalWrite(muxPins[0], HIGH);
        digitalWrite(muxPins[1], LOW);
        digitalWrite(muxPins[2], LOW);
        digitalWrite(muxPins[3], LOW);

        response.setMessage("Success sound is active");
        response.setStatusCode(200);
    } else {
        digitalWrite(muxPins[0], LOW);
        digitalWrite(muxPins[1], LOW);
        digitalWrite(muxPins[2], LOW);
        digitalWrite(muxPins[3], LOW);

        response.setMessage("Success sound is inactive");
        response.setStatusCode(200);
    }

    return response;
}
