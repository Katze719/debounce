#include <debounce.h>

const int MY_BUTTON_PIN = 40;

Debounce myButton([]() { return !digitalRead(MY_BUTTON_PIN); });

void setup() {
  Serial.begin(115200);
  pinMode(MY_BUTTON_PIN, INPUT_PULLUP);
}

bool myButtonPressed = false;
void loop() {
  if(myButton.read()) {
    if (!myButtonPressed) {
      Serial.println("Button pressed and debounced");
    }
    myButtonPressed = true;
  } else {
    myButtonPressed = false;
  }
}
