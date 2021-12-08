//-----------------------------------------------------------------------
// File: Light.cpp
// Summary: A class that represents a Light in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//-----------------------------------------------------------------------

#include "Light.h"


/**
 * A constructor for the light class this constructor handles lights that
 * are not connected to a multiplexor.
 * @param id (unsigned int): The id is a representation of the pin the
 * device is connected to.
 * @param isDimmable (boolean): The boolean that determines if a light
 * is dimmable or not.
 */
Light::Light(unsigned int id, bool isDimmable, unsigned int * muxPins)
        : Device(id), _isDimmable(isDimmable), _dim(0), _muxPins(muxPins) {

}

/**
 * A constructor for the light class this constructor handles lights that
 * are connected to a multiplexor.
 * @param id (unsigned int): The id is a representation of the pin the
 * device is connected to.
 * @param muxPins (unsigned int[]): An array of the multiplexor pins.
 */
Light::Light(unsigned int id, unsigned int * muxPins) : Device(id), _isDimmable(false), _dim(0), _muxPins(muxPins) {
}

/**
 * A getter for the is dimmable boolean.
 * @return (boolean): The lights boolean value for whether or not
 * it is dimmable.
 */
bool Light::getIsDimmable() const {
    return _isDimmable;
}

/**
 * A getter for the dim value.
 * @return (int): The dim value between 0-99.
 */
int Light::getDim() {
    return _dim;
}

/**
 * A setter fpr the dim value.
 * @param value (int): The dim value to be set.
 * @return (Response): A response to the server.
 */
void Light::setDim(int value) {
    Response response{500, "Fail"};
    _dim = value;

    response.setStatusCode(200);
    response.setMessage("lamp:" + getId() + ":" + _dim);

    response.sendMessage();
}
/**
 * The function that handles the light switch.
 * @param request (Request): A request is passed as a parameter to
 * hold the information about the command from the server.
 * @return (Response): The response from the command sent by the
 * server.
 */
void Light::handleLightSwitch(Request request) {
    Response response{500, "Fail"};
    response.setStatusCode(404);
    response.setMessage("lamp:ERROR");
    //Indoors Light
    if (request.getId() == 11) {
    setIsActive(request.isState());
        if (getIsActive()) {
        //ON
        digitalWrite(_muxPins[0], LOW);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], HIGH);
        digitalWrite(_muxPins[3], LOW);

        response.setStatusCode(200);
        response.setMessage("lamp:" + request.getId() + ":ON");

        } else {
        //OFF
        digitalWrite(_muxPins[0], HIGH);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], HIGH);
        digitalWrite(_muxPins[3], LOW);

        response.setStatusCode(200);
        response.setMessage("lamp:" + request.getId() + ":OFF");

        }

    } else if(request.getId() == 20) {
    //Outdoors Light
    setIsActive(request.isState());
        if (getIsActive()) {
        //ON
        digitalWrite(_muxPins[0], LOW);
        digitalWrite(_muxPins[1], HIGH);
        digitalWrite(_muxPins[2], HIGH);
        digitalWrite(_muxPins[3], HIGH);

        response.setStatusCode(200);
        response.setMessage("lamp:" + request.getId() + ":ON");

        } else {
        //OFF
        digitalWrite(_muxPins[0], HIGH);
        digitalWrite(_muxPins[1], HIGH);
        digitalWrite(_muxPins[2], HIGH);
        digitalWrite(_muxPins[3], HIGH);

        response.setStatusCode(200);
        response.setMessage("lamp:" + request.getId() + ":OFF");
        }

    } else if (request.getId() == 22){
    //Alarm Light
    setIsActive(request.isState());
        if (getIsActive()) {
        //ON
        digitalWrite(_muxPins[0], LOW);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], HIGH);
        digitalWrite(_muxPins[3], HIGH);

        response.setStatusCode(200);
        response.setMessage("lamp:" + request.getId() + ":ON");

        } else {
        //OFF
        digitalWrite(_muxPins[0], HIGH);
        digitalWrite(_muxPins[1], LOW);
        digitalWrite(_muxPins[2], HIGH);
        digitalWrite(_muxPins[3], HIGH);

        response.setStatusCode(200);
        response.setMessage("lamp:" + request.getId() + ":OFF");

        }
    }

    response.sendMessage();
}

