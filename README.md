*********************OPEN SOURCE WEATHER STATION - OSWS - *********************

                      Documentation and main concept


1. Description and purpose


The Open Source Weather Station (OSWS) is tentative to promote Open Source Software and Hardware 
and education on Weather Monitoring and data gathering from various sensors while containing 
the cost of the OSWS on a limited budget.

The OSWS is based on HW as Arduino UNO, Attiny85 and SW as the 
Arduino IDE, Python. 
The HW of the sensors is the only part that has been purchased as in the case of the:

1. LM 35 Linear Temperature sensor
2. DHT 11 Humidity and Temperature sensor
3. BMP180 Pressure and Temperature sensor
4. LDR and IR diodes etc for light detection


2. The OSWS Features:

Version 1.0

1. Thermometer: Temperature measurement
2. Hygrometer: Humidity measurement
3. Barometer: Atmospheric pressure measurement
4. Lux-meter: Measurement of light 


2. Who can build and use

OSWS is easy to implement from everyone with intermediate knowledge on electronics.
The number of persons can speed up the process and knowledge on using Arduino IDE 
and programming Attiny85 with Arduino as ISP is a must. HW building is a limiting factor in this
project as the housing of the sensors and some of the sensors is completely DIY.


3. HOW TO BUILD

This system is a simple sensor integration platform. All data is gathered on an Arduino UNO as a I2C Master.
All other sensors are either directly integrated on the Arduino UNO or hooked up on the I2C bus as slaves. 
Detailed instructions are uploaded on the GitHub repo.

