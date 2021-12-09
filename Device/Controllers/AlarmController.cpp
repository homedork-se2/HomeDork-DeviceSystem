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
void AlarmController::runAlarm() {
    _securityAlarm.setIsArmed(true);
    int reading = _fireAlarm.alarmSensor.readDigitalSensor();
    if (reading == HIGH && !_fireAlarm.getIsActive()) {
        _fireAlarm.handleAlarmTrigger(true, true);
    } else if (_fireAlarm.getIsActive()) {
        _fireAlarm.handleAlarmTrigger(false, true);
    }

    reading = _securityAlarm.alarmSensor.readDigitalSensor();
    if (reading == LOW && _securityAlarm.getIsArmed() && !_securityAlarm.getIsActive()) {
        _securityAlarm.handleAlarmTrigger(true, false);
    } else if (reading == HIGH || (_securityAlarm.getIsActive() && !_securityAlarm.getIsArmed())){
        _securityAlarm.handleAlarmTrigger(false, false);
    }
}
