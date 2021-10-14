//
// Created by Samuel Mcmurray on 10/14/2021.
//

#include "Device.h"
#include <Response.h>
#include "Arduino.h"

Device::Device(int id, int pin) {
    isActive = false;
};

int Device::getId() {
    return id;
}

int Device::getPin() {
    return pin;
}

bool Device::getIsActive() {
    return isActive;
}

Response Device::setIsActive() {
    isActive = !isActive;
    return Response response{200, "Success"};
}

