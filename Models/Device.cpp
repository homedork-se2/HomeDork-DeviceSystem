//
// Created by Samuel Mcmurray on 10/14/2021.
//
#include "Device.h"
#include "../Util/Response.h"
#include "Arduino.h"

Device::Device(unsigned int id) {
    this ->id = id;
    this->isActive = false;
};

unsigned int Device::getId() const {
    return this->id;
}

bool Device::getIsActive() const {
    return this->isActive;
}

void Device::setIsActive() {
    this->isActive = !isActive;
}

