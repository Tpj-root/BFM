int buzzerPin = 9;  // Pin connected to the active buzzer

// Emergency tone frequencies (in Hz)
int toneHigh = 1000;  // High frequency beep (1kHz)
int toneLow = 500;    // Low frequency beep (500Hz)

int beepDuration = 200;  // Duration of each beep in milliseconds
int pauseDuration = 200; // Pause between beeps

void setup() {
  // Nothing to set up
}

void loop() {
  // Beep - High Frequency
  tone(buzzerPin, toneHigh, beepDuration);  // Play high beep
  delay(beepDuration + pauseDuration);      // Wait after high beep
  
  // Beep - Low Frequency
  tone(buzzerPin, toneLow, beepDuration);   // Play low beep
  delay(beepDuration + pauseDuration);      // Wait after low beep
  
  // Repeat the pattern
  delay(500);  // Pause between complete cycles
}
