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
    int _statusCode = 404;
    String _message;
    int _messageLength = 0;
public:
    int getStatusCode();
    void setStatusCode(int statusCode);
    String getMessage();
    void createMessage(String type, int tSize, String id, int idSize, String, int stateSize);
    void setMessage(String message, int size);
    int getMessageLength();
    void setMessageLength(int len);
    void sendMessage();


};


#endif //HOMEDORK_DEVICESYSTEM_RESPONSE_H
