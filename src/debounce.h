/**
 * This class is used to debounces a button.
 */
class Debounce {
  private:
    bool (*digitalReadFunction)();
    uint16_t debounceDelayMs;
    unsigned long lastDebounceTime;

  public:
    /**
     * Construct a new instance to debounce a button.
     * 
     * @param digitalReadFunction The function to read the button
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
