//
// Created by Samuel Mcmurray on 10/20/2021.
//

#include "Radiator.h"
Radiator::Radiator(unsigned int id, unsigned int * muxPins): Device(id) {
    this->muxPins = muxPins;
}

Response Radiator::adjustTemp(bool isCold) {

    if (id == 23 ) {
        //Window
        setIsActive(isCold);
        if (getIsActive()) {
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);
            Response response{200, "Success Light is ON... \n"};
            return response;
        } else {
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);
            Response response{200, "Success Power is OFF...\n"};
            return response;
        }

    } else if(id == 25)
        //Non window
        setIsActive(isCold);
    if (getIsActive()) {
        digitalWrite(muxPins[0], LOW);
        digitalWrite(muxPins[1], HIGH);
        digitalWrite(muxPins[2], LOW);
        digitalWrite(muxPins[3], HIGH);
        Response response{200, "Success Light is ON... \n"};
        return response;
    } else {
        digitalWrite(muxPins[0], HIGH);
        digitalWrite(muxPins[1], HIGH);
        digitalWrite(muxPins[2], LOW);
        digitalWrite(muxPins[3], HIGH);
        Response response{200, "Success Power is OFF...\n"};
        return response;
    }
}
}