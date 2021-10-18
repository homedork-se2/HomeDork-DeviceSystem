//
// Created by Samuel Mcmurray on 10/14/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_LIGHT_H
#define HOMEDORK_DEVICESYSTEM_LIGHT_H
#include <Device.h>
#include <Response.h>
#include "Arduino.h"

class Light:public Device {/**
     * An class that represents a Light in a smart home this class inherits from the Abstract Device class.
     *
     * Attributes:
     *      @param id an unsigned integer who's value is the id of a light device.
     *      @param pin an integer who's value is the pin location on the Arduino device.
     *      @param isDimmable a boolean which if true if the light can be dimmed else if false the light has no such feature.
     *
     * Methods:
     *      The Light class also has access to the Device class methods
     *      getIsDimmable returns a boolean which if true if the light can be dimmed else if false the light has no such feature.
     *      getDim returns an integer whos value is the percentage of dim..
     *      setDim returns a response takes an integer as a parameter and sets the dim percentage.
     * **/

private:
    bool isDimmable;
    int dim;
    unsigned int array[4] = {12, 13, 11, 8};
public:
    Light(unsigned int id, bool isDimmable);
    bool getIsDimmable();
    int getDim();
    unsigned int * getPins();
    Response setDim(int dim);
    Response handleLightSwitch(int id);
};


#endif //HOMEDORK_DEVICESYSTEM_LIGHT_H
