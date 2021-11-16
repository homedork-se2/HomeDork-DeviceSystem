//-----------------------------------------------------------------------
// File: WaterLeakage.h
// Summary: A class that represents a water leakage sensor in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Mustafa
//-----------------------------------------------------------------------
// Log: 2021-11-01 Created the file,
//-----------------------------------------------------------------------
#ifndef HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
#define HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H

#include "Sensor.h"
#include "Response.h"
#include "Arduino.h"

class WaterLeakage: public Sensor{
    /**
   * A class that represent a WaterLeakage in a smart home.
   *
   * Attributes:
   *      @param id an integer who's value is the id of an instance of a subclass device.
   *
   * Methods:
   *      The Waterleakage class.
   *      handleWaterLeakage returns a response.
   *
   * **/
private:

public :
    explicit WaterLeakage(unsigned int id);

    Response handleWaterLeakage();

    void readWaterLeakSensor();
};

#endif //HOMEDORK_DEVICESYSTEM_WATERLEAKAGE_H
