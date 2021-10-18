//
// Created by ibrahim Ahmed ali on 10/18/2021.
//

#include "Fan.h"

Fan::Fan(int id, bool hasMultiMode, bool hasOscillation) : Device(id) {

}

bool Fan::getHasMultiMode()  {
    return hasMultiMode;
}

Response Fan::setHasMultiMode(bool hasMultiMode) {
    Fan::hasMultiMode = hasMultiMode;
    return Response response{200, "Success"};
}

bool Fan::getHasOscillation()  {
    return hasOscillation;
}

Response Fan::setHasOscillation(bool hasOscillation) {
    Fan::hasOscillation = hasOscillation;
    return Response response{200, "Success"};
}

