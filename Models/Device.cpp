//
// Created by Samuel Mcmurray on 10/14/2021.
//
#include <Device.h>
#include <Response.h>
#include <Arduino.h>

Device::Device(unsigned int id) {
    this ->id = id;
    isActive = false;
};

unsigned int Device::getId() {
    return this->id;
}

bool Device::getIsActive() {
    return this->isActive;
}

void Device::setIsActive() {
    isActive = !isActive;
}

