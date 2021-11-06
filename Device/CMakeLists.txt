cmake_minimum_required(VERSION 3.20)
project(HomeDork_DeviceSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(arduinomain)

add_executable(HomeDork_DeviceSystem
        arduinomain/arduinomain.ino
        Models/Device.cpp Models/Device.h Util/Response.cpp Util/Response.h Models/Light.cpp Models/Light.h Controllers/SensorController.cpp Controllers/SensorController.h Models/Timer.cpp Models/Timer.h Models/Mode.cpp Models/Mode.h Models/PowerCutOff.cpp Models/PowerCutOff.h Models/WaterLeakage.cpp Models/WaterLeakage.h)
