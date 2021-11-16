//
// Created by Samuel Mcmurray on 10/14/2021.
//

#include "Response.h"

Response::Response(int statusCode, String message) {
    this->statusCode = statusCode;
    this->message = message;
}

int Response::getStatusCode() {
    return this->statusCode;
}

String Response::getMessage() {

    return this->message;
}

void Response::setMessage(String message) {
    Response::message = message;
}

void Response::setStatusCode(int statusCode) {
    Response::statusCode = statusCode;
}
