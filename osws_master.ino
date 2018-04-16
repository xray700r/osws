/*

Code for the OSWS Arduino UNO Master 

These function calls have the purpose of reading the output of the sensors
connected through the I2C bus or directly to the Arduino Uno master.

Author Moisi Xhaferaj, 05/03/2018.
Released into the public domain.

#########I2C Tiny Wire#########

#Arduino TinyWire Slave Library found at:

#https://github.com/rambo/TinyWire


#########Pressure Sensor Bosch Sensortec BMP180#########

#Version of bmp180 sensor driver and library found at:

#https://github.com/BoschSensortec/BMP180_driver


#########Humidity sensor DHT 11#########

#DHT 11 sensor library found at:

#https://github.com/adafruit/DHT-sensor-library


#########Light Sensor on Attiny 85#########

#Attiny photoresistor i2c code found at:

#https://github.com/DzikuVx/attiny_photoresistor_i2c

*/

#include <Wire.h>

#include <LMsensorquery.h>

#include <DHTsensorquery.h>

#include <SFE_BMP180.h>

#include <dht.h>

#include <AT85sensorquery.h>

#include <BMP180sensorquery.h>


#define DHT11_PIN 7

int tempPin = 1;

#define I2C_SLAVE1 0x13 //luminance level 10 bit

//#define I2C_SLAVE2 0x08 //radiated powerlevel

// You will need to create an SFE_BMP180 object, here called "pressure":

SFE_BMP180 pressure;





 
void setup()
{
 Wire.begin(); // join i2c bus (address optional for master)
 Serial.begin(9600); // start serial for output
 Serial.println("REBOOT");

  // Initialize the sensor (it is important to get calibration values stored on the device).

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.

    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }
}
 
void loop()
{


float lm35temp=0;
float dht11temp=0;
float dht11hum=0;
unsigned int luminance=0, irradiatedpower=0, WindSpeed=0, WindDir=0;

float bmp180abspress=0;
float bmp180relpress=0;
float bmp180temp=0;
float bmp180altitude=103; // meters

AT85sensorquery(I2C_SLAVE1, 2000, luminance);

//AT85sensorquery(I2C_SLAVE2, 2000, irradiatedpower);

DHTsensorquery(DHT11_PIN, 3000, dht11hum, dht11temp);

LMsensorquery(tempPin, 3000, lm35temp);

BMP180sensorquery(pressure, 2000, bmp180altitude, bmp180abspress, bmp180relpress, bmp180temp);



String stringOut = "Weather Sensor Outputs:\n";

stringOut = stringOut + "Temperature[LM35]= " + lm35temp + " *C,\n" +"Temperature[DHT11]= "+ dht11temp + " *C,\n" +"Temperature[BMP180]= "+ bmp180temp + " *C,\n" +"Humidity[DHT11]= "+ dht11hum + " %RH,\n" +"Pessure[BMP180]absolute= "+ bmp180abspress + " mbar,\n" +"Pessure[BMP180]relative= "+ bmp180relpress + " mbar,\n" +"Luminance= "+ luminance + " Lux,\n";\n";



Serial.println();
  Serial.print(stringOut);

Serial.println();
 


delay(1000);  // Pause for 1 seconds.


}


