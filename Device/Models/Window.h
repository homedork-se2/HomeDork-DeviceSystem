//-----------------------------------------------------------------------
// File: Window.h
// Summary: A class that represents a Window in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim
//-----------------------------------------------------------------------
// Log: 2021-10-28 Created the file,
//-----------------------------------------------------------------------
#ifndef HOMEDORK_DEVICESYSTEM_WINDOW_H
#define HOMEDORK_DEVICESYSTEM_WINDOW_H

#include <Arduino.h
#include <Device.h>
#include <Response.h>

class Window: public Sensor {
    /**
    * A class that represents a Window in a smart home this class inherits from Abstract Device class.
    *
    * Attributes:
    *      @param id an integer who's value is the id of an instance of a subclass device.
    *
    * Methods:
     *       Methods:
     *       handleWindowSwitch: handles when window change position from open and close.
    *
    * **/
public:

    explicit Window(unsigned int id);
    Response handleWindowSwitch();

};


#endif //HOMEDORK_DEVICESYSTEM_WINDOW_H
