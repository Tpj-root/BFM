/* Arduino Rotary Encoder with Button Tutorial
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 */

#define outputA 6
#define outputB 7
#define buttonPin 8  // Define the pin for the button

int counter = 0;
int aState;
int aLastState;
int buttonState = HIGH;  // Initial button state
int lastButtonState = HIGH;

void setup() {
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Enable internal pull-up resistor for button

  Serial.begin(9600);
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);
}

void loop() {
  // Read the rotary encoder states
  aState = digitalRead(outputA);
  
  // If the previous and the current state of the outputA are different, a pulse has occurred
  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      counter++;
    } else {
      counter--;
    }
    Serial.print("Position: ");
    Serial.println(counter);
  }
  
  aLastState = aState;

  // Read the button state
  buttonState = digitalRead(buttonPin);
  
  // Check if the button was pressed (HIGH to LOW transition)
  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("Button Pressed!");
    counter = 0;  // Reset counter when button is pressed
  }

  lastButtonState = buttonState;  // Update last button state
}

