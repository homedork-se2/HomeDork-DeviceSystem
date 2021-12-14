//-----------------------------------------------------------------------
// File: Window.h
// Summary: A class that represents a Window in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Ibrahim
//-----------------------------------------------------------------------
// Log: 2021-10-28 Created the file,
//-----------------------------------------------------------------------

#ifndef HOMEDORK_DEVICESYSTEM_WINDOW_H
#define HOMEDORK_DEVICESYSTEM_WINDOW_H

#include <Arduino.h>
#include <Response.h>
#include <Sensor.h>

class Window: public Sensor {
public:
    Window(unsigned int id);
    void readSensor();
    void handleWindowSwitch(bool state);

};

#endif //HOMEDORK_DEVICESYSTEM_WINDOW_H
