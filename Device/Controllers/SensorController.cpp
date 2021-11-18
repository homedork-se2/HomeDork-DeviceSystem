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

SensorController::SensorController(ElectricityConsumption electricityConsumption, PowerCutOff powerCutOff,
                                   Stove stove, TwilightAutomaticSystem twilightAutomaticSystem,
                                   WaterLeakage waterLeakage, Window windows[])
        : electricityConsumption(electricityConsumption), powerCutOff(powerCutOff), stove(stove),
          twilightAutomaticSystem(twilightAutomaticSystem), waterLeakage(waterLeakage) {


}


Response SensorController::runSensorController() {
    Response response{500, "error in loop"};
    while(true) {
        if (windows->getIsActive()) {
            windows->readDigitalSensor();

        }
        if (electricityConsumption.getIsActive()) {
            electricityConsumption.getElectricUsage();

        }
        if (powerCutOff.getIsActive()) {
            powerCutOff.handlePowerCutOff();
        }
        if (stove.getIsActive()) {
            stove.readDigitalSensor();

        }
        if (twilightAutomaticSystem.getSensorState()) {
            twilightAutomaticSystem.handleTwilightSystem();

        }
        if (waterLeakage.getIsActive()) {
            waterLeakage.handleWaterLeakage();

        }
    }
}
