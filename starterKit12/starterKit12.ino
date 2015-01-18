#include <Servo.h>
Servo servo;

const int piezo = A0;
const int switchPin = 2;
const int redLed = 5;
const int yellowLed = 4;
const int greenLed = 3;

int knockVal;
int switchVal;

const int quietKnock = 1;
const int loudKnock = 10;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  servo.attach(9);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  
  Serial.begin(9600);
  
  digitalWrite(greenLed, HIGH);
  servo.write(0);
  
  Serial.println("The box is unlocked");
}

void loop() {
  if(!locked) {
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH) {
      locked = true;
      numberOfKnocks = 0;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      servo.write(90);
      Serial.println("The box is locked");
      delay(1000);
    }
  }
  
  if(locked) {
    knockVal = analogRead(piezo);
    
    if(numberOfKnocks < 3 && knockVal > 0) {
      if(checkForKnock(knockVal))
        numberOfKnocks++;
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    
    if(numberOfKnocks>=3) {
      locked = false;
      servo.write(0);
      delay(20);
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      Serial.println("The box is unlocked");      
    }
  }
}

boolean checkForKnock(int value) {
  if(value >= quietKnock && value <= loudKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value: ");
    Serial.println(value);
    return true;
  }  
  else {
    Serial.print("Bad knock value: ");
    Serial.println(value);
    return false;
  }
}
