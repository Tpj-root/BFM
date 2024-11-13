#include <Wire.h>

const int MPU = 0x68; // I2C address of the MPU-6050

int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // Power management register
  Wire.write(0);     // Set to 0 to wake up the MPU-6050
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // Starting register for accelerometer data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);  // Request 14 registers from the MPU-6050

  // Read accelerometer data
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  
  // Read temperature data (not needed here but provided for completeness)
  int16_t temp = Wire.read() << 8 | Wire.read();

  // Read gyroscope data
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  // Print accelerometer and gyroscope data to the Serial Monitor
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);

  Serial.println("-----------------------------------------");
  
  delay(500); // Wait 500 ms before the next reading
}
