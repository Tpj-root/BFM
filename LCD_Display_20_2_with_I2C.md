

#  LCD_Display_20_2_with_I2C

[LINK]()


[CODE]()


LCD1602 Parallel LCD Display with Blue Backlight + IIC/I2C Serial Interface Adapter Module






http://robojax.com/learn/arduino/
http://robojax.com/learn/arduino/?vid=robojax-LCD1602-I2C


https://robu.in/product/basic-16x2-character-lcd-white-on-blue-on-blue-5v/
https://robu.in/product/iic-i2c-serial-interface-adapter-module/



https://www.youtube.com/watch?v=q9YC_GVHy5A&ab_channel=Robojax

How it Works





top to bottom

[1][GND]  <------>  [ard_GND]
[2][VCC]  <------>  [ard_5v5]
[3][SDA]  <------>  [ard_A4]
[4][SCL]  <------>  [ard_A5]



Download library


https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library/tree/master








cat > /dev/ttyUSB1


screen /dev/ttyUSB1 9600

# Ensure you have permission to access /dev/ttyUSB1
sudo usermod -aG dialout $USER



**source**

```
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

```
