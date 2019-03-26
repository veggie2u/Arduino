// Test the 2 purple strands on the robot

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

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

void setup() {
  pixels1.begin(); // This initializes the NeoPixel library.
  pixels1.setBrightness(BRIGHTNESS);

  pixels2.begin(); // This initializes the NeoPixel library.
  pixels2.setBrightness(BRIGHTNESS);
}

void loop() {
  turnOn1();
  turnOff2();
  delay(DELAY);
  turnOff1();
  turnOn2();
  delay(DELAY);
}

void turnOn1() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels1.setPixelColor(i, color4); // purple
    pixels1.show(); // This sends the updated pixel color to the hardware.
  }
}

void turnOff1() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels1.setPixelColor(i, 0);
  }
  pixels1.show();
}

void turnOn2() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels2.setPixelColor(i, color4); // purple    
  }
  pixels2.show(); // This sends the updated pixel color to the hardware.
}

void turnOff2() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels2.setPixelColor(i, 0);
  }
  pixels2.show();
}
