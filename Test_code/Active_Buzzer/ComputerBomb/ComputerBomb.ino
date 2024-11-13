int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Rising alarm: increasing frequency and speed
  for (int i = 500; i <= 2000; i += 100) { // Frequency increases from 500Hz to 2000Hz
    tone(buzzerPin, i, 200);  // Play the tone for 200ms
    delay(100);                // Shorter delay as we go faster
  }

  // Explosion sound: loud, sudden tone to simulate bomb explosion
  tone(buzzerPin, 5000, 500);  // High-frequency loud tone (5000Hz) for 500ms
  delay(500);                  // Short delay for dramatic effect

  // Pause before repeating the alarm or explosion (optional)
  delay(2000);  // Pause to give a break before starting again
}
