// Fundamentals of Robot Design
// Anas Ibrahim Al-Mutairi | Abdulaziz Zayed Al-Mutairi
// Reconstructed diagnostic based on a partial photo; NOT recovered original code.
// This sketch ONLY prints commands. It never attaches or drives ESC outputs.
#include <Arduino.h>
#include "throttle_logic.h"

// D2 is a NEW configurable assumption, not a pin recovered from the photo.
// Confirm the receiver pinout and signal voltage before connecting it.
const byte THROTTLE_PIN = 2;
const unsigned long PULSE_TIMEOUT_US = 30000UL;

void setup() {
  pinMode(THROTTLE_PIN, INPUT);
  Serial.begin(115200);
  Serial.println(F("Reconstructed throttle diagnostic; ESC outputs disabled."));
}

void loop() {
  const unsigned long rawThrottle = pulseIn(THROTTLE_PIN, HIGH, PULSE_TIMEOUT_US);
  const uint16_t motorCommandUs = throttleCommand(rawThrottle);
  Serial.print(F("Raw CH3: "));
  Serial.print(rawThrottle);
  Serial.print(F(" | Motor command (not applied): "));
  Serial.print(motorCommandUs);
  Serial.println(rawThrottle >= 900UL && rawThrottle <= 2100UL
                 ? F(" | Input in pictured acceptance range")
                 : F(" | Timeout or invalid input; minimum command"));
  delay(20);
}
