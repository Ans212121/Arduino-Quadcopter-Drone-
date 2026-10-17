# Development evidence

**Course:** Fundamentals of Robot Design  
**Team:** Anas Ibrahim Al-Mutairi · Abdulaziz Zayed Al-Mutairi

This document describes the three project photographs supplied for the team project. Photographs record development stages; they are not substitutes for complete firmware or repeatable test logs.

## Assembly and electronics

The photos show a four-arm frame, four motors, propellers in the assembled views, a central Arduino Uno-format board, jumper wiring, a USB connection, and a FlySky-branded transmitter. Exact transmitter/receiver, ESC, battery, and sensor models are not reliably established.

## Throttle sketch visible in the IDE

The visible loop performs these steps:

1. Reads `rawThrottle = pulseIn(throttlePin, HIGH, 30000)`.
2. Accepts input between 900 and 2100.
3. Constrains an accepted command to 1000–1500 with `constrain(rawThrottle, 1000, 1500)`.
4. Sets the command to 1000 for an out-of-range input.
5. Prints the raw throttle and motor command.
6. Sends the same `motorSpeed` through `writeMicroseconds` to `esc1`, `esc2`, `esc3`, and `esc4`.
7. Waits 20 ms before repeating.

This is a description of the photographed code, not a complete recovered sketch or a recommendation to run all motors together. Receiver wiring, startup behavior, and full declarations are outside the visible excerpt. The same-output pattern alone does not provide attitude control.

The Arduino IDE output reports **3,620 bytes** of program storage and **262 bytes** of global-variable memory, with an Uno selected. This supports historical successful compilation of that sketch; the image does not independently establish upload completion or motor behavior.

## Sensor diagnostics

A separate photograph shows code printing sensor variables and Serial Monitor displaying changing values for:

| Labels | Displayed signal group |
| --- | --- |
| AcX, AcY, AcZ | Acceleration-axis variables |
| GyX, GyY, GyZ | Gyroscope-axis variables |

The visible code includes a 300 ms delay. Exact sampling rate, scaling, calibration, sensor model, and physical units cannot be determined from this excerpt. The data should not be presented as calibrated acceleration, angular rate, or attitude.

## Relationship to repository firmware

The supplied bench-test example was prepared separately and uses manual serial commands to select one channel. Its host syntax check and its limitations are documented in the README. The photographed historical build and sensor stream do not validate this new example.

## Evidence to collect next

Record original source files, component part numbers, wiring diagram, Arduino core/library versions, and repeatable test observations. Sensor calibration, receiver loss behavior, motor rotation, and flight results each require their own documented tests.
