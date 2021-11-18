//-----------------------------------------------------------------------
// File: Light.cpp
// Summary: A class that represents a Light in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//-----------------------------------------------------------------------

#include <asptlb.h>
#include "Light.h"
#include "Arduino.h"
#include "Response.h"
#include "../Util/Request.h"

Light::Light(unsigned int id, bool isDimmable) : Device(id), isDimmable(isDimmable) {
    Light::dim = 0;
}

Light::Light(unsigned int id, unsigned int muxPins[]) : Device(id) {
    for (int i = 0; i < 4; ++i) {
        Light::muxPins[i] = muxPins[i];
    }
    Light::isDimmable = false;
    Light::dim = 0;
}

bool Light::getIsDimmable() const {
    return isDimmable;
}

int Light::getDim() {
    return dim;
}


Response Light::setDim(int dim) {
    Response response;
    Light::dim = dim;

    response.setStatusCode(200);
    response.setMessage("Success");

    return response;
}

Response Light::handleLightSwitch(Request request) {
    Response response;
    //Indoors Light
    if (request.getId() == 11) {
        setIsActive(request.isState());
        if (getIsActive()) {
            //ON
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);

            response.setStatusCode(200);
            response.setMessage("Success Indoor Light is ON... \n");

        } else {
            //OFF
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], LOW);

            response.setStatusCode(200);
            response.setMessage("Success Indoor Light is OFF...\n");

        }
        return response

    } else if(request.getId() == 20) {
        //Outdoors Light
        setIsActive(request.isState());
        if (getIsActive()) {
            //ON
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);

            response.setStatusCode(200);
            response.setMessage("Success Outdoor Light is ON...\n");

        } else {
            //OFF
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], HIGH);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);

            response.setStatusCode(200);
            response.setMessage("Success Outdoor Light is OFF...\n");
        }
        return response;
    } else if (request.getId() == 22){
        //Alarm Light
        setIsActive(request.isState());
        if (getIsActive()) {
            //ON
            digitalWrite(muxPins[0], LOW);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);

            response.setStatusCode(200);
            response.setMessage("Success Alarm Light is ON...\n");

        } else {
            //OFF
            digitalWrite(muxPins[0], HIGH);
            digitalWrite(muxPins[1], LOW);
            digitalWrite(muxPins[2], HIGH);
            digitalWrite(muxPins[3], HIGH);

            response.setStatusCode(200);
            response.setMessage("Success Alarm Light is OFF...\n");

        }
        return response;
    }
    response.setStatusCode(404);
    response.setMessage("The Light doesn't exist in the system.");
    return response;
}

const unsigned int *Light::getMuxPins() const {
    return muxPins;
}


