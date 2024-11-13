int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Gradually decrease frequency to simulate Predator's sound
  for (int freq = 1500; freq >= 300; freq--) {   // Start from 1500Hz, drop to 300Hz
    tone(buzzerPin, freq, 50);  // Play tone for 50ms
    delay(50);                  // Short delay to create the descending effect
  }

  delay(1000);  // Pause after descending tone

  // Optional: Repeat the sound again
}
