//
// Created by Samuel Mcmurray on 10/14/2021.
//

#include "Response.h"

Response::Response(int statusCode, String message) {

}

int Response::getStatusCode() {
    return 0;
}

String Response::getMessage() {
    return String();
}

void Response::setMessage(String message) {
    this->message = message;
}

void Response::setStatusCode(int statusCode) {

}
