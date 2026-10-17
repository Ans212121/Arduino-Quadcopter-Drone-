// New propeller-free bench example; NOT original firmware or a flight controller.
// Confirm ESC protocol and pulse widths against its manufacturer documentation.
#include <Arduino.h>
#include <Servo.h>

const byte MOTOR_COUNT = 4;
const byte ESC_PINS[MOTOR_COUNT] = {3, 5, 6, 9};
const int MIN_US = 1000;
const int TEST_US = 1100;
const unsigned long STARTUP_MS = 3000;
const unsigned long TEST_MS = 2000;
const unsigned long ARM_TIMEOUT_MS = 10000;

Servo esc[MOTOR_COUNT];
bool armed = false;
bool testing = false;
unsigned long bootAt = 0;
unsigned long armedAt = 0;
unsigned long testAt = 0;

void stopAll() {
  for (byte i = 0; i < MOTOR_COUNT; ++i) {
    esc[i].writeMicroseconds(MIN_US);
  }
  armed = false;
  testing = false;
}

void printHelp() {
  Serial.println(F("PROPELLERS OFF. Bench example only. 115200 baud."));
  Serial.println(F("a=arm one test; 1..4=test channel; s=stop; h=help"));
  Serial.println(F("Stop is minimum pulse, NOT a physical power disconnect."));
}

void setup() {
  // Preload minimum before attaching to avoid the default servo midpoint pulse.
  for (byte i = 0; i < MOTOR_COUNT; ++i) {
    esc[i].writeMicroseconds(MIN_US);
    esc[i].attach(ESC_PINS[i]);
    esc[i].writeMicroseconds(MIN_US);
  }
  stopAll();
  Serial.begin(115200);
  bootAt = millis();
  printHelp();
}

void loop() {
  const unsigned long now = millis();
  if (testing && now - testAt >= TEST_MS) {
    stopAll();
    Serial.println(F("Test ended. Minimum on all channels; disarmed."));
  } else if (armed && !testing && now - armedAt >= ARM_TIMEOUT_MS) {
    stopAll();
    Serial.println(F("Arm session expired."));
  }

  // Handle one byte per loop so timers are checked even with continuous input.
  if (Serial.available() <= 0) return;
  const char command = static_cast<char>(Serial.read());
  if (command == '\r' || command == '\n' || command == ' ' || command == '\t') return;
  if (command == 's') {
    stopAll();
    Serial.println(F("Minimum on all channels; disarmed."));
  } else if (command == 'h') {
    printHelp();
  } else if (command == 'a') {
    stopAll();
    if (now - bootAt < STARTUP_MS) {
      Serial.println(F("Wait at least 3 seconds after startup, then send a again."));
      return;
    }
    armed = true;
    armedAt = now;
    Serial.println(F("One test enabled for 10 seconds. Send 1..4."));
  } else if (command >= '1' && command <= '4') {
    if (!armed || testing) {
      Serial.println(F("Rejected. Wait for test to end, then send a first."));
      return;
    }
    const byte motor = static_cast<byte>(command - '1');
    for (byte i = 0; i < MOTOR_COUNT; ++i) esc[i].writeMicroseconds(MIN_US);
    esc[motor].writeMicroseconds(TEST_US);
    testing = true;
    testAt = now;
    Serial.print(F("Testing channel "));
    Serial.println(motor + 1);
  } else {
    stopAll();
    Serial.println(F("Unknown command; stopped and disarmed."));
  }
}
