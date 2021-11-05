//
// Created by Dell on 11/5/2021.
//

#include "TwilightAutomaticSystem.h"

TwilightAutomaticSystem::TwilightAutomaticSystem(int id) {
    this-> id = id;

}

bool TwilightAutomaticSystem::getSensorState() {
    return lightSensor.readLightSensor();
}

Response TwilightAutomaticSystem::handleTwilightSystem() {
    Response response{200, "Starting System"};
    return response;
}



