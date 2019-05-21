# I2C Test

## What is this?
This was created as a way to test i2c communication recieving on an Arduino or compatible device. You can use this code as a way to understand how the Wire library works.

The specifific use case was to send commands from our robot over i2c to an Arduino. To make this easy, the commands are just numbers, such as 1 and 2. This code when it recieves an i2c command will do:

1. Console log the command (1 byte)
2. Check if it is '1' or '2'
3. If it is, console log a message.
4. Turn on or off the internal led as a status indicator
