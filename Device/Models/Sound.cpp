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
Sound::Sound(unsigned int id, unsigned int * muxPins): Device(id), _muxPins(muxPins){
}

/**
 * The function that handles the sound switch.
 * @param isActive (boolean): The represented state that the sound device
 * should be set to.
 * @return (Response): A response sent back to the server.
 */
void Sound::handleSoundSwitch(bool isActive) {
    Response response;
    char sound[5] = {'s', 'o', 'u', 'n', 'd'};
    setIsActive(isActive);
    if (getIsActive()) {
        char stateString[2] = {'O', 'N'};
        digitalWrite(_muxPins[0], HIGH);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], LOW);
        digitalWrite(_muxPins[3], LOW);
        response.createMessage(String(sound), 5, String(getId()), 2, String(stateString), 2);
    } else {
        char stateString[3] = {'O', 'F', 'F'};
        digitalWrite(_muxPins[0], LOW);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], LOW);
        digitalWrite(_muxPins[3], LOW);
        response.createMessage(String(sound), 5, String(getId()), 2, String(stateString), 3);
    }
<<<<<<< HEAD
    delay(100);
=======
    //Serial.println(response.getMessage());
    delay(10);
>>>>>>> 40d52950655ecf9ddec15aa4122625812e38c356
    response.sendMessage();
}
