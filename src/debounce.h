/**
 * This class is used to debounce a button.
 */
class Debounce {
  private:
    bool (*digitalReadFunction)();
    uint16_t debounceDelayMs;
    unsigned long lastDebounceTime;
    bool lastStableState;
    bool lastReading;

  public:
    /**
     * Construct a new instance to debounce a button.
     * 
     * @param digitalReadFunction The pin of the button
     * @param debounceDelayMs The debounce delay in milliseconds
     */
    Debounce(
      bool (*digitalReadFunction)(),
      uint16_t debounceDelayMs = 10
    );

    /**
     * This function returns the current state of the button.
     * 
     * @return The current state of the button
     */
    bool read();
};
