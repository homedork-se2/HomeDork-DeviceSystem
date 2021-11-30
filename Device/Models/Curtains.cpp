//-----------------------------------------------------------------------
// File: Curtains.cpp
// Summary: The Curtains class represented in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim Ali
//-----------------------------------------------------------------------
// Log: 2021-10-18 Created the file.
//-----------------------------------------------------------------------
#include "Curtains.h"

/**
 * The constructor of the Curtains class.
 * @param id (unsigned int): Takes the pin of the device as an id.
 */
Curtains::Curtains(unsigned int id) : Device(id) {

}

/**
 * The function that handles the changing of the Curtains state
 * @param isOpen (bool): The state the curtain should be changed to.
 * @return (Response): The response is returned to send to the server.
 */
Response Curtains::handleCurtainSwitch(bool isOpen) {
    
}
