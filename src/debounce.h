#pragma once
#include <Arduino.h>

class Debounce {
  private:
    bool (*digitalReadFunction)();
    uint32_t (*millisFunction)();
    uint32_t lastDebounceTime;
    uint16_t debounceDelayMs;
    bool lastStableState;
    bool lastReading;

  public:
    /**
     * Construct a new instance to debounce a button.
     * 
     * @param digitalReadFunction The function for reading the button
     * @param debounceDelayMs The debounce delay in milliseconds
     * @param millisFunction The millis function
     */
    Debounce(
      bool (*digitalReadFunction)(),
      uint16_t debounceDelayMs = 10,
      unsigned long (*millisFunction)() = millis
    );

    /**
     * This function returns the current state of the button.
     * 
     * @return The current state of the button
     */
    bool read();
};
