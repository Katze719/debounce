#include <Arduino.h>
#include "./debounce.h"

Debounce::Debounce(
  bool (*digitalReadFunction)(),
  uint16_t debounceDelayMs
) :
  digitalReadFunction(digitalReadFunction),
  debounceDelayMs(debounceDelayMs),
  lastDebounceTime(0)
{};

bool Debounce::read() {
  static bool lastStableState = LOW;
  static bool lastReading = LOW;

  bool currentReading = digitalReadFunction();

  if (currentReading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) >= debounceDelayMs) {
    if (currentReading != lastStableState) {
      lastStableState = currentReading;
    }
  }

  lastReading = currentReading;
  return lastStableState;
}
