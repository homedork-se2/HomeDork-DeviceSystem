//
// Created by Samuel Mcmurray on 10/14/2021.
//
#include "Device.h"
#include "Response.h"
#include "Arduino.h"

Device::Device(unsigned int id) {
    Device::id = id;
    Device::isActive = false;
};

unsigned int Device::getId() const {
    return id;
}

bool Device::getIsActive() const {
    return isActive;
}

void Device::setIsActive(bool active) {
    Device::isActive = active;
}

