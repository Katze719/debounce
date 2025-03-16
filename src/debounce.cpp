#include <Arduino.h>
#include "./debounce.h"

Debounce::Debounce(
  bool (*digitalReadFunction)(),
  uint16_t debounceDelayMs
) :
  digitalReadFunction(digitalReadFunction),
  debounceDelayMs(debounceDelayMs),
  lastDebounceTime(millis()),
  lastStableState(LOW),
  lastReading(LOW)
{};

bool Debounce::read() {
  bool currentReading = this->digitalReadFunction();

  if (currentReading != this->lastReading) {
    this->lastDebounceTime = millis();
  }

  if ((millis() - this->lastDebounceTime) >= this->debounceDelayMs) {
    if (currentReading != this->lastStableState) {
      this->lastStableState = currentReading;
    }
  }

  lastReading = currentReading;
  return this->lastStableState;
}
