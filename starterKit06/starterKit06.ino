int sensorValue=0;
int sensorLow=1023;
int sensorHigh=0;

int ledPin=13;//the built-in led on ArduinoUno

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  while(millis() < 5000) {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    else if( sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}  
