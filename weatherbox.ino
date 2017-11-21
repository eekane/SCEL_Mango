/* File: weatherbox.ino */
/* Weatherbox driver */

/* Included Libraries */
#include "config.h"
#include "sensor.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"

/* External Libraries */
#include <SHT1x.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <XBee.h>
#include <EEPROM.h>

/* Global Variables for Packet */
schema_1 Gpacket;

/* Global Xbee object */
XBee Gxbee = Xbee();

/* Global count variable */
int G_count = 0;

void setup() {
  /* Initialization */
  sensor_init();
  Serial.begin(9600);
  Gxbee.begin(Serial);

  /* Initialize Packet */
  clear_Packet();

}

void loop() {
  routine(&G_count);
}
