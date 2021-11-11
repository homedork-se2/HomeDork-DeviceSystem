//-----------------------------------------------------------------------
// File: Alarm.h
// Summary: The Alarm class a composite of a light, sound, and sensor.
// This class handles the alarm functions.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_ALARM_H
#define HOMEDORK_DEVICESYSTEM_ALARM_H
#include "Arduino.h"
#include "Light.h"
#include "Sensor.h"
#include "Sound.h"

#include "../Util/Response.h"
#include "../Util/Request.h"

class Alarm {
    /**
     * An class that represents the Thermometer in a smart home this class inherits from the Abstract Device class.
     *
     * Attributes:
     *      @param isActive A boolean that keeps track of the armed state of the alarm.
     *      @param light The security/fire Light class instance for the alarm.
     *      @param siren This is a Sound class instance that handles the alarm sound.
     *      @param sensor This is an instance of the sensor class in this project it will be a switch,
     *      this is for the simulation of such an alarm going off.
     *
     * Methods:
     *      Constructor takes the light, sound, and sensor objects as paramaters.
     *      setAlarm returns a response sets the alarm to an active monitoring state.
     *      handleAlarmTrigger returns a response triggers the alarm if inactive and turns off the system when not active.
     *      setIsActive returns void sets the inverse of the state which manages if the alarm is active.
     *      getIsActive returns boolean gets the current active state of the alarm.
     *
     * **/
private:
    bool isActive;
    bool isArmed;
    Sound siren;
    Sensor sensor;
    Light light;
public:
    Alarm(Light light, Sound siren, Sensor sensor);

    Response setAlarm();

    bool getIsArmed();

    bool setIsArmed(bool armed);

    bool getIsActive();

    void setIsActive(bool active);

    Response handleAlarmTrigger();
};


#endif //HOMEDORK_DEVICESYSTEM_ALARM_H
