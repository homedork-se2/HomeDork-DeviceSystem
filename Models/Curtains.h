//
// Created by Hi on 10/18/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_CURTAINS_H
#define HOMEDORK_DEVICESYSTEM_CURTAINS_H
#include "Device.h"
#include "Response.h"
#include "Arduino.h"


class Curtains: public Device{
public:
    Curtains(int id);
    Response handleCurtainSwitch();
};


#endif //HOMEDORK_DEVICESYSTEM_CURTAINS_H
