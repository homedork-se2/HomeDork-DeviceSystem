//-----------------------------------------------------------------------
// File: Alarm.cpp
// Summary: The Alarm class a composite of a light, sound, and sensor.
// This class handles the alarm functions.
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file.
// Log: 2021-11-16 changed handleAlarmTrigger.
//-----------------------------------------------------------------------
#include "Alarm.h"
#include "Request.h"
#include "Response.h"

/**
 * The Alarm constructor takes the light, sound, and sensor objects as paramaters.
 * @param light (Light):
 * @param siren
 * @param sensor
 */
Alarm::Alarm(Light light, Sound siren, Sensor sensor) {
    Alarm::light = light;
    Alarm::siren = siren;
    Alarm::sensor = sensor;
    Alarm::isActive = false;

}

/**
 *
 * @param request
 * @return
 */
Response Alarm::setAlarm(Request request) {
    if (!request.isState()) {
        siren.setIsActive(false);

    }
    setIsArmed(request.isState());
}

/**
 *
 * @param active
 */
void Alarm::setIsActive(bool active) {
    Alarm::isActive = active;
}

/**
 *
 * @return
 */
bool Alarm::getIsActive() {
    return isActive;
}

/**
 *
 * @return
 */
bool Alarm::getIsArmed() {
    return isArmed;
}

/**
 *
 * @param armed
 */
void Alarm::setIsArmed(bool armed) {
    Alarm::isArmed = armed;
}

/**
 *
 * @return
 */
Response Alarm::handleAlarmTrigger(bool triggered) {
    Response response{500, "Failure"};
    Request request;
    if (triggered) {
        siren.handleSoundSwitch(true);
        request.setDeviceType("LIGHT");
        request.setState(true);
        request.setId(light.getId());
        light.handleLightSwitch(request);
        setIsActive(true);
    } else {
        siren.handleSoundSwitch(false);
        request.setDeviceType("LIGHT");
        request.setState(false);
        request.setId(light.getId());
        light.handleLightSwitch(request);
        setIsActive(false);
    }



    response.setStatusCode(200)
    response.set
    return response;
}
