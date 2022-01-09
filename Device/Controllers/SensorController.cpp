//-----------------------------------------------------------------------
// File: SensorController.cpp
// Summary: Monitors the sensors of the devices and sends a request to
// the server when a devices state has changed.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-23 Created the file,
//-----------------------------------------------------------------------

#include "SensorController.h"

/**
 * The sensor controller constructor.
 * @param electricityConsumption (ElectricityConsumption): The input device which handles
 * the reading of the electricity consumption within the smart home.
 * @param powerCutOff (PowerCutOff): The power cut off input device that will
 * read a power failure.
 * @param stove (Stove): Represents the stove within the smart home an input device.
 * @param twilightAutomaticSystem (TwilightAutomaticSystem): The twilight automatic system
 * class reads the light sensor and turns on the light accordingly.
 * @param waterLeakage (WaterLeakage): The water leakage sensor handles the reading for a
 * water leak.
 * @param windows (Window[]): The window in the smart house.
 */
SensorController::SensorController(ElectricityConsumption electricityConsumption, PowerCutOff powerCutOff,
                                   Stove stove, TwilightAutomaticSystem twilightAutomaticSystem,
                                   WaterLeakage waterLeakage, Window * windows)
        : _electricityConsumption(electricityConsumption), _powerCutOff(powerCutOff), _stove(stove),
          _twilightAutomaticSystem(twilightAutomaticSystem), _waterLeakage(waterLeakage), _windows(windows) {
}



/**
 * The function runs the sensor controller loop reading the input devices.
 * @return (Response): It returns a response if a failure occur so it can be
 * logged on the server.
 */
void SensorController::runSensorController() {
    int size = 2;
    for (int i = 0; i < size; ++i) {
        if (!shouldRun()) {
            return;
        }
        noInterrupts();
        _windows[i].readSensor();
        interrupts();
    }
    if (timeCounter == 0 || timeCounter >= millis()) {
        if (!shouldRun()) {
            return;
        }
        noInterrupts();
        _electricityConsumption.readSensor();
        timeCounter = millis() + 2000;
        interrupts();
    }
    if (!shouldRun()) {
        return;
    }
    noInterrupts();
    _powerCutOff.readSensor();
    delay(50);
    interrupts();
    if (!shouldRun()) {
        return;
    }
    noInterrupts();
    _stove.readStoveSensor();
    delay(50);
    interrupts();
    if (!shouldRun()) {
        return;
    }
    noInterrupts();
    _twilightAutomaticSystem.readLightSensor();
    delay(50);
    interrupts();
    if (!shouldRun()) {
        return;
    }
    noInterrupts();
    _waterLeakage.readWaterLeakSensor();
    delay(50);
    interrupts();

}

bool SensorController::shouldRun() {
    if (Serial.available() > 0) {
        return false;
    }
    return true;
}
