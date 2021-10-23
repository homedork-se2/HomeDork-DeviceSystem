//
// Created by Ibrahim on 10/18/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_FAN_H
#define HOMEDORK_DEVICESYSTEM_FAN_H
#include "Device.h"
#include "Arduino.h"


class Fan: public Device{
    /**
     * An class that represent a Fan in a smart home this class inherits from Abstract Device class.
     *
     * Attributes:
     *      @param id an integer who's value is the id of an instance of a subclass device.
     *      @Param hasOscillation an boolean which if true the fan oscillates else
     *      @Param hasMultiMode an boolean which if true the fan oscillates else
     *
     *
     * Methods:
     *      getPin: returns an integer of the devices pin (The location on the arduino)
     *      getHasOscillation: returns boolean that states if the fan is oscillating or not
     *      getMultiMode: returns boolean that states if the fan has multiMode
     *      setHasOscillation: change the boolean for oscillation return response
     *
     * **/
private:
    bool hasMultiMode;
    bool hasOscillation;

public:
    Fan(int id, bool hasMultiMode, bool hasOscillation);


    bool getHasMultiMode() ;

    void setHasMultiMode(bool hasMultiMode);

    void setHasOscillation(bool hasOscillation);

    bool getHasOscillation();

};


#endif //HOMEDORK_DEVICESYSTEM_FAN_H
