int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Gradual tone change for a peaceful sound effect
  for (int freq = 300; freq <= 600; freq++) {   // Gradually increase frequency from 300Hz to 600Hz
    tone(buzzerPin, freq, 10);  // Play tone for 10ms
    delay(10);                  // Short delay for smooth transition
  }

  delay(500);  // Pause for a moment

  // Gradual decrease in frequency for peaceful descent
  for (int freq = 600; freq >= 300; freq--) {   // Gradually decrease frequency from 600Hz to 300Hz
    tone(buzzerPin, freq, 10);  // Play tone for 10ms
    delay(10);                  // Short delay for smooth transition
  }

  delay(500);  // Pause before repeating
}
