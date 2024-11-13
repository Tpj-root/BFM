int buzzerPin = 9;  // Pin connected to the active buzzer

// Frequency range for bomb tone effect (in Hz)
int startFreq = 200;   // Starting frequency (low pitch)
int endFreq = 1000;    // Ending frequency (high pitch)
int step = 50;         // Frequency step for increasing/decreasing the pitch
int duration = 50;     // Duration for each frequency step

void setup() {
  // Nothing to set up
}

void loop() {
  // Rising pitch (increasing frequency)
  for (int freq = startFreq; freq <= endFreq; freq += step) {
    tone(buzzerPin, freq);    // Play the tone
    delay(duration);          // Wait before changing frequency
  }

  delay(200);  // Pause after rising pitch
  
  // Falling pitch (decreasing frequency)
  for (int freq = endFreq; freq >= startFreq; freq -= step) {
    tone(buzzerPin, freq);    // Play the tone
    delay(duration);          // Wait before changing frequency
  }

  delay(500);  // Pause before repeating the tone
}
