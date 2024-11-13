int buzzerPin = 9;  // Pin connected to the active buzzer

int beepFrequency = 1000;  // Frequency of the beep (1kHz)
int beepDuration = 300;    // Duration of the beep (in milliseconds)

void setup() {
  // Nothing to set up
}

void loop() {
  tone(buzzerPin, beepFrequency, beepDuration);  // Generate the beep
  delay(1000);  // Wait before repeating the beep
}
