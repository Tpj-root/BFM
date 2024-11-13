int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Generate random frequencies for alien-like sound
  int freq = random(100, 2000);  // Random frequency between 100Hz and 2000Hz
  
  // Random duration for the sound
  int duration = random(50, 300);  // Random duration between 50ms and 300ms
  
  tone(buzzerPin, freq, duration);  // Play the random tone
  delay(random(50, 300));          // Wait before playing the next tone
}
