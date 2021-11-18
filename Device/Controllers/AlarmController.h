//-----------------------------------------------------------------------
// File: AlarmController.h
// Summary: A class that handles the automation of the alarm system, monitoring the
// fire sensor and the the Security sensor.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
#include <Alarm.h>
#include <Arduino.h>

class AlarmController {
private:
    Alarm fireAlarm;
    Alarm securityAlarm;
public:
    AlarmController(Alarm fireAlarm, Alarm securityAlarm);
    runFireAlarm();
    runSecurityAlarm();
};


#endif //HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
