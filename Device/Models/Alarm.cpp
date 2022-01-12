//-----------------------------------------------------------------------
// File: Alarm.cpp
// Summary: The Alarm class a composite of a light, sound, and sensor.
// This class handles the alarm functions.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file.
//-----------------------------------------------------------------------

#include "Alarm.h"

/**
 * The Alarm constructor takes the light, sound, and sensor objects as paramaters.
 * @param light (Light): The security light that will be turned on if the alarm is triggered.
 * @param siren (Sound): The siren that produces a sound when an alarm is triggered.
 * @param sensor (Sensor): The sensor which will determine if the alarm should be triggered.
 */
Alarm::Alarm(Light light, Sound sound, Sensor sensor, int id): alarmLight(light), siren(sound), alarmSensor(sensor), _id(id){
    setIsArmed(true);
}

/**
 * A setter for the security Alarm
 * @param request: (Request): A parameter created from the message sent by the user
 * @return (Response): returns on the success or failure of setting the alarm.
 */
void Alarm::setAlarm(bool isSet) {
    Response response{400, "ERROR"};
    if (isSet) {
        setIsArmed(true);
        response.createMessage(String(getId()), String(1));
    } else {
        setIsArmed(false);
        if (getIsActive()) {
            handleSecurityAlarm(false);
        }
        response.createMessage(String(getId()), String(0));
    }
    response.sendMessage();
}

/**
 * A setter for the alarm as active or inactive while active the siren will sound
 * and the light will be on.
 * @param active (boolean):
 */
void Alarm::setIsActive(bool active) {
    _isActive = active;
}

/**
 * A getter for the alarm as active or inactive while active the siren will sound
 * and the light will be on.
 * @return (boolean): The current state represented as a boolean.
 */
bool Alarm::getIsActive() {
    return _isActive;
}

/**
 * A getter for the alarm as armed or disarmed while armed the alarm can be
 * triggered by the sensor.
 * @return (bool): The state of the alarm armed or disarmed.
 */
bool Alarm::getIsArmed() {
    return _isArmed;
}

/**
 * A setter for the alarm as armed or disarmed while armed the alarm can be
 * triggered by the sensor.
 * @param armed (bool): A boolean to set whether the alarm is armed or
 * disarmed.
 */
void Alarm::setIsArmed(bool armed) {
    _isArmed = armed;
}

int Alarm::getId() const {
    return _id;
}

/**
 * The function that will handle the triggering of the alarm or disabling of
 * the alarm.
 * @param isTriggered (bool): A boolean that represents the state the
 * alarm should be in.
 * @return (Response): The response of the request to determine if it was
 * successful.
 */
void Alarm::handleFireAlarm(bool isTriggered) {
    Response response{500, ":ERROR"};
    response.createMessage(String(this->getId()), String(500));
    Request request;

    if (isTriggered) {
        this->siren.handleSoundSwitch(isTriggered);
        response.createMessage(String(getId()), String(1));
        this->setIsActive(true);
    } else if (!isTriggered) {
        this->siren.handleSoundSwitch(isTriggered);
        this->setIsActive(false);
        response.createMessage(String(getId()), String(0));
    }
    delay(200);
    setIsActive(isTriggered);
    response.sendMessage();
}

void Alarm::handleSecurityAlarm(bool isTriggered) {
    Response response{500, ":ERROR"};
    response.createMessage(String(this->getId()), String(500));
    if (isTriggered) {
        if (getIsArmed()) {
            this->siren.handleSoundSwitch(isTriggered);
            this->setIsActive(true);
            request.setCommand(23);
            request.setState(true);
            request.setId(alarmLight.getId());
            this->alarmLight.handleLightSwitch(request);
            response.createMessage(String(getId()), String(1));
        }
    } else if (!isTriggered) {
        this->siren.handleSoundSwitch(isTriggered);
        request.setCommand(23);
        request.setState(false);
        request.setId(alarmLight.getId());
        this->alarmLight.handleLightSwitch(request);
        this->setIsActive(false);
        response.createMessage(String(getId()), String(0));
    }
    delay(200);
    setIsActive(isTriggered);
    response.sendMessage();
}
