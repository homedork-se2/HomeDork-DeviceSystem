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
Radiator::Radiator(unsigned int id, unsigned int * muxPins): Device(id), _muxPins(muxPins){

}

/**
 * The function that handles the radiator switch.
 * @return (Response): A response that will be sent
 * back to the server.
 */
void Radiator::adjustTemp(bool isCold) {
    Response response;
    char radiator[8] = {'r', 'a', 'd', 'i', 'a', 't', 'o', 'r'};
    setIsActive(isCold);
    if (getIsActive()) {
        char state[2] = {'O', 'N'};
        if (getId() == 23) {
            //Window ON
            digitalWrite(_muxPins[0], LOW);
            digitalWrite(_muxPins[1], HIGH);
            digitalWrite(_muxPins[2], HIGH);
            digitalWrite(_muxPins[3], LOW);
        }else if(getId() == 25) {
            //Non window ON
            digitalWrite(_muxPins[0], LOW);
            digitalWrite(_muxPins[1], HIGH);
            digitalWrite(_muxPins[2], LOW);
            digitalWrite(_muxPins[3], HIGH);

        }
        response.createMessage(String(radiator), 8, String(getId()), 2, String(state), 2);

    } else  {
        char state[3] = {'O', 'F', 'F'};
        if(getId() == 23) {
            //Window OFF
            digitalWrite(_muxPins[0], HIGH);
            digitalWrite(_muxPins[1], HIGH);
            digitalWrite(_muxPins[2], HIGH);
            digitalWrite(_muxPins[3], LOW);

        } else if (getId() == 25) {
            //Non window OFF
            digitalWrite(_muxPins[0], HIGH);
            digitalWrite(_muxPins[1], HIGH);
            digitalWrite(_muxPins[2], LOW);
            digitalWrite(_muxPins[3], HIGH);

        }
        response.createMessage(String(radiator), 8, String(getId()), 2, String(state), 3);
    }
<<<<<<< HEAD
    delay(50);
=======
    delay(10);
>>>>>>> 40d52950655ecf9ddec15aa4122625812e38c356
    response.sendMessage();
}
