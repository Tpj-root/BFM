int buzzerPin = 9;  // Pin connected to the active buzzer

void setup() {
  // Nothing to set up
}

void loop() {
  // Stage 1: Normal beep for 10 seconds
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 500);     // 500Hz for 500ms
    delay(1000);                   // Wait for 1 second
  }

  // Stage 2: Fast beep for 10 seconds
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 200);     // 500Hz for 200ms (faster beep)
    delay(800);                    // Wait for 400ms (shorter pause)
  }
  
  // Stage 3: Fast beep for 10 seconds
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 200);     // 500Hz for 200ms (faster beep)
    delay(600);                    // Wait for 400ms (shorter pause)
  }
  
  // Stage 4: Fast beep for 10 seconds
  for (int i = 0; i < 10; i++) {  // Repeat 10 times (1 beep per second)
    tone(buzzerPin, 500, 200);     // 500Hz for 200ms (faster beep)
    delay(400);                    // Wait for 400ms (shorter pause)
  }

  // Pause before the loop restarts or ends (optional)
  delay(2000);  // Wait for 2 seconds before restarting the loop (you can adjust or remove this)
}
