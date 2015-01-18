#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(4,2);

const int treshold = 500;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensorValue = sensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  
  if(sensorValue > treshold)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
    
  delay(10);
  
}
