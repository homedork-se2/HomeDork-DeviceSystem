//-----------------------------------------------------------------------
// File: Response.h
// Summary: A class that represents a command response to the server of
// the smart home.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//-----------------------------------------------------------------------

#include "Response.h"

/**
 * A getter for the status code.
 * @return (int): The status code.
 */
int Response::getStatusCode() {
    return _statusCode;
}

/**
 * A getter for the message.
 * @return (String): The message.
 */
String Response::getMessage() {
    return _message;
}

/**
 * A setter to set the message.
 * @param message (String): The message.
 */
void Response::setMessage(String message, int size) {
    _message = message;
    _messageLength = size;
}

/**
 * A setter to set the status code.
 * @param statusCode (int): The status code.
 */
void Response::setStatusCode(int statusCode) {
    _statusCode = statusCode;
}

void Response::createMessage(String type, int tSize, String id, int idSize, String state, int stateSize) {
    String string = type;
    string.concat(":");
    string.concat(id);
    string.concat(":");
    string.concat(state);
    setMessage(string, string.length());
}


void Response::sendMessage() {
<<<<<<< HEAD
    byte buf[_messageLength];
    for (int i = 0; i < _messageLength; ++i) {
        buf[i] = (byte) _message[i];
    }

    Serial.write(buf, _messageLength);
=======
    Serial.println(getMessage());
    Serial.flush();
>>>>>>> 40d52950655ecf9ddec15aa4122625812e38c356
}

void Response::setMessageLength(int len) {
    _messageLength = len;
}

int Response::getMessageLength() {
    return _messageLength;
}


