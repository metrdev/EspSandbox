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

void TickTacker::start(int interval_ms)
{
  _ticker.attach_ms(interval_ms, ::execute);
}