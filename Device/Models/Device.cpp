//-----------------------------------------------------------------------
// File: Device.cpp
// Summary: An abstract class that represents devices in a smart home.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file.
//-----------------------------------------------------------------------

#include "Device.h"

/**
 * The constructor to the Abstract Device Class.
 * @param id (unsigned int): An integer who's value is the id of an
 * instance of a subclass device.
 */
Device::Device(unsigned int pin, int id): _pin(id), _isActive(false), _id(id) {
}

/**
 * A getter for the id
 * @return (unsigned int): The id.
 */
unsigned int Device::getPin() const {
    return _pin;
}

/**
 * A getter for the isActive boolean.
 * @return (boolean): Is Active.
 */
bool Device::getIsActive() const {
    return _isActive;
}

int Device::getId() const {
    return _id
}

/**
 * A setter for the isActive boolean.
 * @param active (boolean): The value that the isActive wll be set to.
 */
void Device::setIsActive(bool active) {
    _isActive = active;
}
