#include "LedControl.h"

// Initialize LedControl object for the MAX72XX (pins: DataIn, CLK, LOAD)
LedControl lc = LedControl(8, 10, 9, 1);

// Timing and delay setup
unsigned long delaytime = 100;

// Buzzer pin
int buzzerPin = 11;  // Change this if needed

// Define Yautja digits for the LED display
byte yautjaDigits[10] = {
  B00000000, B11110001, B11111101, B10100101,  // Yautja digits 0-3
  B10111101, B11010111, B10011111, B11010011,  // Yautja digits 4-7
  B11111101, B11111111  // Yautja digits 8-9
};

void setup() {
  // Wake up the MAX72XX and set brightness
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);  // Set brightness to a medium value
  lc.clearDisplay(0);     // Clear display

  pinMode(12, OUTPUT);    // LED indicator pin (for twinkle effect)
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void testSequence() {
  for (int i = 1; i < 10; i++) {
    // Display the Yautja digits on the LED matrix
    lc.setRow(0, 0, yautjaDigits[i]);
    lc.setRow(0, 1, yautjaDigits[i]);
    lc.setRow(0, 2, yautjaDigits[i]);
    lc.setRow(0, 3, yautjaDigits[i]);

    // Generate a tone effect corresponding to the digit
    playTone(i);

    // Twinkle the LED pin to indicate that something changed
    twinkle();
    
    delay(1000);  // Wait 1 second before updating
  }
}

void twinkle() {
  for (int twinkle = 0; twinkle < 6; twinkle++) {
    digitalWrite(12, LOW);
    delay(100);
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
  }
}

void playTone(int digit) {
  // Play a tone depending on the digit
  switch (digit) {
    case 1:
      tone(buzzerPin, 400, 500);  // Beep for 500ms at 400Hz for digit 1
      break;
    case 2:
      tone(buzzerPin, 500, 500);  // Beep for 500ms at 500Hz for digit 2
      break;
    case 3:
      tone(buzzerPin, 600, 500);  // Beep for 500ms at 600Hz for digit 3
      break;
    case 4:
      tone(buzzerPin, 700, 500);  // Beep for 500ms at 700Hz for digit 4
      break;
    case 5:
      tone(buzzerPin, 800, 500);  // Beep for 500ms at 800Hz for digit 5
      break;
    case 6:
      tone(buzzerPin, 900, 500);  // Beep for 500ms at 900Hz for digit 6
      break;
    case 7:
      tone(buzzerPin, 1000, 500); // Beep for 500ms at 1000Hz for digit 7
      break;
    case 8:
      tone(buzzerPin, 1100, 500); // Beep for 500ms at 1100Hz for digit 8
      break;
    case 9:
      tone(buzzerPin, 1200, 500); // Beep for 500ms at 1200Hz for digit 9
      break;
    default:
      tone(buzzerPin, 300, 500);  // Default beep for 300Hz for any other case
      break;
  }
}

void loop() {
  lc.clearDisplay(0);   // Clear the display
  digitalWrite(12, LOW);  // Turn off the LED indicator
  delay(1000);            // Wait 1 second before starting

  testSequence();        // Run the test sequence
  digitalWrite(12, HIGH); // Turn on the LED indicator
  delay(1000);            // Wait 1 second before repeating
}
