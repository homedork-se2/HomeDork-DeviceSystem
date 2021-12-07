//-----------------------------------------------------------------------
// File: Light.h
// Summary: A class that represents a Light in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_LIGHT_H
#define HOMEDORK_DEVICESYSTEM_LIGHT_H

#include <Arduino.h>
#include <Device.h>
#include <Response.h>
#include <Request.h>

class Light:public Device {
private:
    bool _isDimmable;
    int _dim;
    unsigned int * _muxPins;

public:
    Light(unsigned int id, bool isDimmable, unsigned int * muxPins);
    Light(unsigned int id, unsigned int * muxPins);
    bool getIsDimmable() const;
    int getDim();
    Response setDim(int dim);
    Response handleLightSwitch(Request request);

};


#endif //HOMEDORK_DEVICESYSTEM_LIGHT_H
