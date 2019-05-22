# I2C Test

## What is this?
This was created as a way to test i2c communication recieving on an Arduino or compatible device. You can use this code as a way to understand how the Wire library works.

## What for?
The specific use case was to send commands from our robot over i2c to an Arduino.

##How does it work?
This code uses the Wire (i2c) library.

This is just a reciever.

The code is using a few pins.
- 4 & 5 are the i2c pins on an Ardunino UNO. Check your board.
- 13 is the built in Arduino UNO status light.

The code initializes both the Wire library in setup. The real magic is in the handleEvent method.

The handleEvent method is called when ever a command is recieved by i2c. The commands are simply numbers. This requires the sender program and this reciever program to jointly decide what these command numbers mean. There are more descriptive ways to do this, but this was done for simplicity. Only one byte needed.

When a command is recieved, a method to log to the console and update a status light on the Arduino.
