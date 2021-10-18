//
// Created by Samuel Mcmurray on 10/14/2021.
//

#include "Light.h"
#include "Arduino.h"
#include "Response.h"

Light::Light(unsigned int id, bool isDimmable) : Device(id) {
    this->isDimmable = isDimmable;
}

bool Light::getIsDimmable() const {
    return this->isDimmable;
}

int Light::getDim() {
    return this->dim;
}

unsigned int * Light::getPins() {
    return this->array;
}

Response Light::setDim(int dim) {
    Response response{200, "Success"};
    return response;
}

Response Light::handleLightSwitch(int id) {
    unsigned int * pins = this->getPins();
    //indoors
    if (id == 1 ) {
        setIsActive();
        if (getIsActive()) {
            Response response{200, "Success Light is ON... \n"};
            digitalWrite(pins[0], LOW);
            digitalWrite(pins[1], LOW);
            digitalWrite(pins[2], HIGH);
            digitalWrite(pins[3], LOW);
            Serial.print("light is ON...");
            return response;
        } else {
            Response response{200, "Success Power is OFF...\n"};
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
            digitalWrite(11, HIGH);
            digitalWrite(8, LOW);
            return response;
        }

    } else
        //outdoors
        setIsActive();
        if (getIsActive()) {
            Response response{200, "Success Light is ON... \n"};
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(8, HIGH);
            Serial.print("light is ON...");
            return response;
        } else {
            Response response{200, "Success Power is OFF...\n"};
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(8, HIGH);
            return response;
        }
    }
}
