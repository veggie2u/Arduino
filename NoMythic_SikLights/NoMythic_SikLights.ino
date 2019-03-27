/*******************************************************
 * NoMythic SikLights Neopixels controlled over I2C    *
 * Listen on I2C for light animation commands.         *
 *******************************************************/

#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

/*******************************************************
 * NeoPixel Config                                     *
 *******************************************************/
 
// The pin the NeoPixels are attached to
// These are analog input pins, but are used due to location on the board
#define PIN1       14
#define PIN2       15

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS  120

// How bright are the neo pixels? (0-100)
#define BRIGHTNESS 100

// Delay defines the blink rate in ms
#define DELAY      400

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

// Testing different purples
// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
uint32_t color1 = pixels1.Color(102, 000, 204);
uint32_t color2 = pixels1.Color(161, 000, 255);
uint32_t color3 = pixels1.Color(150, 025, 148);
uint32_t color4 = pixels1.Color(91, 36, 98);

/*******************************************************
 * I2C Config                                          *
 *******************************************************/

//The I2C device number. Must use same number in sender
const byte DEVICE_NO = 4;
// Status pin - a led - onboard is 13 - pulses for each command
const byte STATUS_PIN = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("NoMythic SikLights");
  pinMode(13, OUTPUT);

  // Strand 1
  pixels1.begin(); // This initializes the NeoPixel library.
  pixels1.setBrightness(BRIGHTNESS);

  // Strand 2
  pixels2.begin(); // This initializes the NeoPixel library.
  pixels2.setBrightness(BRIGHTNESS);

  Wire.begin(DEVICE_NO);
  // when an I2C event happens, process it
  Wire.onReceive(handleEvent);
  
  Serial.println("Ready");
}

/*******************************************************
 * Every time we hear an I2C event for our device,     *
 * handle the command here                             *
 *******************************************************/
void handleEvent(int howMany) {
  digitalWrite(STATUS_PIN, HIGH);
  while(Wire.available()) {
    byte command = Wire.read();
    Serial.print("Command: ");
    Serial.println(command);
    // we have predefined commands that both send and receive understand
    switch(command) {
      case 1:
        turnOff1();
        turnOff2();
        break;
      case 2:
        turnOn1();
        turnOn2();
        break;
    }
  }
  digitalWrite(STATUS_PIN, LOW);
}

// Nothing happening right now
void loop() {
  delay(DELAY);
}

// Turn on all lights on strand 1
void turnOn1() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels1.setPixelColor(i, color4); // purple
    pixels1.show(); // This sends the updated pixel color to the hardware.
  }
}

// Turn off all lights on strand 1
void turnOff1() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels1.setPixelColor(i, 0);
  }
  pixels1.show();
}

// Turn on all lights on strand 2
void turnOn2() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels2.setPixelColor(i, color4); // purple
    pixels2.show(); // This sends the updated pixel color to the hardware.
  }
}

// Turn off all lights on strand 2
void turnOff2() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels2.setPixelColor(i, 0);
  }
  pixels2.show();
}
