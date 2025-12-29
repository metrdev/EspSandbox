#include <Arduino.h>
#include "TickTacker.h"

TickTacker tickTaker;
const uint32_t TICK_MS_INTERVAL = 1000;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(10);
  }
  Serial.println("Serial started at 115200");

  tickTaker.start(TICK_MS_INTERVAL);
}

void loop()
{
}