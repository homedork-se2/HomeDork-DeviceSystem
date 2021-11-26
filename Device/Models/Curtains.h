//-----------------------------------------------------------------------
// File: Curtains.h
// Summary: The Curtains class represented in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim Ali
//-----------------------------------------------------------------------
// Log: 2021-10-18 Created the file.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_CURTAINS_H
#define HOMEDORK_DEVICESYSTEM_CURTAINS_H

#include <Device.h>
#include <Response.h>
#include <Arduino.h>

class Curtains: public Device{
public:
    Curtains(unsigned int id);
    Response handleCurtainSwitch(bool isOpen);
};

#endif //HOMEDORK_DEVICESYSTEM_CURTAINS_H
