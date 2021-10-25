//
// Created by Samuel Mcmurray on 10/14/2021.
//

#include "Light.h"
#include "Arduino.h"
#include "Response.h"

Light::Light(unsigned int id, bool isDimmable) : Device(id) {
    this->isDimmable = isDimmable;
}

Light::Light(unsigned int id, int * muxPins, bool isDimmable) : Device(id) {
    int length = sizeof(muxPins)/sizeof(muxPins[0]);
    for (int i = 0; i < length; ++i) {
        this->muxPins[i] = muxPins[i];
    }
    this->isDimmable = isDimmable;
}

bool Light::getIsDimmable() const {
    return this->isDimmable;
}

int Light::getDim() {
    return this->dim;
}


Response Light::setDim(int dim) {
    Response response{200, "Success"};
    return response;
}

Response Light::handleLightSwitch(int id) {
    //indoors
    if (id == 20 ) {
        setIsActive();
        if (getIsActive()) {
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);
            Response response{200, "Success Light is ON... \n"};
            return response;
        } else {
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);
            Response response{200, "Success Power is OFF...\n"};
            return response;
        }

    } else if(id == 10)
        //outdoors
        setIsActive();
        if (getIsActive()) {
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);
            Response response{200, "Success Light is ON... \n"};
            return response;
        } else {
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);
            Response response{200, "Success Power is OFF...\n"};
            return response;
        }
    }
}
