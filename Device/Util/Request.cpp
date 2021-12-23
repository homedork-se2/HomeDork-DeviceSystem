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
unsigned int Request::getId() {
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
bool Request::isState() {
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
int Request::getValue() {
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
    Serial.println(deviceName);
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
void Request::parseRequest(const char * buf) {
    char input[15];
    int count = 0;
    int i = 0;
    int flag = 0;
    int bufSize;
    while (true) {
        char c = (char) buf[i];
        if (c == ':') {
            if (flag == 0) {
                String deviceType = String(input);
                Serial.println("Request: " + deviceType);
                Request::setDeviceType(deviceType);
            } else if (flag == 1) {
                String id = String(input);
                Serial.println("Request: " + id + "\r\n");
                Request::setId(id.toInt());
            } else if (flag == 2) {
                String stateString = String(input);
                Serial.println("Request: " + stateString );
                if (stateString.equals("ON") || stateString.equals("OPEN")) {
                    Request::setState(true);
                    break;
                } else if (stateString.equals("OFF") || stateString.equals("CLOSED")) {
                    Request::setState(false);
                    break;
                } else {
                    String value = String(input);
                    Request::setValue(value.toInt());
                    if (getValue() > 0) {
                        Request::setState(true);
                    }
                    break;
                }
            }
            count = 0;
            flag++;
            continue;
        }
        input[count] = c;
        count++;
    }

}
