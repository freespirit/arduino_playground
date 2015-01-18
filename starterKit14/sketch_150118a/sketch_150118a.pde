import processing.serial.*;
Serial port;
PImage logo;

int bgColor = 0;

void setup() {
  colorMode(HSB, 255);
  
  logo = loadImage("http://arduino.cc/logo.png");
  size(logo.width, logo.height);
  println("Available serial ports: ");
  println(Serial.list());
  
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  if(port.available() > 0) {
    bgColor = port.read();
    println(bgColor);
  }
  background(bgColor, 255, 255);
  image(logo, 0,0);
}
