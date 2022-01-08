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
SensorController::SensorController( ElectricityConsumption electricityConsumption, PowerCutOff powerCutOff,
                                   Stove stove, TwilightAutomaticSystem twilightAutomaticSystem,
                                   WaterLeakage waterLeakage, Window * windows)
        : _electricityConsumption(electricityConsumption), _powerCutOff(powerCutOff), _stove(stove),
          _twilightAutomaticSystem(twilightAutomaticSystem), _waterLeakage(waterLeakage), _windows(windows) {
    _twilightAutomaticSystem.setActive(true);
}



/**
 * The function runs the sensor controller loop reading the input devices.
 * @return (Response): It returns a response if a failure occur so it can be
 * logged on the server.
 */
void SensorController::runSensorController() {

    int size = 2;
    for (int i = 0; i < size; ++i) {
        if (SensorController::shouldRun()) {
            _windows[i].readSensor();
        }
    }
    if (SensorController::shouldRun() && (timeCounter == 0 || timeCounter < millis())) {

        _electricityConsumption.readSensor();

        timeCounter = millis() + 1000;
    }
    if (SensorController::shouldRun()) {
        _powerCutOff.readSensor();
    }

<<<<<<< HEAD
    if (SensorController::shouldRun()) {
        _stove.readStoveSensor();
    }
=======
    _powerCutOff.readSensor();
    _stove.readStoveSensor();
    _twilightAutomaticSystem.readLightSensor();
    _waterLeakage.readWaterLeakSensor();
>>>>>>> 40d52950655ecf9ddec15aa4122625812e38c356

    if (SensorController::shouldRun()) {
        _twilightAutomaticSystem.readLightSensor();
    }

    if (SensorController::shouldRun()) {
        _waterLeakage.readWaterLeakSensor();
    }
}

bool shouldRun() {
    if (Serial.available() > 0) {
        return false;
    }
    return true;
}
