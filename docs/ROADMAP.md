# Development roadmap

These are planned tasks, not implemented capabilities.

- [ ] Identify exact frame, motor, ESC, battery, receiver, and sensor models.
- [ ] Draw and verify an actual wiring diagram and power budget.
- [x] Document historical Arduino IDE compilation output for the photographed throttle sketch.
- [x] Document acceleration/gyroscope variables displayed in Serial Monitor.
- [ ] Compile the separate repository bench example with the Arduino Uno toolchain and record versions/output.
- [ ] Run propeller-free channel tests and record observations.
- [ ] Recover and version the original project firmware if available.
- [ ] Identify the sensor model and validate calibrated readings.
- [ ] Design and validate receiver input and signal-loss behavior.
- [ ] Implement and evaluate attitude estimation and control on an appropriate test rig.
- [ ] Document verified flight-controller motor ordering and rotation directions.
- [ ] Establish a controlled flight-test plan under applicable local requirements.

Before claiming successful flight, add actual test logs or a video and describe conditions and limitations. Do not add invented performance metrics or describe planned autonomous functions as completed.


## Source reconstruction update

The team reports the original sketches were deleted. A new throttle diagnostic now reconstructs the visible pulse-validation logic without driving ESC outputs. A separate helper recreates the sensor print format; it does not read a sensor. Eleven host throttle boundary tests passed, along with host syntax checks for the diagnostic/helper using simplified Arduino interfaces. Original source recovery, actual Uno builds, sensor identification, and hardware validation remain incomplete. See [reconstruction notes](RECONSTRUCTION.ar.md).
