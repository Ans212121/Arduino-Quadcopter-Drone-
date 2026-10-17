#pragma once
#include <Arduino.h>
#include <stdint.h>

// Serial formatting for six raw sensor-axis values.
// Caller must supply REAL sensor readings from a verified hardware driver.
// Does not initialize/read a sensor or invent physical units/calibration.
inline void printSensorAxes(int16_t acX, int16_t acY, int16_t acZ,
                            int16_t gyX, int16_t gyY, int16_t gyZ) {
  Serial.print(F("AcX: ")); Serial.print(acX);
  Serial.print(F(" | AcY: ")); Serial.print(acY);
  Serial.print(F(" | AcZ: ")); Serial.print(acZ);
  Serial.print(F(" | GyX: ")); Serial.print(gyX);
  Serial.print(F(" | GyY: ")); Serial.print(gyY);
  Serial.print(F(" | GyZ: ")); Serial.println(gyZ);
}
