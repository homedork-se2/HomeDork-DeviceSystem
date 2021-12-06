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
Alarm::Alarm(Light light, Sound sound, Sensor sensor): alarmLight(light), siren(sound), alarmSensor(sensor){
}

/**
 * A setter for the security Alarm
 * @param request: (Request): A parameter created from the message sent by the user
 * @return (Response): returns on the success or failure of setting the alarm.
 */
Response Alarm::setAlarm(Request request) {
    if (!request.isState()) {
        handleAlarmTrigger(false);
    }
    setIsArmed(request.isState());
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

/**
 * The function that will handle the triggering of the alarm or disabling of
 * the alarm.
 * @param isTriggered (bool): A boolean that represents the state the
 * alarm should be in.
 * @return (Response): The response of the request to determine if it was
 * successful.
 */
Response Alarm::handleAlarmTrigger(bool isTriggered) {
    Response response{500, "Failure"};
    Request request;
    if (isTriggered) {
        siren.handleSoundSwitch(true);
        request.setDeviceType("light");
        request.setState(true);
        request.setId(alarmLight.getId());
        alarmLight.handleLightSwitch(request);
        setIsActive(true);
        response.setStatusCode(200);
        response.setMessage("ON");
    } else {
        siren.handleSoundSwitch(false);
        request.setDeviceType("light");
        request.setState(false);
        request.setId(alarmLight.getId());
        alarmLight.handleLightSwitch(request);
        setIsActive(false);
        response.setStatusCode(200);
        response.setMessage("OFF");
    }

    return response;
}
