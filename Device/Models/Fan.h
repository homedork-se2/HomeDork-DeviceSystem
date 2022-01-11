//-----------------------------------------------------------------------
// File: Fan.h
// Summary: A class that represent a Fan in a smart home this class
// inherits from Abstract Device class.
// device class.
// Version: 1.0
// Owner: Ibrahim Ali
//-----------------------------------------------------------------------
// Log: 2021-10-18 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_FAN_H
#define HOMEDORK_DEVICESYSTEM_FAN_H

#include <Arduino.h>
#include <Device.h>
#include <Request.h>

enum Mode{Low, Medium, High};

class Fan: public Device{
private:
    bool _hasMultiMode;
    bool _hasOscillation;
    Mode _fanMode;

public:
    Fan(unsigned int pin, int id, bool hasMultiMode, bool hasOscillation);
    bool getHasMultiMode() ;
    void setHasMultiMode(bool hasMultiMode);
    void setHasOscillation(bool hasOscillation);
    Response setOscillation(bool isOscillating);
    bool getHasOscillation();
    void setMode(int value);
    Mode getMode();
    void handleFanSwitch(Request request);

};


#endif //HOMEDORK_DEVICESYSTEM_FAN_H
