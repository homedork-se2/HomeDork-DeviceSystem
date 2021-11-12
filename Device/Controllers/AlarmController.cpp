//-----------------------------------------------------------------------
// File: AlarmController.cpp
// Summary: A class that handles the automation of the alarm system, monitoring the
// fire sensor and the the Security sensor.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
//-----------------------------------------------------------------------

#include "AlarmController.h"

/**
 * The Alarm Controller Constructor
 * @param fireAlarm (Alarm): The device systems fire alarm.
 * @param securityAlarm (Alarm): The device systems security alarm.
 */
AlarmController::AlarmController(Alarm fireAlarm, Alarm securityAlarm) {
    AlarmController::fireAlarm = fireAlarm;
    AlarmController::securityAlarm = securityAlarm;
}


