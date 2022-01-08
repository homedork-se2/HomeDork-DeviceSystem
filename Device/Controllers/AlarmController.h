//-----------------------------------------------------------------------
// File: AlarmController.h
// Summary: A class that handles the automation of the alarm system, monitoring the
// fire sensor and the the Security sensor.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
//      2021-11-16 revised by Ibrahim Ali created the runAlarm method
// which monitors the security and fire alarms.
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H

#include <Alarm.h>
#include <DeviceController.h>
#include <Arduino.h>
#include <Response.h>

class AlarmController {
private:
    Alarm _fireAlarm;
    Alarm _securityAlarm;
public:
    AlarmController(Alarm fireAlarm, Alarm securityAlarm);
    void runAlarm();
    bool shouldRun();
};

#endif //HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
