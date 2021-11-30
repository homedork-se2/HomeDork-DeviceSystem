//-----------------------------------------------------------------------
// File: Window.cpp
// Summary: A class that represents a Window in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim
//-----------------------------------------------------------------------
// Log: 2021-10-28 Created the file,
//-----------------------------------------------------------------------

#include "Window.h"

/**
 *  The constructor of the Window class a subclass of the Sensor class.
 * @param id (unsigned int): An integer who's value is the id of an instance
 * of a subclass device.
 */
Window::Window(unsigned int id): Sensor(id) {
}

/**
 *  The function that handles the change in state of the window.
 * @return (Response): A response that is sent to the server to handle
 * the state change
 */
Response Window::handleWindowSwitch() {

}
