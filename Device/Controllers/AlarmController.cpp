//-----------------------------------------------------------------------
// File: AlarmController.cpp
// Summary: A class that handles the automation of the alarm system, monitoring the
// fire sensor and the the Security sensor.
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
// Log: 2021-11-16 runAlarm check both fire and securityAlarm to so if they are triggered the alarm will go off.
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

Response AlarmController::runAlarm() {
    Response response {500, "exit while loop error"};
    while (true) {
        int reading = fireAlarm.sensor.readDigitalSensor();
        if (reading == HIGH) {
            fireAlarm.handleAlarmTrigger(true);
            //Serial.println("Alarm is Triggered!");
        } else {
            fireAlarm.handleAlarmTrigger(false);
            //Serial.println("Alarm is OFF");
        }

        reading = securityAlarm.sensor.readDigitalSensor();
        if (reading == HIGH && securityAlarm.getIsArmed()) {
            securityAlarm.handleAlarmTrigger(true);
            //Serial.println("Alarm is Triggered!");
        } else {
            securityAlarm.handleAlarmTrigger(false);
            //Serial.println("Alarm is OFF");
        }
    }

    return response;
}


