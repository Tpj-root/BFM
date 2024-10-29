

#  4×4 Matrix Keypad

[LINK](https://osoyoo.com/2017/09/13/arduino-lesson-4x4-matrix-keypad/)


[CODE](https://github.com/osoyoo/Osoyoo-development-kits/tree/master)

https://rydepier.wordpress.com/2015/10/20/4x4-matrix-keyboard-with-arduino/



How it Works



Turn on your multimeter and set it to continuity mode (or resistance mode). 
In continuity mode, the meter will beep when there is a complete circuit, 
While in resistance mode, it will show a low resistance value.


Identify Rows and Columns:



Start by connecting one probe of the multimeter to switch pin and use the other probe to test the other switch pins.

Pins 1-4 are rows.
Pins 5-8 are columns.



top to bottom

[1]  <------>  [ard_pin_9]
[2]  <------>  [ard_pin_8]
[3]  <------>  [ard_pin_7]
[4]  <------>  [ard_pin_6]
[5]  <------>  [ard_pin_2]
[6]  <------>  [ard_pin_3]
[7]  <------>  [ard_pin_4]
[8]  <------>  [ard_pin_5]


**source**

```
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
 
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
 
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
```
