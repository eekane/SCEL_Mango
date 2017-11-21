/*  File: sensors.cpp
    Function definitions for sensors
*/

/* Libraries */
#include "sensor.h"
#include "config.h"

/* Set pins */
SHT1x sht1x(PIN_HUMID_DATA, PIN_HUMID_CLK);   
Adafruit_BMP280 bmp;                       /* Temperature and Pressure object */


/* Initialization */
void sensor_init(void)
{
 bmp.begin();      
}

/* Humidity */
long sensorHumidity(void)
{
    long value = sht1x.readHumidity();
    return value;
}

/* Pressure */
long sensorPressure(void)
{
    long value =  bmp.readPressure();
    return value; 
}

/* Temperature Sensor */
long sensorRoofTemp(void)      
{
    long value = bmp.readTemperature();
    return value;
}

/*Solar Irradiance */
long sensorSolarIrrd(void)
{
  long sensorValue = analogRead(PIN_APOGEE_V) * 5000.0/1023;
  return sensorValue* 0.25;
}





/*Battery */
long sensorBattery(void)
{
    long value = analogRead(PIN_BATT_V)*5000.0/1023;
    return value;
}


/* Solar Panel */
/* Times 2 to account for voltage divider, add 700 to account for voltage drop across diode on charging chip. */ 
long sensorPanelmV(void)
{
    long value = 2*analogRead(PIN_SOLAR_V)*5000.0/1023;
    return value;
}
