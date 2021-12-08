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
 * The Response class constructor.
 * @param statusCode (int): An integer who's value represents the success or failure of the command given.
 * @param message (String):
 */
Response::Response(int statusCode, String message): _statusCode(statusCode), _message(message) {
}

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
void Response::setMessage(String message) {
    _message = message;
}

/**
 * A setter to set the status code.
 * @param statusCode (int): The status code.
 */
void Response::setStatusCode(int statusCode) {
    _statusCode = statusCode;
}

void Response::sendMessage() {
    int length = getMessage().length();
    byte buf[length];
    String string = getMessage();
    string.getBytes(buf, length);

    Serial.write(buf, length);
}
