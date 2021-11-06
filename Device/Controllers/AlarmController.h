//
// Created by Samuel Mcmurray on 10/23/2021.
//

#ifndef HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
#define HOMEDORK_DEVICESYSTEM_ALARMCONTROLLER_H
#include "../Models/Alarm.h"
#include "Arduino.h"

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
