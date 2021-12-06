//-----------------------------------------------------------------------
// File: Timer.cpp
// Summary: A class that represents a Timer system in a smart home this class
// inherits from Abstract Device class.
// Version: 1.0
// Owner: Samuel Mcmurray
//-----------------------------------------------------------------------
// Log: 2021-10-25 Created the file,
//-----------------------------------------------------------------------

#include "Timer.h"

Timer::Timer(unsigned int id, unsigned int  (&muxPins)[4]): Device(id), _muxPins(muxPins) {
}
