
#include "Thread.h"
#include "ThreadController.h"

#include "Alarm.h"
#include "Curtains.h"
#include "ElectricityConsumption.h"
#include "Fan.h"
#include "Light.h"
#include "PowerCutOff.h"
#include "Radiator.h"
#include "Response.h"
#include "Sound.h"
#include "Sensor.h"
#include "Stove.h"
#include "Thermometer.h"
#include "Timer.h"
#include "TwilightAutomaticSystem.h"
#include "WaterLeakage.h"
#include "Window.h"

#include "AlarmController.h"
#include "DeviceController.h"
#include "TemperatureController.h"
#include "SensorController.h"


//Multiplexor Pins
unsigned int * muxPins = new unsigned int[4]{12, 13, 11, 8};
int i = 0;

//Declare and instantiate Models
Curtains curtain1{28};
Curtains curtain2{29};
ElectricityConsumption electricityConsumption{A0};
Fan fanLoft{10, false, true};
Fan fanFake{38,false, true};
Light indoorLight{11, muxPins};
Light outdoorLight{20, muxPins};
Light alarmLight{22, muxPins};
PowerCutOff powerCutOff{7};
Radiator radiator{25, muxPins};
Radiator radiatorWindow{23, muxPins};
Response response{500, "Failed"};
Sound siren{21, muxPins};
Sensor switchSecuritySensor{3};
Sensor switchFireSensor{2};
Sensor lightSensor{A3};
Stove stove{5};
Thermometer thermometerIn{A1};
Thermometer thermometerInWindow{A2};
Thermometer thermometerOut{9};
Timer timer1{18, muxPins};
Timer timer2{19, muxPins};
WaterLeakage waterLeakage{7};
Window window{6};
Window fakeWindow{27};

//Declare and instantiate Composition Models
Alarm securityAlarm(alarmLight, siren, switchSecuritySensor);
Alarm fireAlarm{alarmLight, siren, switchFireSensor};

TwilightAutomaticSystem twilightSystem{lightSensor, outdoorLight};


//Create Model lists
Curtains * curtains = new Curtains[2]{curtain1, curtain2};
Fan * fans = new Fan[2]{fanLoft, fanFake};
Light * lights = new Light[3]{indoorLight, outdoorLight, alarmLight};
Radiator * radiators = new Radiator[2]{radiator, radiatorWindow};
Thermometer * thermometersIn = new Thermometer[2]{thermometerIn, thermometerInWindow};
Timer * timers = new Timer[2]{timer1, timer2};
Window * windows = new Window[2]{window, fakeWindow};

//Declare and instantiate Controllers
AlarmController alarmController{fireAlarm, securityAlarm};
SensorController sensorController{electricityConsumption, powerCutOff, stove, twilightSystem, waterLeakage, windows};
TemperatureController temperatureController{thermometersIn, radiators, thermometerOut};
DeviceController deviceController{securityAlarm, curtains, fans, lights, response,  stove, temperatureController,
                                  timers, twilightSystem, windows};

ThreadController threadController = ThreadController();
//Create Thread pool
Thread alarmControllerThread = Thread();
Thread deviceControllerThread = Thread();
Thread sensorControllerThread = Thread();
Thread temperatureControllerThread = Thread();


void setup() {
    Serial.begin(9600);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(9, INPUT);
    pinMode(10, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(8, OUTPUT);

    //Connect threads to callbacks
    alarmControllerThread.onRun(alarmCallback);
    alarmControllerThread.setInterval(100);

    deviceControllerThread.onRun(deviceControllerCallback);
    deviceControllerThread.setInterval(100);

    sensorControllerThread.onRun(sensorControllerCallback);
    sensorControllerThread.setInterval(100);

    temperatureControllerThread.onRun(temperatureControllerCallback);
    temperatureControllerThread.setInterval(100);

    //Add threads to thread Controller
    threadController.add(&alarmControllerThread);
    threadController.add(&deviceControllerThread);
    threadController.add(&sensorControllerThread);
    threadController.add(&temperatureControllerThread);

//    //Get Database States

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    delay(500);

}

void loop() {
    //handles all threads runs those that should run.
//   threadController.run();
    threadController.run();
}

void alarmCallback() {
//    Serial.println("Starting Fire Alarm System...");
//    Serial.println(millis());
    // Run the loop for the fire alarm to check its sensor and return a response from the alarm has been triggered.
    alarmController.runAlarm();
}



void deviceControllerCallback() {
//    Serial.println("Starting Device Control System...");
//    Serial.println(millis());
    deviceController.runListen();
}

void sensorControllerCallback() {
//    Serial.println("Starting Security Alarm System...");
//    Serial.println(millis());
    // Run the loop for the sensor controller to check its sensor and return a response from the alarm has been triggered.
    sensorController.runSensorController();

}

void temperatureControllerCallback() {
//    Serial.println("Starting Security Alarm System...");
//    Serial.println(millis());
    // Run  the temperature controller to check its sensor and return a response if and only if they want updates.
    temperatureController.runTempController();
}
