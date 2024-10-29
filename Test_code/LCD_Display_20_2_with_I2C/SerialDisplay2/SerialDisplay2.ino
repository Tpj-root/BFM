/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    delay(100);  // Wait a bit for the full message to arrive

    char message[20];  // Buffer to hold the message
    int index = 0;

    // Clear the screen
    lcd.clear();

    // Read the entire message into the buffer
    while (Serial.available() > 0 && index < sizeof(message) - 1) {
      message[index++] = Serial.read();
    }
    message[index] = '\0';  // Null-terminate the string

    // Display the full message on the LCD
    lcd.print(message);
  }
}

