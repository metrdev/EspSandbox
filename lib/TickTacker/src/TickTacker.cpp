#include "TickTacker.h"

#include <Arduino.h>

void execute()
{
  static bool state = true;

  Serial.println(state ? "Tick" : "Tack");
  state = !state;
}

TickTacker::TickTacker()
{}

void TickTacker::start(uint32_t interval_ms)
{
  ticker.attach_ms(interval_ms, ::execute);
}