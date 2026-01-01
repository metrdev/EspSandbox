#include <Arduino.h>
#include "TickTacker.h"
#include "HcSr505.h"
#include "IDigitalSensor.h"

const int MOTION_SENSOR_PIN = 14;
IDigitalSensor *motionSensor;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(10);
  }
  Serial.println("Serial started at 115200");

  motionSensor = new HcSr505();
  motionSensor->init(MOTION_SENSOR_PIN);
  motionSensor->setCallback([](bool state)
                      { Serial.println(state ? "Motion detected" : "No motion"); });
}

void loop()
{
  static_cast<HcSr505 *>(motionSensor)->service();
}