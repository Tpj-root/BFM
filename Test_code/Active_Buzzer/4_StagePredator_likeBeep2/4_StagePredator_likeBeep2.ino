int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Stage 1: Normal beep (10 seconds)
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 200);     // 500Hz for 200ms
    delay(800);                    // Wait for 800ms (longer pause to make a "teesee" effect)
    tone(buzzerPin, 600, 200);     // 600Hz for 200ms (slightly higher pitch for second beep)
    delay(800);                    // Wait for 800ms (same pause)
  }

  // Stage 2: Fast beep (10 seconds)
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 150);     // 500Hz for 150ms
    delay(350);                    // Wait for 350ms
    tone(buzzerPin, 600, 150);     // 600Hz for 150ms
    delay(350);                    // Wait for 350ms
  }

  // Stage 3: Faster beep (10 seconds)
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 100);     // 500Hz for 100ms
    delay(200);                    // Wait for 200ms
    tone(buzzerPin, 600, 100);     // 600Hz for 100ms
    delay(200);                    // Wait for 200ms
  }

  // Stage 4: Fastest beep (10 seconds)
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 50);      // 500Hz for 50ms (fastest beep)
    delay(100);                    // Wait for 100ms
    tone(buzzerPin, 600, 50);      // 600Hz for 50ms
    delay(100);                    // Wait for 100ms
  }

  // Pause before the loop restarts or ends (optional)
  delay(2000);  // Wait for 2 seconds before restarting the loop (you can adjust or remove this)
}
