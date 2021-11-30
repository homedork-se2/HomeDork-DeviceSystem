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
 * The alarm controller constructor.
 * @param fireAlarm (Alarm): The fire alarm.
 * @param securityAlarm (Alarm): The security Alarm.
 */
AlarmController::AlarmController(Alarm fireAlarm, Alarm securityAlarm) : _fireAlarm(fireAlarm), _securityAlarm(securityAlarm) {
}

/**
 * The function handles the alarm sensor reading and then triggering the
 * alarm when the sensor is
 * @return
 */
Response AlarmController::runAlarm() {
    Response response {500, "exit while loop error"};
    while (true) {
        int reading = _fireAlarm.alarmSensor.readDigitalSensor();
        if (reading == HIGH) {
            _fireAlarm.handleAlarmTrigger(true);
            //Serial.println("Alarm is Triggered!");
        } else {
            _fireAlarm.handleAlarmTrigger(false);
            //Serial.println("Alarm is OFF");
        }

        reading = _securityAlarm.alarmSensor.readDigitalSensor();
        if (reading == HIGH && _securityAlarm.getIsArmed()) {
            _securityAlarm.handleAlarmTrigger(true);
            //Serial.println("Alarm is Triggered!");
        } else {
            _securityAlarm.handleAlarmTrigger(false);
            //Serial.println("Alarm is OFF");
        }
    }

    return response;
}