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
#include <Arduino.h>
#include <Light.h>
#include <Request.h>
#include <Response.h>
#include <Sensor.h>
#include <Sound.h>

class Alarm {
private:
    bool _isActive;
    bool _isArmed;
    int _id;

public:
    Sound siren;
    Sensor alarmSensor;
    Light alarmLight;

    Alarm(Light light, Sound sound, Sensor sensor, int id);
    void setAlarm(bool isSet);
    bool getIsArmed();
    void setIsArmed(bool armed);
    int getId() const;
    bool getIsActive();
    void setIsActive(bool active);
    void handleFireAlarm(bool isTriggered);
    void handleSecurityAlarm(bool isTriggered);

};


#endif //HOMEDORK_DEVICESYSTEM_ALARM_H
