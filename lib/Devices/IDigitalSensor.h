#pragma once
#include <functional>

class IDigitalSensor
{
public:
  virtual ~IDigitalSensor() = default;
  virtual void init(int pin) = 0;
  virtual void setCallback(std::function<void(bool)> callback) = 0;
  virtual bool isHigh() = 0;
};