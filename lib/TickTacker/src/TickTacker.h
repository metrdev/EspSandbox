#pragma once

#include <Ticker.h>

class TickTacker {
public:
  TickTacker();

  void start(int interval_ms);

private:
  Ticker _ticker;
};
