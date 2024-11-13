int buzzerPin = 9;  // Pin connected to the active buzzer

// Frequency for tick-tock sound
int tickFreq = 1000;  // Frequency of the "tick" sound (1kHz)
int tockFreq = 500;   // Frequency of the "tock" sound (lower tone)

int tickDuration = 100;  // Duration of the "tick" in milliseconds
int tockDuration = 300;  // Duration of the "tock" in milliseconds
int pauseDuration = 100; // Pause between tick and tock

void setup() {
  // Nothing to set up
}

void loop() {
  // Tick sound (high frequency)
  tone(buzzerPin, tickFreq, tickDuration);  // Play "tick"
  delay(tickDuration + pauseDuration);      // Wait before "tock"
  
  // Tock sound (low frequency)
  tone(buzzerPin, tockFreq, tockDuration);  // Play "tock"
  delay(tockDuration + pauseDuration);      // Wait before repeating
  
  // Repeat the tick-tock pattern
}
