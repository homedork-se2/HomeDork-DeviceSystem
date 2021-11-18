//-----------------------------------------------------------------------
// File: Mode.h
// Summary: Enum class to serve as a mode for the Fan class. LOW, MEDIUM,
// and HIGH
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-26 Created the file.
//-----------------------------------------------------------------------
#ifndef HOMEDORK_DEVICESYSTEM_MODE_H
#define HOMEDORK_DEVICESYSTEM_MODE_H
#include <Arduino.h>

enum class Mode {
    LOW=75,
    MEDIUM=150,
    HIGH=240
};


#endif //HOMEDORK_DEVICESYSTEM_MODE_H
