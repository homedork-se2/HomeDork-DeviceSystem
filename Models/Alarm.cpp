//
// Created by Samuel Mcmurray on 10/23/2021.
//

#include "Alarm.h"

Alarm::Alarm(Light light, Sound siren, Sensor sensor) {
    this->light = light;
    this->siren = siren;
    this->sensor = sensor;
    this->isActive = false;
}

Response Alarm::setAlarm() {
    setIsActive();

}

void Alarm::setIsActive() {
    this->isActive = !isActive;
}

bool Alarm::getIsActive() {
    return this->isActive;
}

Response Alarm::handleAlarmTrigger() {
    siren.handleSoundOn();
    light.handleLightSwitch(this->light.id);
    Response response{200, "Triggered"};
    return response;
}