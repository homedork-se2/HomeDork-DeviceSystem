
//#include "Thread.h"
//#include "ThreadController.h"
//
//#include "Alarm.h"
//#include "Curtain.h"
//#include "ElectricityConsumption.h"
//#include "Fan.h"
#include "Light.h"
//#include "PowerCutOff.h"
//#include "Radiator.h"
//#include "Sound.h"
//#include "Sensor.h"
//#include "Stove.h"
//#include "Thermometer.h"
//#include "Timer.h"
//#include "WaterLeakage.h"
//
//#include "AlarmController.h"
//#include "DeviceController.h"
//#include "TemperatureController.h"
//#include "SensorController.h"
//
//
////Other Variables
unsigned int muxPins[4] = {12, 13, 11, 8};
//
////Instantiated Models
//Curtain* curtain1{28};
//Curtain* curtain2{29};
//ElectricityConsumption electricityConsumption{A0};
//Fan fanLoft{10, false};
//Fan fan{};
Light indoorLight{11, muxPins, false};
//Light outdoorLight{20, muxPins, false};
//Light alarmLight{22, muxPins, false};
//PowerCutOff powerCutOff{7};
//Radiator radiator{25, muxPins};
//Radiator radiatorWindow{23, muxPins}
//Response response;
//Sound siren{21, muxPins};
//Sensor switchSecuritySensor{3};
//Sensor switchFireSensor{2};
//Sensor lightSensor{A3};
//Stove stove{5};
//Thermometer thermometerIn{A1};
//Thermometer thermometerInWindow{A2};
//Thermometer thermometerOut{9};
//Timer timer1{18, muxPins};
//Timer tiemr2{19, muxPins};
//WaterLeakage waterLeakage{4};
//Window window{6};
//Window fakeWindow{27};
//
////Composition Models
//Alarm* securityAlarm{alarmLight, siren, switchSecuritySensor};
//Alarm* fireAlarm{alarmLight, siren, switchFireSensor};
//TwilightSystem twilightSystem{outdoorLight, Sensor};
//
////Models lists
//Alarm alarms[2];
//Curtain curtains[2];
//Fan fans[2];
//Light lights[3] = {indoorLight, outdoorLight, alarmLight};
//Radiator radiators[2] = {radiator, radiatorWindow};
//Thermometer thermometersIn[2] = {thermometerIn, thermometerInWindow};
//Window windows[2] = {window, fakeWindow};
//
////Controllers
//AlarmController alarmController;
//DeviceController deviceController;
//SensorController sensorController;
//TemperatureController temperatureController;
//ThreadController threadController = ThreadController();
//
////Threads
//Thread* alarmFireControllerThread = new Thread()
//Thread* alarmSecurityControllerThread = new Thread();
//Thread* deviceControllerThread = new Thread();
//Thread* sensorControllerThread = new Thread();
//Thread* temperatureControllerThread = new Thread();
//

void setup() {
    Serial.begin(9600);
    
//    setPinModes();
//    //Get Database States
//    //Setup Threads
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }
   
   
 
}

void loop() {
//    threadController.run();
const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];
if (Serial.available() > 0) {
    int len = Serial.readBytes(buf, BUFFER_SIZE);
    char stringID[2] = {buf[2], buf[3]};
    
    unsigned int id = atoi(stringID);
    if ( id == indoorLight.getId()) {
      Serial.println("ID:11:ON");
      indoorLight.handleLightSwitch(indoorLight.getId());
    }
}
 
}
//
//void fireAlarmCallback() {
//    Serial.println("Starting Fire Alarm System...");
//    Serial.println(millis());
//    // Run the loop for the fire alarm to check its sensor and return a response from the alarm has been triggered.
//    response = alarmController.runFireAlarm();
//    //if we get a response we need to send it to the serve so they can update database and inform end user
//
//    //Client
//    // We need to connect to the server send the response and/or information concerning the alarm
//}
//
//void securityAlarmCallback() {
//    Serial.println("Starting Security Alarm System...")
//    Serial.println(millis());
//    // Run the loop for the fire alarm to check its sensor and return a response from the alarm has been triggered.
//    response = alarmController.runSecurityAlarm();
//    //if we get a response we need to send it to the serve so they can update database and inform end user
//
//    //Client
//    // We need to connect to the server send the response and/or information concerning the alarm
//
//
//}
//
//void deviceControllerCallback() {
//    Serial.println("Starting Device Control System...");
//    Serial.println(millis());
//    //Server should should start listening and wait for a client to connect once the client Connects we will
//    // wait for a command from the user and implement
//    //Server
//   
//    //response = deviceController.runDeiviceControl(message);
//    if (Serial.available() > 0) {
//      inByte = Serial.read();
//    }
//}
//
//void sensorControllerCallback() {
//    Serial.println("Starting Security Alarm System...")
//    Serial.println(millis());
//    // Run the loop for the sencor controller to check its sensor and return a response from the alarm has been triggered.
//    response = alarmController.runSensorControl();
//    //if we get a response we need to send it to the serve so they can update database and inform end user
//
//    //Client
//    // We need to connect to the server send the response and/or information concerning the alarm
//    Serial.write(response.getMessage());
//}
//
//void temperatureControllerCallback() {
//    Serial.println("Starting Security Alarm System...")
//    Serial.println(millis());
//    // Run the loop for the temperature controller to check its sensor and return a response if and only if they want updates.
//    response = temperatureController.runTemperatureControl();
//    //Not sure if they want us to update the database on a regular schedule like every 5 minutes or receive a command for
//    //getting the currentTemp but if they want us to send we need to use the client
//    //Client
//    // We need to connect to the server send the response and/or temperature
//
//}
//
//void setPinModes()
//    pinMode(2, INPUT);
//    pinMode(3, INPUT);
//    pinMode(4, INPUT);
//    pinMode(5, INPUT);
//    pinMode(6, INPUT);
//    pinMode(7, INPUT);
//    pinMode(9, INPUT);
//    pinMode(10, OUTPUT);
//    pinMode(muxPins[0], OUTPUT);
//    pinMode(muxPins[1], OUTPUT);
//    pinMode(muxPins[2], OUTPUT);
//    pinMode(muxPins[3], OUTPUT);
//
//}

//void establishContact() {
//  
//}
