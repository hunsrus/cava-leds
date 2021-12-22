---
<img align="left" src="https://github.com/hunsrus/cava-leds/blob/main/cava-led.png" width="156px">

# C.A.V.A control for LEDs
Control LEDs (or any other light source) intensity trough C.A.V.A raw output and Arduino.
# C.A.V.A use
This project uses raw data provided by C.A.V.A (Console-based Audio Visualizer for ALSA). Follow the documentation in the C.A.V.A project [GitHub page](https://github.com/karlstav/cava) to understand and install it.

---
### Set up
You should modify the C.A.V.A [config](https://github.com/karlstav/cava/blob/master/example_files/config) file to your liking (removing the `;` to unncoment), making sure to set the following parameters:
```
data_format = ascii
bit_format = 8bit
method = raw
```
The number of bars should be setted according to the amount of LEDs you have connected to your Arduino, which also depends on the number of analog imputs your Arduino model has. The default number to directly work with the Arduino code provided is 6, since it has been written for the Arduino Uno:
```
bars = 6
```
### How to use
To run the program that sends raw data from C.A.V.A trough the serial port, you should run the following command:
```
cava | cava-raw-output
```
### Arduino
The code in `led-controller.ino` should be loaded in your Arduino. It takes 4-bit brightness data input from the serial port and uses it to set the light intensity trough the analog output pins.
