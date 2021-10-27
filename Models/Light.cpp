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
    for (int i = 0; i < 4; ++i) {
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
    Response response;
    //Indoors Light
    if (id == 11 ) {
        setIsActive();
        if (getIsActive()) {
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);

            response.setStatusCode(200);
            response.setMessage("Success Indoor Light is ON... \n");
            Serial.println(response.getMessage());
            return response;
        } else {
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);

            response.setStatusCode(200);
            response.setMessage("Success Indoor Light is OFF...\n");
            Serial.println(response.getMessage());
            return response;
        }

    } else if(id == 20) {
        //Outdoors Light
        setIsActive();
        if (getIsActive()) {
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);

            response.setStatusCode(200);
            response.setMessage("Success Outdoor Light is ON...\n");
            Serial.println(response.getMessage());
            return response;
        } else {
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);

            response.setStatusCode(200);
            response.setMessage("Success Outdoor Light is OFF...\n");
            Serial.println(response.getMessage());
            return response;
        }
    } else if (){
        //Alarm Light
        setIsActive();
        if (getIsActive()) {
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);
            response.setStatusCode(200);
            response.setMessage("Success Alarm Light is ON...\n");
            Serial.println(response.getMessage());
            return response;
        } else {
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);
            response.setStatusCode(200);
            response.setMessage("Success Alarm Light is OFF...\n");
            Serial.print(response.getMessage());
            return response;
        }
    }
    response.setStatusCode(404);
    response.setMessage("The Light doesn't exist in the system.");
    return response;
}

