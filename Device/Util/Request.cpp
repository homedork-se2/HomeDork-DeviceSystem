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
void Request::setDeviceType(String deviceName) {
    if (deviceName == "lamp") {
        _deviceType = 1;
    } else if (deviceName == "fan") {
        _deviceType = 2;
    } else if (deviceName == "curtain") {
        _deviceType = 3;
    } else if (deviceName == "alarm") {
        _deviceType = 4;
    } else if (deviceName == "temp") {
        _deviceType = 5;
    } else if (deviceName == "twilight") {
        _deviceType = 6;
    } else if (deviceName == "timer") {
        _deviceType = 7;
    } else if (deviceName == "window") {
        _deviceType = 8;
    } else {
        _deviceType = 0;
    }
}

/**
 * The function that parses the server request into the request class.
 * @param buf (char[]): The command in a char array.
 */
void Request::parseRequest(byte * buf, int size) {
    char input[65];
    int count = 0;
    int flag = 0;
    int i = 0;
    while(flag != 3) {
        char c = (char) buf[i];
        i++;
        if (c == ':') {
            char cString[count];
            for (int j = 0; j < count; ++j) {
                cString[j] = input[j];
            }
            String string = String(cString);
            if (flag == 0) {
                setDeviceType(string);
                Serial.println(string);
            } else if (flag == 1) {
                Serial.println(string);
                Serial.println(string.toInt());
                setId(atoi);
                flag++;
            } else if (flag == 2) {
                if (string.equalsIgnoreCase("on")) {
                    setState(true);
                    break;
                } else {
                    setState(false);
                }
            } else {
                String value = String(atoi(cString));
                setValue(atoi(cString));
                break;
            }
            flag++;
            continue;
        }
        input[count] = c;
        count++;
    }

}
