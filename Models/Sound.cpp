//
// Created by Mustafa on 2021-10-21.
//

#include "Sound.h"

Sound::Sound(unsigned int id, unsigned int * muxPins): Device(id){
    this->id = id;
    this->muxPins = muxPins;
}

Response Sound::handleSoundOn() {
    setIsActive();
    digitalWrite(muxPins[0], HIGH);
    digitalWrite(muxPins[1], LOW);
    digitalWrite(muxPins[2], LOW);
    digitalWrite(muxPins[3], LOW);
    Response response{200, "Sound is Active"};
    return response;
}

Response Sound::handleSoundOff() {
    setIsActive();
    digitalWrite(muxPins[0], LOW);
    digitalWrite(muxPins[1], LOW);
    digitalWrite(muxPins[2], LOW);
    digitalWrite(muxPins[3], LOW);
    Response response{200, "Sound is inActive"};
    return response;
}
