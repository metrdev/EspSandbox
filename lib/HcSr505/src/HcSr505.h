#pragma once

#include "IDigitalSensor.h"
#include <functional>
#include <atomic>
#include <Arduino.h>

class HcSr505 : public IDigitalSensor {
public:
  HcSr505();
  void init(int pin) override;
  void setCallback(std::function<void(bool)> callback) override;
  bool isHigh() override;
  void service();

private:
  int _pin = -1;
  std::function<void(bool)> _callback;
  std::atomic<bool> _pending{false};

  static void IRAM_ATTR isrStatic();
  static HcSr505* instance;
};
