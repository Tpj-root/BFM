#include <Keypad.h>

// Define the keypad layout
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect the row pins of the keypad to the Arduino
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pinouts of the keypad
// Connect the column pins of the keypad to the Arduino
byte colPins[COLS] = {6, 7, 8, 9}; // Connect to the column pinouts of the keypad

// Create a keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey(); // Get the key pressed

  if (key) { // If a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key); // Print the key to the serial monitor
  }
}

