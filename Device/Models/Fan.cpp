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
Fan::Fan(unsigned int id, bool hasMultiMode, bool hasOscillation) : Device(id) {
    Fan::hasMultiMode = hasMultiMode;
    Fan::hasOscillation = hasOscillation;
    if (hasMultiMode) {
        fanMode = Mode::MEDIUM;
    }
}

/**
 * A getter to check if the fan has a multi mode.
 * @return (boolean): Will return whether or not the fan has multi mode.
 */
bool Fan::getHasMultiMode()  {
    return hasMultiMode;
}

/**
 * A setter to set whether or not a fan has multi mode.
 * @param hasMultiMode (boolean): The boolean representation if the
 * fan has a multi mode function.
 */
void Fan::setHasMultiMode(bool hasMultiMode) {
    Fan::hasMultiMode = hasMultiMode;
}

/**
 * A getter to determine whether or not oscillation is a feature
 * of the fan.
 * @return (boolean): A boolean that represents whether or not
 * the fan has a oscillation function.
 */
bool Fan::getHasOscillation()  {
    return hasOscillation;
}

/**
 * A setter for the oscillation
 * @param hasOscillation (boolean): The boolean representation if the
 * fan has a oscillation function.
 */
void Fan::setHasOscillation(bool hasOscillation) {
    Fan::hasOscillation = hasOscillation;
}

/**
 * The function that handles a command from the server to
 * @param isActive (boolean): The state of the fan.
 * @return (Response): A response is returned to the server.
 */
Response Fan::handleFanSwitch(bool isActive) {
    setIsActive(isActive);
    if (getHasMultiMode()) {
        if (getIsActive()) {
            //turn on fan with the current MODE
            if (fanMode == Mode::HIGH) {
                analogWrite(getId(), 200);
                Response response{200, "Success Fan set  High...\n"};
            } else if (fanMode == Mode::MEDIUM) {
                analogWrite(getId(), 124);
                Response response{200, "Success Fan set  Medium...\n"};
            } else if (fanMode == Mode::LOW){
                analogWrite(getId(), 64);
                Response response{200, "Success Fan set  Low...\n"};
            }

        } else {
            analogWrite(getId(), 0);
            Response response{200, "Success Fan set OFF\n"};
        }
    } else {
        if (getIsActive()) {
            digitalWrite(getId(), HIGH);
        } else {
            digitalWrite(getId(), LOW);
        }

    }
}
