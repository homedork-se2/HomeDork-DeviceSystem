//-----------------------------------------------------------------------
// File: TwilightAutomaticSystem.h
// Summary: A class that represents a water leakage sensor in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Osas
//-----------------------------------------------------------------------
// Log: 2021-11-05 Created the file,
//-----------------------------------------------------------------------

#include "TwilightAutomaticSystem.h"

TwilightAutomaticSystem::TwilightAutomaticSystem(Sensor sensor, Light outdoorLight) {
    TwilightAutomaticSystem::lightSensor = sensor;
    TwilightAutomaticSystem::outdoorLight =outdoorLight;

}

bool TwilightAutomaticSystem::getSensorState() {
    return lightSensor.readLightSensor();
}

Response TwilightAutomaticSystem::handleTwilightSystem() {
    Response response{200, "Starting System"};
    return response;
}