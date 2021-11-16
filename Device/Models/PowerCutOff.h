//
// Created by Must on 2021-11-01.
//

#ifndef HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H
#define HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H

#include "Response.h"
#include "Arduino.h"
#include "../Util/Response.h"

class PowerCutOff {
    /**
   * An class that represent a PowerCutOff in a smart home.
   *
   * Attributes:
   *      @param id an integer who's value is the id of an instance of a subclass device.
   *
   * Methods:
   *      The PowerCutoff class.
   *      handlePowerCutOff return a response.
   *
   *
   * **/
public :
    PowerCutOff();
    PowerCutOff(unsigned int id);
    Response handlePowerCutOff();
};

#endif //HOMEDORK_DEVICESYSTEM_POWERCUTOFF_H
