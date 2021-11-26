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


/**
 *  The constructor of the Waterleakage class a subclass of the Sensor class.
 * @param id (unsigned int): An integer who's value is the id of an instance
 * of a subclass device.
 */
WaterLeakage::WaterLeakage(unsigned int id) : Sensor(id) {

}



/**
 *  The function that handles the change in state of the waterleakage sensor.
 * @return (Response): A response that is sent to the server to handle
 * the state change.
 */
Response WaterLeakage::handleWaterLeakage(){


}

/**
 * The function that handles the reading of the waterleakage sensor.
 */
void WaterLeakage::readWaterLeakSensor() {
    if (readDigitalSensor() == HIGH) {
        handleWaterLeakage();
    }
}



