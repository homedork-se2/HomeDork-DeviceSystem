//
// Created by Ibrahim on 10/18/2021.
//

#include "Fan.h"

Fan::Fan(int id, bool hasMultiMode, bool hasOscillation) : Device(id) {
    this->hasMultiMode = hasMultiMode;
    this->hasOscillation = hasOscillation;
    if (hasMultiMode) {
        fanMode = Mode::MEDIUM;
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
            if (fanMode == Mode::HIGH) {
                analogWrite(id, 200);
                Response response{200, "Success Fan set  High...\n"};
            } else if (fanMode == Mode::MEDIUM) {
                analogWrite(id, 124);
                Response response{200, "Success Fan set  Medium...\n"};
            } else {
                analogWrite(id, 64);
                Response response{200, "Success Fan set  Low...\n"};
    } else {
        if (isActive) {
            analogWrite(id, 200);
            Response response{200, "Success Fan ON...\n"};
        } else {
            analogWrite(id, 0);
            Response response{200, "Success Fan set OFF\n"};
        }
    }
}



