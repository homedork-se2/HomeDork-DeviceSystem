//-----------------------------------------------------------------------
// File: WaterLeakage.h
// Summary: A class that represents a water leakage sensor in a smart
// home this class inherits from Sensor class.
// Version: 1.0
// Owner: Mustafa Ismail
//-----------------------------------------------------------------------
// Log: 2021-11-01 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
#define HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H

#include <Arduino.h>
#include <Response.h>
#include <Sensor.h>

class WaterLeakage: public Sensor{
private:
    Response handleWaterLeakage();

public :
    explicit WaterLeakage(unsigned int id);
    void readWaterLeakSensor();

};

#endif //HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
