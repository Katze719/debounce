#pragma once
#include <Arduino.h>

class Debounce {
  private:
    bool (*digitalReadFunction)();
    uint16_t debounceDelayMs;
    unsigned long (*millisFunction)();
    unsigned long lastDebounceTime;
    bool lastStableState;
    bool lastReading;

  public:
    Debounce(
      bool (*digitalReadFunction)(),
      uint16_t debounceDelayMs = 10,
      unsigned long (*millisFunction)() = millis
    );

    bool read();
};
