//-----------------------------------------------------------------------
// File: WaterLeakage.cpp
// Summary: A class that represents a Water leakage sensor in a smart
// home this class inherits from Abstract Device class.
// Version: 1.0
// Owner: Mustafa
//-----------------------------------------------------------------------
// Log: 2021-11-01 Created the file,
//-----------------------------------------------------------------------
#include "WaterLeakage.h"
#include "Sensor.h"


/**
 *
 * @param id
 */
WaterLeakage::WaterLeakage(unsigned int id) : Sensor(id) {

}



/**
 *
 * @return
 */
Response WaterLeakage::handleWaterLeakage(){


}

/**
 *
 */
void WaterLeakage::readWaterLeakSensor() {
    if (readDigitalSensor() == 5) {
        handleWaterLeakage();
    }
}



