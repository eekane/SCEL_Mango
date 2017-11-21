/* File: sensors.h
   Header file for Sensor functions
*/

/* Libraries */
#include <SHT1x.h>                  /* Humidity Sensor */
#include <Wire.h>                   /* Pressure and Temperature Senor*/
#include <SPI.h>                    /* Pressure and Temperature Senor*/
#include <Adafruit_Sensor.h>        /* Pressure and Temperature Senor*/ 
#include <Adafruit_BMP280.h>        /* Pressure and Temperature Senor*/

/* Create instances of object */
extern SHT1x sht1x;
extern Adafruit_BMP280 bmp280;

/*Initialization Function */
void sensor_init(void);

/* Sensor Functions */
long sensorPressure(void);
long sensorSolarIrrd(void);
long sensorHumidity(void);         
long sensorRoofTemp(void);             
long sensorBattery(void);
long sensorPanelmV(void);
