//
// Created by Samuel Mcmurray on 10/14/2021.
//

#include <Light.h>

Light::Light(int id, int pin, bool isDimmable) : Device(id, pin) {

}

bool Light::getIsDimmable() {
    return isDimmable;
}

int Light::getDim() {
    return dim;
}

Response Light::setDim(int dim) {

    return Response response{200, "Success"};
}

