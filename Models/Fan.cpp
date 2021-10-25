//
// Created by Ibrahim on 10/18/2021.
//

#include "Fan.h"

Fan::Fan(int id, bool hasMultiMode, bool hasOscillation) : Device(id) {
    this->hasMultiMode = hasMultiMode;
    this->hasOscillation = hasOscillation;
    if (hasMultiMode) {
        fanMode = Mode::Medium;
    }
}

bool Fan::getHasMultiMode()  {
    return hasMultiMode;
}

void Fan::setHasMultiMode(bool hasMultiMode) {
    this->hasMultiMode = hasMultiMode;
}

bool Fan::getHasOscillation()  {
    return hasOscillation;
}

void Fan::setHasOscillation(bool hasOscillation) {
    this->hasOscillation = hasOscillation;
}

Response Fan::handleFanPowerSwitch() {
    setIsActive()
    if (getHasMultiMode()) {
        if (isActive) {
            //turn on fan with the current MODE
            if (fanMode == Mode::High) {
                //200
            } else if (fanMode == Mode::Medium) {
                //125
            } else {
                //65
            }
        } else {
            //0
        }
    } else {
        if (isActive) {
            digitalWrite(id, HIGH);
        } else {
            digitalWrite(id, LOW);
        }
    }
}



