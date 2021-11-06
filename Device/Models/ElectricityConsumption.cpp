//
// Created by Dell on 11/5/2021.
//

#include "ElectricityConsumption.h"

ElectricityConsumption::ElectricityConsumption(int id): Device(id) {

}

Response ElectricityConsumption::getElectricUsage() {
    Response response{200, "Message"};
    return response;
}