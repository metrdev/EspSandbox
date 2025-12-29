#include "TickTacker.h"

TickTacker::TickTacker()
  : _state(false), _interval(1000)
{
}

void TickTacker::start(uint32_t interval_ms)
{
  _interval = interval_ms;
  _ticker.attach_ms(_interval, TickTacker::_isr, this);
}

void TickTacker::_isr(TickTacker* instance)
{
  if (instance) instance->toggle();
}

void TickTacker::toggle()
{
  _state = !_state;
  Serial.println(_state ? "Tick" : "Tack");
}
