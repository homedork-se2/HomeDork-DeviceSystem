//-----------------------------------------------------------------------
// File: Fan.cpp
// Summary: A class that represent a Fan in a smart home this class
// inherits from Abstract Device class.
// device class.
// Version: 1.0
// Owner: Ibrahim Ali
//-----------------------------------------------------------------------
// Log: 2021-10-18 Created the file,
//-----------------------------------------------------------------------
#include "Fan.h"

/**
 *  A contstructor of the Fan class.
 * @param id (unsigned int): An id who's value is the pin in which it is
 * located.
 * @param hasMultiMode (boolean): A boolean determining if the fan has
 * multimode.
 * @param hasOscillation (boolean): A boolean determining if the fan has
 * oscillation.
 */
Fan::Fan(unsigned int pin, int id, bool hasMultiMode, bool hasOscillation) : Device(pin,id), _hasMultiMode(hasMultiMode), _hasOscillation(hasOscillation){
    if (hasMultiMode) {
        _fanMode = Medium;
    }
}

/**
 * A getter to check if the fan has a multi mode.
 * @return (boolean): Will return whether or not the fan has multi mode.
 */
bool Fan::getHasMultiMode()  {
    return _hasMultiMode;
}

/**
 * A setter to set whether or not a fan has multi mode.
 * @param hasMultiMode (boolean): The boolean representation if the
 * fan has a multi mode function.
 */
void Fan::setHasMultiMode(bool hasMultiMode) {
    _hasMultiMode = hasMultiMode;
}

/**
 * A getter to determine whether or not oscillation is a feature
 * of the fan.
 * @return (boolean): A boolean that represents whether or not
 * the fan has a oscillation function.
 */
bool Fan::getHasOscillation()  {
    return _hasOscillation;
}

/**
 * A setter for the oscillation
 * @param hasOscillation (boolean): The boolean representation if the
 * fan has a oscillation function.
 */
void Fan::setHasOscillation(bool hasOscillation) {
    _hasOscillation = hasOscillation;
}

/**
 * A setter for the mode
 * @param value (int): The value of the fan sent by the user.
 */
void Fan::setMode(int value) {
    if (value > 70) {
        _fanMode = High;
    } else if (value < 70 && value > 25) {
        _fanMode = Medium;
    } else {
        _fanMode = Low;
    }
}

/**
 * A getter for the mode.
 * @return (Mode): The mode that the fan is set at.
 */
Mode Fan::getMode() {
    return _fanMode;
}

/**
 * The function that handles a command from the server to
 * @param isActive (boolean): The state of the fan.
 * @return (Response): A response is returned to the server.
 */
void Fan::handleFanSwitch(Request request) {
    Response response{500, ":ERROR"};
    response.createMessage(String(this->getId()), String(500));
    setIsActive(request.isState());
    if (getHasMultiMode()) {
        if (getIsActive()) {
            //turn on fan with the current MODE
            setMode(request.getValue());
            if (_fanMode == Mode::High) {
                analogWrite(getId(), 200);
            } else if (_fanMode == Mode::Medium) {
                analogWrite(getId(), 124);
            } else if (_fanMode == Mode::Low){
                analogWrite(getId(), 64);
            }
            response.createMessage(String(getId()), String(request.getValue()));

        } else {
            analogWrite(getId(), 0);
            response.createMessage(String(getId()), String(0));
        }
    } else {
        if (getIsActive()) {
            digitalWrite(getId(), HIGH);
            response.createMessage(String(getId()), String(1));
        } else {
            digitalWrite(getId(), LOW);
            response.createMessage(String(getId()), String(0));
        }

    }

    response.sendMessage();
}
