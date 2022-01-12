//-----------------------------------------------------------------------
// File: TwilightAutomaticSystem.h
// Summary: A class that represent a TwilightAutomaticSystem in a smart
// home this class is a composite class that represents an automatic
// light control for the outdoor light.
// Version: 1.0
// Owner: Osayamore Edugie
//-----------------------------------------------------------------------
// Log: 2021-11-05 Created the file,
//-----------------------------------------------------------------------

#include "TwilightAutomaticSystem.h"

/**
 * The constructor of the TwilightAutomaticSystem class.
 * @param sensor (Sensor): The light sensor to determine when the light becomes low
 * to turn on the outdoor light
 * @param outdoorLight (Light): The light that will be modified based on the state
 * of the sensor.
 */
TwilightAutomaticSystem::TwilightAutomaticSystem(Sensor sensor, Light outdoorLight): _lightSensor(sensor), _outdoorLight(outdoorLight) {
}

/**
 *
 * @return
 */
bool TwilightAutomaticSystem::isActive() {
    return _isActive;
}

void TwilightAutomaticSystem::setActive(bool isActive) {
    _isActive = isActive;
}

/**
 * The function that will handle the reading of the light sensor to help determine
 * the light state.
 * @return (boolean): A returns to state of the light sensor
 */
void TwilightAutomaticSystem::readLightSensor() {
    Response response{70, "ERROR;"};
    int value = this->_lightSensor.readAnalogSensor();
    this->setActive(true);
    if (value > 250 && !this->_outdoorLight.getIsActive() && !change) {
        if (this->isActive()) {
            handleTwilightSystem(true);
            change = true;
            response.createMessage(String(70), String(1));
            response.sendMessage();
        }

    } else if ((this->_outdoorLight.getIsActive() && !this->isActive() && change && value < 250)) {
        handleTwilightSystem(false);
        change = false;
        response.createMessage(String(70), String(0));
        response.sendMessage();
    }

}

/**
 * The function that will handle the state change for the light.
 * @return (Response): A response that is sent to the server to handle
 * the state change in the twilight system.
 */
void TwilightAutomaticSystem::handleTwilightSystem(bool state) {
    Request request;
    request.setId(this->_outdoorLight.getId());
    request.setState(state);
    _outdoorLight.handleLightSwitch(request);

}