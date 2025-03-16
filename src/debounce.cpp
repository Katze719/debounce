#include "./debounce.h"

/**
 * Construct a new instance to debounce a button.
 * 
 * @param digitalReadFunction The function for reading the button
 * @param debounceDelayMs The debounce delay in milliseconds
 * @param millisFunction The millis function
 */
Debounce::Debounce(
  bool (*digitalReadFunction)(),
  uint16_t debounceDelayMs,
  unsigned long (*millisFunction)()
) :
  digitalReadFunction(digitalReadFunction),
  debounceDelayMs(debounceDelayMs),
  millisFunction(millisFunction),
  lastDebounceTime(millis()),
  lastStableState(LOW),
  lastReading(LOW)
{};

/**
 * This function returns the current state of the button.
 * 
 * @return The current state of the button
 */
bool Debounce::read() {
  bool currentReading = this->digitalReadFunction();

  if (currentReading != this->lastReading) {
    this->lastDebounceTime = millisFunction();
  }

  if ((millisFunction() - this->lastDebounceTime) >= this->debounceDelayMs) {
    if (currentReading != this->lastStableState) {
      this->lastStableState = currentReading;
    }
  }

  lastReading = currentReading;
  return this->lastStableState;
}
