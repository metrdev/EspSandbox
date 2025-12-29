#pragma once

#include <Ticker.h>
#include <cstdint>

class TickTacker {
public:
  TickTacker();

  void start(uint32_t interval_ms);

private:
  Ticker ticker;
};
