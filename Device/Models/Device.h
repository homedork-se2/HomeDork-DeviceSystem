

//
// Created by Samuel Mcmurray on 10/14/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_DEVICE_H
#define HOMEDORK_DEVICESYSTEM_DEVICE_H

#include <Arduino.h>

class Device{
/**
     * An abstract class that represents devices in a smart home.
     *
     * Attributes:
     *      @param id an integer who's value is the id of an instance of a subclass device.
     *      @param pin an integer who's value is the pin location on the Arduino device.
     *      @param isActive a boolean which if true the device is on else if false the device is off.
     *
     * Methods:
     *      getId(): returns an integer of the device id
     *      getPin(): returns an integer of the devices pin (The location on the arduino)
     *      getIsActive(): returns a boolean which if true the device is on else if false the device is off.
     *      setIsActive(): sets the state of the current device takes an isActive boolean to set the state.
     * **/
private:
    unsigned int id;
    bool isActive;
public:
    explicit Device(unsigned int id);
    unsigned int getId() const;
    bool getIsActive() const;
    void setIsActive(bool active);
};


#endif //HOMEDORK_DEVICESYSTEM_DEVICE_H
