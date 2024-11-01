// Define pins for the touch sensors
const int touchSensorPins[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // Pins for the touch sensors
bool isTouched[12] = {false};   // Track the touch state for each sensor

void setup() {
    Serial.begin(9600);  // Start serial communication at 9600 baud
    for (int i = 0; i < 12; i++) {
        pinMode(touchSensorPins[i], INPUT);  // Set each sensor pin as INPUT
    }
}

void loop() {
    for (int i = 0; i < 12; i++) {
        int sensorValue = digitalRead(touchSensorPins[i]);  // Read the sensor value

        // Check if the touch sensor state has changed
        if (sensorValue == HIGH && !isTouched[i]) {
            Serial.print("{\"B");
            Serial.print(i + 1);  // Sensor number (B1, B2, ...)
            Serial.println("\": 1}");  // JSON format for "on" state
            isTouched[i] = true;  // Update touch state

        } else if (sensorValue == LOW && isTouched[i]) {
            // Optional: Only send "off" state if you need it; otherwise, just reset the state without printing
            // Serial.print("{\"B");
            // Serial.print(i + 1);
            // Serial.println("\": 0}");
            isTouched[i] = false;  // Reset touch state without sending "off" message
        }
    }

    delay(100);  // Short delay for stability
}
