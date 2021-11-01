//
// Created by Ibrahim on 10/28/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_WINDOW_H
#define HOMEDORK_DEVICESYSTEM_WINDOW_H
#include "Device.h"
#include "../Util/Response.h"
#include "Arduino.h"
class Window: public Device {
    /**
    * An class that represent a Window in a smart home this class inherits from Abstract Device class.
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
    Window(int id);
    Response handleWindowSwitch();

};


#endif //HOMEDORK_DEVICESYSTEM_WINDOW_H
