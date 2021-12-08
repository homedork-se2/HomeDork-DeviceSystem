//-----------------------------------------------------------------------
// File: Radiator.cpp
// Summary: A class that represents a heating element in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-20 Created the file,
//-----------------------------------------------------------------------

#include "Radiator.h"

/**
 * The constructor for the Radiator class a subclass of the Device class.
 * @param id (unsigned int): The id of the radiator.
 * @param muxPins (unsigned int[]): The array for the multiplexor pins.
 */
Radiator::Radiator(unsigned int id, unsigned int (&muxPins)[4]): Device(id), _muxPins(muxPins){

}

/**
 * The function that handles the radiator switch.
 * @return (Response): A response that will be sent
 * back to the server.
 */
void Radiator::adjustTemp(bool isCold) {
    Response response{404, "Fail"};

    if (getId() == 23 ) {
        //Window
        setIsActive(isCold);
        if (getIsActive()) {
            digitalWrite(_muxPins[0], LOW);
            digitalWrite(_muxPins[1], HIGH);
            digitalWrite(_muxPins[2], HIGH);
            digitalWrite(_muxPins[3], LOW);
            response.setStatusCode(200);
            response.setMessage("radiator" + getId() + ":ON");

        } else {
            digitalWrite(_muxPins[0], HIGH);
            digitalWrite(_muxPins[1], HIGH);
            digitalWrite(_muxPins[2], HIGH);
            digitalWrite(_muxPins[3], LOW);
            response.setStatusCode(200);
            response.setMessage("radiator" + getId() + ":OFF");

        }

    } else if(getId() == 25)
        //Non window
        setIsActive(isCold);
    if (getIsActive()) {
        digitalWrite(_muxPins[0], LOW);
        digitalWrite(_muxPins[1], HIGH);
        digitalWrite(_muxPins[2], LOW);
        digitalWrite(_muxPins[3], HIGH);
        response.setStatusCode(200);
        response.setMessage("radiator" + getId() + ":ON");

    } else {
        digitalWrite(_muxPins[0], HIGH);
        digitalWrite(_muxPins[1], HIGH);
        digitalWrite(_muxPins[2], LOW);
        digitalWrite(_muxPins[3], HIGH);
        response.setStatusCode(200);
        response.setMessage("radiator" + getId() + ":OFF");

    }
    response.sendMessage();
}
