//-----------------------------------------------------------------------
// File: Request.h
// Summary: A class that represents a request from the server contains
// the variables that will be used to run the commands.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-11-07 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_REQUEST_H
#define HOMEDORK_DEVICESYSTEM_REQUEST_H

#include <Arduino.h>

class Request {
private:
    unsigned int _id;
    bool _state;
    int _value;
    int _deviceType;

public:
    unsigned int getId() const;
    void setId(unsigned int id);
    bool isState() const;
    void setState(bool state);
    int getValue() const;
    void setValue(int value);
    int getDeviceType();
    void setDeviceType(String deviceName);
    void parseRequest(byte * buf);

};

#endif //HOMEDORK_DEVICESYSTEM_REQUEST_H
