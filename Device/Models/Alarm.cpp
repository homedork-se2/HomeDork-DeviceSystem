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
Response Alarm::handleAlarmTrigger() {
    Response response{500, "Failure"};
    Request request =
    setIsActive(true);

    siren.handleSoundOn();
    light.handleLightSwitch(Req);
    setIsActive(true);
    response.setStatusCode(200)
    response.set
    return response;
}
