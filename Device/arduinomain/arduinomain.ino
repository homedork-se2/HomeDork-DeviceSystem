
#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

#include <Alarm.h>
#include <Curtains.h>
#include <Device.h>
#include <ElectricityConsumption.h>
#include <Fan.h>
#include <Light.h>
#include <Mode.h>
#include <PowerCutOff.h>
#include <Radiator.h>
#include <Request.h>
#include <Response.h>
#include <Sensor.h>
#include <Sound.h>
#include <Stove.h>
#include <Thermometer.h>
#include <Timer.h>
#include <TwilightAutomaticSystem.h>
#include <WaterLeakage.h>
#include <Window.h>

#include <AlarmController.h>
#include <DeviceController.h>
#include <SensorController.h>
#include <TemperatureController.h>


//Multiplexor Pins
unsigned int muxPins[4] = {12, 13, 11, 8};

//Declare and instantiate Models
Curtain curtain1{28};
Curtain curtain2{29};
ElectricityConsumption electricityConsumption{A0};
Fan fanLoft{10, false, true};
Fan fanFake{38, false, true};
Light indoorLight{11, &muxPins};
Light outdoorLight{20, &muxPins};
Light alarmLight{22, &muxPins};
PowerCutOff powerCutOff{7};
Radiator radiator{25, &muxPins};
Radiator radiatorWindow{23, &muxPins};
Response response{500, "Failed"};
Sound siren{21, &muxPins};
Sensor switchSecuritySensor{3};
Sensor switchFireSensor{2};
Sensor lightSensor{A3};
Stove stove{5};
Thermometer thermometerIn{A1};
Thermometer thermometerInWindow{A2};
Thermometer thermometerOut{9};
Timer timer1{18, &muxPins};
Timer timer2{19, &muxPins};
WaterLeakage waterLeakage{7};
Window window{6};
Window fakeWindow{27};


//Create Thread pool
Thread alarmControllerThread = new Thread();
Thread deviceControllerThread = new Thread();
Thread sensorControllerThread = new Thread();
Thread temperatureControllerThread = new Thread();


void setup() {
    Serial.begin(9600);

    //Declare and instantiate Composition Models
    Alarm securityAlarm{&alarmLight, &siren, &switchSecuritySensor};
    Alarm fireAlarm{&alarmLight, &siren, &switchFireSensor};

    TwilightAutomaticSystem twilightSystem{&outdoorLight, &lightSensor};


    //Create Model lists
    Curtain curtains[2] = {&curtain1, &curtain2};
    Fan fans[2] = {&fanLoft, &fanFake};
    Light lights[3] = {&indoorLight, &outdoorLight, &alarmLight};
    Radiator radiators[2] = {&radiator, &radiatorWindow};
    Thermometer thermometersIn[2] = {&thermometerIn, &thermometerInWindow};
    Timer timers[2] = {timer1, timer2};
    Window windows[2] = {&window, &fakeWindow};

    //Declare and instantiate Controllers
    AlarmController alarmController{&fireAlarm, &securityAlarm};
    SensorController sensorController{&electricityConsumption, &powerCutOff, &stove, &twilightSystem, &waterLeakage, &windows};
    TemperatureController temperatureController{&fans, &radiators, &thermometersIn, &thermometerOut};
    ThreadController threadController = ThreadController();
    DeviceController deviceController{&securityAlarm, &curtains, &electricityConsumption, &fans, &lights, &powerCutOff,
                                      &response,  &stove & temperatureController, &timers, &twilightSystem, &windows};

    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(9, INPUT);
    pinMode(10, OUTPUT);
    pinMode(&muxPins[0], OUTPUT);
    pinMode(&muxPins[1], OUTPUT);
    pinMode(&muxPins[2], OUTPUT);
    pinMode(&muxPins[3], OUTPUT);

    //Connect threads to callbacks
    alarmControllerThread.onRun(alarmCallback());
    alarmControllerThread.setInterval(100);

    deviceControllerThread.onRun(deviceControllerCallback());
    deviceControllerThread.setInterval(300);

    sensorControllerThread.onRun(sensorControllerCallback());
    sensorControllerThread.setInterval(100);

    temperatureControllerThread.onRun(temperatureControllerCallback());
    temperatureControllerThread.setInterval(1000);

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
  threadController.run();

}

void alarmCallback() {
  //Serial.println("Starting Fire Alarm System...");
  //Serial.println(millis());
  // Run the loop for the fire alarm to check its sensor and return a response from the alarm has been triggered.
  response = alarmController.runSensorControl();
  Serial.write(response.getMessage());
}

void deviceControllerCallback() {
  //    Serial.println("Starting Device Control System...");
  //    Serial.println(millis());
  deviceController.runListen();
}

void sensorControllerCallback() {
  //    Serial.println("Starting Security Alarm System...")
  //    Serial.println(millis());
  // Run the loop for the sensor controller to check its sensor and return a response from the alarm has been triggered.
  response = sensorController.runSensorController();
  Serial.write(response.getMessage());
}

void temperatureControllerCallback() {
  //    Serial.println("Starting Security Alarm System...")
  //    Serial.println(millis());
  // Run  the temperature controller to check its sensor and return a response if and only if they want updates.
  response = temperatureController.runTempController();
  Serial.write(response.getMessage());
}
