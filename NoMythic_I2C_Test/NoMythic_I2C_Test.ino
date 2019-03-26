// This test the communication from RoboRio over I2C.
// This is the recieve code.
// Check the DEVICE_NO matches on the RoboRio
// This is only expecting the commands 1 and 2

#include <Wire.h>

//The I2C device number. Must use same number in sender
const byte DEVICE_NO = 4;
// Status pin - a led - onboard is 13 - pulses for each command
const byte STATUS_PIN = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("I2C NoMythic Recieve");
  pinMode(13, OUTPUT);
  digitalWrite(STATUS_PIN, HIGH);
  delay(500);
  digitalWrite(STATUS_PIN, LOW);
  // put your setup code here, to run once:
  Wire.begin(DEVICE_NO);
  // when an I2C event happens, process it
  Wire.onReceive(handleEvent);
  Serial.println("Ready");
}

// every time we hear an I2C event for our device, handle it here
void handleEvent(int howMany) {
 while(Wire.available()) {
   byte command = Wire.read();
   Serial.print("Command: ");
   Serial.println(command);
   // we have predefined commands that both send and receive understand
   switch(command) {
     case 1:
       turnOff();
       break;
     case 2:
       turnOn();
       break;
   }
 }
}

void turnOn() {
 digitalWrite(STATUS_PIN, HIGH);
 Serial.println("Turn ON");
}

void turnOff() {
 digitalWrite(STATUS_PIN, LOW);
 Serial.println("Turn OFF");
}
void loop() {
 delay(100);
}
