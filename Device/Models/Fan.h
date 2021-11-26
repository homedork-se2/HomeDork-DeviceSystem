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
#include <Mode.h>

enum Mode{LOW, MEDIUM, HIGH};

class Fan: public Device{
private:
    bool hasMultiMode;
    bool hasOscillation;
    Mode fanMode;

public:
    Fan(unsigned int id, bool hasMultiMode, bool hasOscillation);
    bool getHasMultiMode() ;
    void setHasMultiMode(bool hasMultiMode);
    void setHasOscillation(bool hasOscillation);
    Response setOscillation(bool isOscillating);
    bool getHasOscillation();
    Response handleFanSwitch();

};


#endif //HOMEDORK_DEVICESYSTEM_FAN_H
