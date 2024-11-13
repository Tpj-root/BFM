// Melody for Happy Birthday

int buzzerPin = 9;  // Pin connected to the active buzzer

// Frequency values for the melody (in Hz)
int melody[] = {
  262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 349, 330,
  262, 262, 523, 440, 349, 330, 294, 466, 466, 440, 349, 330, 349, 523, 523, 466, 440, 349
};

int noteDuration = 500;  // Duration of each note (in milliseconds)

void setup() {
  // Nothing to set up
}

void loop() {
  for (int i = 0; i < 32; i++) {
    tone(buzzerPin, melody[i], noteDuration);  // Play the tone
    delay(noteDuration * 1.3);  // Delay between notes (to space them out)
  }
  delay(2000);  // Wait before playing the melody again
}

