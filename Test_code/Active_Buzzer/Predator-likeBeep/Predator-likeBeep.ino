int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Beep sound with low frequency like Predator's sound
  tone(buzzerPin, 500, 500);  // 500Hz for 500ms (you can adjust frequency and duration)
  delay(1000);                 // Wait for 1 second before the next beep (adjust timing)
}
