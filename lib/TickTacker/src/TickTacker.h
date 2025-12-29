#pragma once
#include <Arduino.h>
#include <Ticker.h>

class TickTacker {
public:
  TickTacker();
  void start(uint32_t interval_ms);

private:
  static void _isr(TickTacker* instance);
  void toggle();
  Ticker _ticker;
  volatile bool _state;
  uint32_t _interval;
};
