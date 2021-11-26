//-----------------------------------------------------------------------
// File: Response.h
// Summary: A class that represents a command response to the server of
// the smart home.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-14 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_RESPONSE_H
#define HOMEDORK_DEVICESYSTEM_RESPONSE_H
#include <Arduino.h>

class Response {
/**
     * A class that represents a command response to the server of the smart home.
     *
     * Attributes:
     *      @param statusCode an integer who's value represents the success or failure of the command given.
     *      @param message an inte who's value is the pin location on the Arduino device.
     *
     * Methods:
     *      getStatusCode: returns a http code for success, or any other that may occur.
     *      setStatusCode: returns void takes an integer as a parameter for the status code.
     *      getmessage: returns a string.
     *      setMessage: returns void takes a string message as a parameter.
     * **/
private:
    int statusCode;
    String message;
public:
    Response(int statusCode, String message);
    int getStatusCode();
    void setStatusCode(int statusCode);
    String getMessage();
    void setMessage(String message);
};


#endif //HOMEDORK_DEVICESYSTEM_RESPONSE_H
