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
    unsigned int id;
    bool state;
    int value;
    String deviceType;
public:

    unsigned int getId() const;

    void setId(unsigned int id);

    bool isState() const;

    void setState(bool state);

    int getValue() const;

    void setValue(int value);

    String getDeviceType();

    void setDeviceType(String deviceType);

    void parseRequest(char buf[]);
};


#endif //HOMEDORK_DEVICESYSTEM_REQUEST_H
