
#include "HcSr505.h"
#include <Arduino.h>

HcSr505* HcSr505::instance = nullptr;

HcSr505::HcSr505() {}

void HcSr505::init(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
  instance = this;
  attachInterrupt(digitalPinToInterrupt(_pin), isrStatic, CHANGE);
}

void HcSr505::setCallback(std::function<void(bool)> callback) {
  _callback = callback;
}

bool HcSr505::isHigh() {
  return digitalRead(_pin) == HIGH;
}

void HcSr505::service() {
  if (_pending.exchange(false)) {
    if (_callback)
      _callback(isHigh());
  }
}

void IRAM_ATTR HcSr505::isrStatic() {
  if (instance)
    instance->_pending.store(true);
}