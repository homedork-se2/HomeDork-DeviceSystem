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
Alarm::Alarm(Light light, Sound sound, Sensor sensor, bool fireAlarm): alarmLight(light), siren(sound), alarmSensor(sensor),
            _isFireAlarm(fireAlarm){
}

/**
 * A setter for the security Alarm
 * @param request: (Request): A parameter created from the message sent by the user
 * @return (Response): returns on the success or failure of setting the alarm.
 */
void Alarm::setAlarm(bool isSet) {
    Response response;
    if (isSet) {
        setIsArmed(true);
        response.createMessage("alarm", 5, "security", 8, "armed", 5);
    } else {
        setIsArmed(false);
        if (getIsActive()) {
            setIsActive(false);
            handleAlarmTrigger();
        }
        response.createMessage("alarm", 5, "security", 8 , "disarmed", 8 );
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

/**
 * The function that will handle the triggering of the alarm or disabling of
 * the alarm.
 * @param isTriggered (bool): A boolean that represents the state the
 * alarm should be in.
 * @return (Response): The response of the request to determine if it was
 * successful.
 */
void Alarm::handleAlarmTrigger() {
    Response response;
    Request request;
    char alarm[5] = {'a', 'l', 'a', 'r', 'm'};
    if (_isFireAlarm) {
        char type[4] = {'f', 'i', 'r', 'e'};
        if (getIsActive()) {
            siren.handleSoundSwitch(true);
            delay(20);

            char state[9] = {'t', 'r', 'i', 'g', 'g', 'e', 'r', 'e', 'd'};
            response.createMessage(String(alarm), 5, String(type), 4, String(state), 9);
            response.sendMessage();

        } else {
            siren.handleSoundSwitch(false);
            delay(20);

            char state[5] = {'c', 'l', 'e', 'a', 'r'};
            response.createMessage(String(alarm), 5, String(type), 4, String(state), 5);
            response.sendMessage();
        }
    } else {
        char type[8] = {'s', 'e', 'c', 'u', 'r', 'i', 't', 'y'};
        char lamp[4] = {'l', 'a', 'm', 'p'};
        if (getIsActive()) {
            siren.handleSoundSwitch(true);
            delay(20);

            char state[9] = {'t', 'r', 'i', 'g', 'g', 'e', 'r', 'e', 'd'};
            request.setDeviceType(*lamp, 4);
            request.setState(true);
            request.setId(alarmLight.getId());

            alarmLight.handleLightSwitch(request);

            response.createMessage(String(alarm), 5, String(type), 8, String(state), 9);
            response.sendMessage();
        } else {
            siren.handleSoundSwitch(false);
            delay(20);
            char state[5] = {'c', 'l', 'e', 'a', 'r'};

            request.setDeviceType(*lamp, 4);
            request.setState(false);
            request.setId(alarmLight.getId());

            alarmLight.handleLightSwitch(request);

            response.createMessage(String(alarm), 5, String(type), 8, String(state), 5);
            response.sendMessage();
        }
    }
}
