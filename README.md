Control WS2812b LED strip with Arduino over serial port.

You can change the colour (RGB - values) and control the brightness 

## **How to wire the arduino and LED strip:**

-Connect Din from the LED strip to Pin 5 on Arduino

-Power the LEDs from Arduino with 5V and ground the LED strip with Arduino

## **How to change colour and brightness:**

-Open a serial terminal program, like Putty, Realterm or Moserial.

-Establish a connection between Arduino and computer

-If you want to change the colour, send a string Rxxxyyyzzz, x - R value, y - G value and z - B value

-Example R230047169, R - 230, G - 047, B - 169

-For the brightness you need to send a string Bxxx, x - brightness value (0-255)



### **You can also turn on and off the LED strip if you send O to the Arduino**
