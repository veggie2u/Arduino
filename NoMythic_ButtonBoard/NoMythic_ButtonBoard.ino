// Arduino Feather 32u4 Acting as a Joystick HID device
// This will work with Arduino Leonardo
// 16 buttons mapped from button board to joystick buttons

#include <Joystick.h>  // Use MHeironimus's Joystick library

const int numOfButtons = 16;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
  numOfButtons, 0,                  // Button Count, Hat Switch Count
  false, false, false,    // No X, Y, or Z axes
  false, false, false,    // No Rx, Ry, or Rz
  false, false,           // No rudder or throttle
  false, false, false);   // No accelerator, brake, or steering

#include <HID_Buttons.h>  // Must import AFTER Joystick.h

// the pins the buttons are on
int buttonPins[numOfButtons] = {12,11,10,9,6,5,3,2,0,1,14,16,15,23,22,21};

// current state of the buttons
int buttonState[numOfButtons] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() {
  Serial.begin(9600);
  Serial.println("NoMythic Buttons");
  // set all the button pins to inputs True = grounded
  for (int i = 0; i < numOfButtons; i++) {
    Serial.print("Init button ");
    Serial.print(i + 1);
    Serial.print(" on pin ");
    Serial.println(buttonPins[i]);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  Joystick.begin();
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Button board ready.");
}

void loop() {
  // loop over all buttons, and read their state
  for (int i = 0; i < numOfButtons; i++) {
    int pressed = !digitalRead(buttonPins[i]);
    // check if that button changed it's state
    if (pressed != buttonState[i]) {
      buttonState[i] = pressed;
      // send the joystick press or release
      Joystick.setButton(i, pressed);
      Serial.print("Button ");
      Serial.print(i);
      Serial.print(" is ");
      Serial.println(pressed);
    }
  }
  delay(10);
}
