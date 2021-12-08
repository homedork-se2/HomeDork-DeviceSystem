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
private:
    int _statusCode;
    String _message;
public:
    Response(int statusCode, String message);
    int getStatusCode();
    void setStatusCode(int statusCode);
    String getMessage();
    void setMessage(String message);
    void sendMessage();
};


#endif //HOMEDORK_DEVICESYSTEM_RESPONSE_H
