#include "Alarm.h"
#include "Curtain.h"
#include "

#include "DeviceController.h"
#include "TemperatureController.h"
#include "AlarmController.h"

//Other Variables
unsigned int muxPins[4] = {12, 13, 11, 8};

//Instantiated Models
Alarm securityAlarm{alarmLight, siren, switchSecuritySensor};
Alarm fireAlarm{alarmLight, siren, switchFireSensor};
Curtain curtain1{28};
Curtain curtain2{29};
ElectricityConsumption electricityConsumption{A0};
Fan fanLoft{10, false};
Light indoorLight{11, muxPins, false};
Light outdoorLight{20, muxPins, false};
Light alarmLight{22, muxPins, false};
Radiator radiator{25, muxPins};
Radiator radiatorWindow{23, muxPins};
Sound siren{21, muxPins};
Sensor switchSecuritySensor{3};
Sensor switchFireSensor{2};
Sensor lightSensor{A3};
Stove stove{5};
Thermometer thermometerIn{A1};
Thermometer thermometerInWindow{A2};
Thermometer thermometerOut{9};
Timer timer1{18, muxPins};
Timer tiemr2{19, muxPins};
PowerCutOff powerCutOff{7};
WaterLeakage waterLeakage{4};

//Models lists
Light lights[3] = {indoorLight, outdoorLight, alarmLight};
Thermometer thermometersIn[thermometerIn, thermometerInWondow];
TwilightSystem twilightSystem{outdoorLight, Sensor};
Thermometer thermometerOut;
Fan fans[2];
Curtain curtains[2];
Window windows[2];
Alarm alarms[2];

//Controllers
SensorController sensorController;
DeviceController deviceController;
TemperatureController temperatureController;
AlarmController alarmController;


void setup() {
    Serial.begin(9600);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(8, OUTPUT);
    // put your setup code here, to run once:
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);

    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(8, HIGH);

    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(8, LOW);

    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(8, HIGH);

    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(8, LOW);

    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, HIGH);

    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);

    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);

}

void loop() {

}
