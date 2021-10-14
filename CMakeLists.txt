cmake_minimum_required(VERSION 3.20)
project(HomeDork_DeviceSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(arduinomain)

add_executable(HomeDork_DeviceSystem
        arduinomain/arduinomain.ino
        arduinomain/Device.cpp arduinomain/Device.h arduinomain/Response.cpp arduinomain/Response.h arduinomain/Light.cpp arduinomain/Light.h)
