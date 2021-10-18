//
// Created by ibrahim Ahmed ali on 10/18/2021.
//

#include "Fan.h"

Fan::Fan(int id, bool hasMultiMode, bool hasOscillation) : Device(id) {
    this->hasMultiMode = hasMultiMode;
    this->hasOscillation = hasOscillation;
}

bool Fan::getHasMultiMode()  {
    return hasMultiMode;
}

void Fan::setHasMultiMode(bool hasMultiMode) {
    this->hasMultiMode = hasMultiMode;
}

bool Fan::getHasOscillation()  {
    return hasOscillation;
}

void Fan::setHasOscillation(bool hasOscillation) {
    this->hasOscillation = hasOscillation;
}

