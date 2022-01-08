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
void Request::setDeviceType(char * deviceName, int size) {
    Serial.println(deviceName);
    if (size == 3) {
        if (deviceName[0] == 'f' && deviceName[1] == 'a' && deviceName[2] == 'n') {
            _deviceType = 2;
        } else {
            Serial.println("error");
            _deviceType = 0;
        }
    } else if (size == 4) {
        if (deviceName[0] == 'l' && deviceName[1] == 'a' && deviceName[2] == 'm' && deviceName[3] == 'p') {
            _deviceType = 2;
        } else if (deviceName[0] == 't' && deviceName[1] == 'e' && deviceName[2] == 'm' && deviceName[3] == 'p') {
            _deviceType = 5;
        }
    } else if (size == 5) {
        if (deviceName[0] == 'a' && deviceName[1] == 'l' && deviceName[2] == 'a'
            && deviceName[3] == 'r' && deviceName[4] == 'm') {
            _deviceType = 4;
        } else if (deviceName[0] == 't' && deviceName[1] == 'i' && deviceName[2] == 'm'
            && deviceName[3] == 'e' && deviceName[4] == 'r') {
            _deviceType = 7;
        } else {
            Serial.println("error");
            _deviceType = 0;
        }
    } else if (size == 6) {
        if (deviceName[0] == 'w' && deviceName[1] == 'i' && deviceName[2] == 'n'
            && deviceName[3] == 'd' && deviceName[4] == 'o' && deviceName[5] == 'w') {
            _deviceType = 8;
        } else {
            Serial.println("error");
            _deviceType = 0;
        }
    } else if (size == 7) {
        if (deviceName[0] == 'c' && deviceName[1] == 'u' && deviceName[2] == 'r'
            && deviceName[3] == 't' && deviceName[4] == 'a' && deviceName[5] == 'i' && deviceName[6] == 'n') {
            _deviceType = 3;
        } else {
            Serial.println("error");
            _deviceType = 0;
        }
    } else if (size == 8){
        if (deviceName[0] == 't' && deviceName[1] == 'w' && deviceName[2] == 'i'
            && deviceName[3] == 'l' && deviceName[4] == 'i' && deviceName[5] == 'g'
            && deviceName[6] == 'h' && deviceName[7] == 't') {
            _deviceType = 6;
        } else {
            Serial.println("error");
            _deviceType = 0;
        }
    }
}

/**
 * The function that parses the server request into the request class.
 * @param buf (char[]): The command in a char array.
 */
void Request::parseRequest(char * buf, int size) {
    char input[size];
    Serial.println("Request parsing.... ");
    int flag = 0;
    int count = 0;
    for (count; count < size; ++count) {
        char c = (char) buf[count];
        if (c == ':') {
            if (flag == 0) {
                char * deviceType = input;
                Request::setDeviceType(deviceType, count - 1);
                Serial.print("Request: ");
                Serial.println(deviceType);
            } else if (flag == 1) {
                unsigned int id = atoi(String(input));
                Serial.print("Request: ");
                Serial.println(id);
                Request::setId(id);
            } else if (flag == 2) {
                char * stateString = input;
                Serial.print("Request: ");
                Serial.println(stateString);
                if (count - 1 == 2) {
                    if (stateString[0] == 'O' && stateString[1] == 'N') {
                        setState(true);
                    } else {
                        setValue(atoi(stateString));
                        if (getValue() > 0) {
                            Request::setState(true);
                        }
                    }
                } else if (count - 1 == 3) {
                    if (stateString[0] == 'O' && ((stateString[1] == 'F' && stateString[2] == 'F'))){
                        setState(false);
                    } else {
                        setValue(atoi(stateString));
                        if (getValue() > 0) {
                            Request::setState(true);
                        }
                    }
                    break;
                } else if (count - 1 == 4) {
                    if (stateString[0] == 'O' && stateString[1] == 'P' && stateString[3] == 'E' && stateString[4] == 'N') {
                        setState(true);
                    }
                    Serial.println("ERROR");
                    setValue(0);
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
