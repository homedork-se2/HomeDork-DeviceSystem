cmake_minimum_required(VERSION 3.20)
project(HomeDork_DeviceSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(arduinomain)

add_executable(HomeDork_DeviceSystem
        arduinomain/arduinomain.ino
        Models/Device.cpp Models/Device.h Models/Response.cpp Models/Response.h Models/Light.cpp Models/Light.h Models/Sensor.cpp Models/Sensor.h)
