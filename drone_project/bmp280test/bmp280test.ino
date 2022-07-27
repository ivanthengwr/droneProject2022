/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK  (52)
#define BMP_MISO (50) //SDO
#define BMP_MOSI (51) //SDI
#define BMP_CS   (53) //SS

//Adafruit_BMP280 bmp; // I2C
Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

float absAlt;

void setup() { 
  Serial.begin(2000000); 
  Serial.println(F("BMP280 test")); 
 
  if (!bmp.begin()) { 
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!")); 
    while (1); 
  } 
 
  /* Default settings from datasheet. */ 
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */ 
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */ 
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */ 
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */ 
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */ 
} 
 
void loop() { 
    Serial.print(F("Temperature = ")); 
    Serial.print(bmp.readTemperature()); 
    Serial.println(" *C"); 
 
    Serial.print(F("Pressure = ")); 
    Serial.print(bmp.readPressure()/100); //displaying the Pressure in hPa, you can change the unit 
    Serial.println(" hPa"); 
 
    Serial.print(F("Approx altitude = "));
    absAlt = bmp.readAltitude(1003.72); //Change to current pressure that is presently observered on the chosen ground level 
    Serial.print(absAlt); //The "1019.66" is the pressure(hPa) at sea level in day in your region 
    Serial.println(" m");                    //If you don't know it, modify it until you get your current altitude 
 
    Serial.println(); 
    delay(100); 
}
