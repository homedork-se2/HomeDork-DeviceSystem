
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
WaterLeakage waterLeakage{4};
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
DeviceController deviceController{alarmController, securityAlarm, curtains, fans, lights, response, sensorController,
                                  stove, temperatureController, timers, twilightSystem, windows};


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

//    //Get Database States

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    delay(500);

}

void loop() {
    if (Serial.available() > 0) {
        Request request;

    }
    deviceController.runListen();
}
