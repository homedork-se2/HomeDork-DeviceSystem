//-----------------------------------------------------------------------
// File: AlarmController.cpp
// Summary: A class that handles the automation of the alarm system, monitoring the
// fire sensor and the the Security sensor.
// Version: 1.1
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
// Log: 2021-11-16 runAlarm check both fire and securityAlarm to so if they are triggered the alarm will go off. Ibrahim
// Log: 2021-12-07 Just added so that respond is send. Ibrahim
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
        int reading = _fireAlarm.alarmSensor.readDigitalSensor();
        if (reading == HIGH) {
            _fireAlarm.handleAlarmTrigger(true);
            //Serial.println("Alarm is Triggered!");
             response.setMessage("FireAlarm:Triggered")
        } else {
            _fireAlarm.handleAlarmTrigger(false);
            //Serial.println("Alarm is OFF");
             response.setMessage("FireAlarm:Disarmed")
        }

        reading = _securityAlarm.alarmSensor.readDigitalSensor();
        if (reading == HIGH && _securityAlarm.getIsArmed()) {
            _securityAlarm.handleAlarmTrigger(true);
            //Serial.println("Alarm is Triggered!");
            response.setMessage("SecurityAlarm:Triggered")
        } else {
            _securityAlarm.handleAlarmTrigger(false);
            //Serial.println("Alarm is OFF");
            response.setMessage("SecurityAlarm:Disarmed")
        }
    }

    return response;
}


