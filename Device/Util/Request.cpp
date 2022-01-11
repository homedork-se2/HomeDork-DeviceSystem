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
int Request::getCommand() {
    return _command;
}

/**
 * A setter that sets the type of device for the command.
 * @param deviceType (int): An integer that represents the
 * device type.
 */
void Request::setCommand(int command) {
    _command = command;
}

/**
 * The function that parses the server request into the request class.
 * @param buf (char[]): The command in a char array.
 */
void Request::parseRequest() {

    int result = 0;
    int powerOfTwo = 0;

    int incomingByte;
    incomingByte = Serial.read();
    String c = String(incomingByte);
    setId(incomingByte);
    setCommand(incomingByte);
    if (Serial.available() > 0) {
        incomingByte = Serial.read();
        if (incomingByte == 1) {
            setState(true);
        } else if (incomingByte == 0){
            setState(false);
        } else {
            setValue(incomingByte);
        }
    }
}
