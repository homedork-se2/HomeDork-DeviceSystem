//-----------------------------------------------------------------------
// File: Request.cpp
// Summary: A class that represents a request from the server contains
// the variables that will be used to run the commands.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-11-07 Created the file,
//-----------------------------------------------------------------------


#include "Request.h"

/**
 * A getter that gets the id of device for the command.
 * @return (unsigned int): An integer who's value is the id of an instance
 * of a device that will be used in handling the command.
 */
unsigned int Request::getId() const {
    return _id;
}

/**
 * A setter that gets the id of device for the command.
 * @param id (unsigned int): An integer who's value is the id of an instance
 * of a device that will be used in handling the command.
 */
void Request::setId(unsigned int id) {
    _id = id;
}

/**
 * A getter that gets the state of the the device for the command.
 * @return (bool): A boolean who's value is the state of an instance
 * of a device that will be used in handling the command.
 */
bool Request::isState() const {
    return _state;
}

/**
 * A setter that sets the state of the the device for the command.
 * @param state
 */
void Request::setState(bool state) {
    _state = state;
}

/**
 * A getter that gets the value of the the device for the command.
 * @return (int): The value as an integer.
 */
int Request::getValue() const {
    return _value;
}

/**
 * A setter that sets the value of device for the command.
 * @param value (int): The value as an integer.
 */
void Request::setValue(int value) {
    _value = value;
}

/**
 * A getter that gets the type of the the device for the command.
 * @return (int): An integer that represents a
 */
int Request::getDeviceType() {
    return _deviceType;
}

/**
 * A setter that sets the type of device for the command.
 * @param deviceType (int): An integer that represents the
 * device type.
 */
void Request::setDeviceType(int device) {
    _deviceType = device;
}

/**
 * The function that parses the server request into the request class.
 * @param buf (char[]): The command in a char array.
 */
void Request::parseRequest(char buf[]) {
    char input[15];
    int count = 0;
    int flag = 0;
    int bufSize = sizeof(&buf) / sizeof(&buf[0]);
    for (int i = 0; i < bufSize; ++i) {
        char c = buf[i];
        if (c == ':') {
            if (flag == 0) {
                String stringValue = input;
                if (stringValue == "lamp") {
                    setDeviceType(1);
                } else if (stringValue == "fan") {
                    setDeviceType(2);
                }
                setDeviceType(0);
            } else if (flag == 1) {
                setId(atoi(input));
            } else if (flag == 2) {
                String stateString = input;
                if (stateString == "ON") {
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
