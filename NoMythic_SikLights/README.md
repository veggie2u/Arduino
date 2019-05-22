#SikLights

##What is this?

This program recieves commands over i2c and then controls NeoPixels strips based on the commands recieved.

##What for?

Our goal was 2 fold.
1. To provide some interest (sick lights) on the robot
2. To provide some visual feedback to operators

##How does it work?

This code uses 2 libraries, Wire, to communicate over i2c, and Adafruit_NeoPixel to control a strand of led lights.

This is just the reciever.

The code is using a few pins.
- 4 & 5 are the i2c pins on an Ardunino UNO. Check your board.
- 14 & 15 are being used to control the NeoPixels (we had 2 strands)
- 13 is the built in Arduino UNO status light.

The code initializes both the Wire library and the NeoPixels in setup. The real magic is in the handleEvent method.

The handleEvent method is called when ever a command is recieved by i2c. The commands are simply numbers. This requires the sender program and this reciever program to jointly decide what these command numbers mean. There are more descriptive ways to do this, but this was done for simplicity. Only one byte needed.

When a command is recieved, methods to change the colors on the lights are called. There is one call per strand. This is code that should change the state of a strip of lights and end. This system can not be used to run animations.
