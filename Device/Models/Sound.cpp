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

/**
 * The Sound class constructor.
 * @param id (unsigned int): The id by which will be reffered to in regards
 * the the instance.
 * @param muxPins (unsigned int[]): The array containing the multiplexor
 * pins.
 */
Sound::Sound(unsigned int pin, int id, unsigned int * muxPins): Device(pin, id), _muxPins(muxPins){
}

/**
 * The function that handles the sound switch.
 * @param isActive (boolean): The represented state that the sound device
 * should be set to.
 * @return (Response): A response sent back to the server.
 */
void Sound::handleSoundSwitch(bool isActive) {
    Response response{500, ":ERROR"};
    response.createMessage(String(this->getId()), String(500));
    setIsActive(isActive);
    if (getIsActive()) {
        digitalWrite(_muxPins[0], HIGH);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], LOW);
        digitalWrite(_muxPins[3], LOW);
        response.createMessage(String(getId()), String(1));
    } else {
        digitalWrite(_muxPins[0], LOW);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], LOW);
        digitalWrite(_muxPins[3], LOW);
        response.createMessage(String(getId()), String(0));
    }
    response.sendMessage();
    delay(200);
}
