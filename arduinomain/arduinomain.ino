#include "Response.h"
#include "Light.h"
#include "Device.h"


Light light1{1, false};

Light light2{2, false};
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
  // put your main code here, to run repeatedly:
  light1.handleLightSwitch(light1.getId());
    delay(5000);
    
    light2.handleLightSwitch(light2.getId());
    delay(5000);
  
}
