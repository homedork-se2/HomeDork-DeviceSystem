//
// Created by Samuel Mcmurray on 11/7/2021.
//

#include <cstdlib>
#include "Request.h"


unsigned int Request::getId() const {
    return id;
}

void Request::setId(unsigned int id) {
    Request::id = id;
}

bool Request::isState() const {
    return state;
}

void Request::setState(bool state) {
    Request::state = state;
}

int Request::getValue() const {
    return value;
}

void Request::setValue(int value) {
    Request::value = value;
}

String Request::getDeviceType() {
    return deviceType;
}

void Request::setDeviceType(String deviceType) {
    Request::deviceType = deviceType;
}

void Request::parseRequest(char buf[]) {
    char input[15];
    int count = 0;
    int flag = 0;
    for (char c: &buf) {
        if (c == ':') {
            if (flag == 0) {
                setDeviceType(input);
            } else if (flag == 1) {
                setId(atoi(input));
            } else if (flag == 2) {
                String stateString = input;
                if (stateString.equalsIgnoreCase("ON")) {
                    setState(true);
                } else {
                    setState(false);
                }
            } else {
                setValue(atoi(input));
            }
            count = 0;
            flag++;
            continue;
        }
        input[count] = c;
        count++;
    }

}


