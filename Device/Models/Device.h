//-----------------------------------------------------------------------
// File: Device.h
// Summary: An abstract class that represents devices in a smart home.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_DEVICE_H
#define HOMEDORK_DEVICESYSTEM_DEVICE_H

#include <Arduino.h>
#include <Response.h>

class Device{
private:
    unsigned int _id;
    bool _isActive;

public:
    explicit Device(unsigned int id);
    unsigned int getId() const;
    bool getIsActive() const;
    void setIsActive(bool active);

};


#endif //HOMEDORK_DEVICESYSTEM_DEVICE_H
