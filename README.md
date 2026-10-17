# Arduino Quadcopter Drone
### Fundamentals of Robot Design

| Team member | الاسم |
| --- | --- |
| Anas Ibrahim Al-Mutairi | أنس إبراهيم المطيري |
| Abdulaziz Zayed Al-Mutairi | عبدالعزيز زايد المطيري |

[العربية](README.ar.md)

![Quadcopter platform](images/quadcopter-overview.jpeg)

## Project overview

An educational quadcopter project covering mechanical assembly, Arduino integration, motor-control signal experiments, and inertial sensor diagnostics. The platform uses a four-arm frame with four motors and centrally mounted electronics.

## Objectives

- Integrate mechanical components, actuators, and an embedded controller.
- Explore ESC pulse commands and receiver throttle signals.
- Observe acceleration and gyroscope data through serial diagnostics.
- Validate individual functions before combining them into a control system.

## Software

| Module | Function |
| --- | --- |
| [ESC bench test](firmware/esc_bench_test/esc_bench_test.ino) | Tests one ESC channel at a time using serial commands |
| [Throttle diagnostic](firmware/throttle_diagnostic/throttle_diagnostic.ino) | Reads a throttle pulse and prints a limited command; does not drive motors |
| [Throttle logic](firmware/throttle_diagnostic/throttle_logic.h) | Accepts 900–2100 us and limits valid commands to 1000–1500 us |
| [Sensor output](firmware/sensor_output/sensor_output.h) | Formats six sensor-axis values supplied by a sensor driver |
| [Logic tests](tests/throttle_logic_test.cpp) | Checks timeout, input boundaries, and command limits |

The throttle diagnostic uses D2 as a configurable input assumption. The ESC bench example uses D3, D5, D6, and D9. Confirm all connections against the actual hardware. The sensor-output helper requires a hardware-specific driver; it does not initialize or acquire sensor data.

## Development results

The project photographs document assembly, compilation output from a throttle sketch, and sensor-axis values displayed in Serial Monitor. The pictured build reports 3,620 bytes of program storage and 262 bytes of global-variable memory. These figures apply to the pictured sketch, not the repository examples.

### Throttle programming

![Throttle code and compilation output](images/throttle-code-build.jpeg)

### Sensor diagnostics

![Acceleration and gyroscope values](images/imu-serial-readings.jpeg)

The pictured values are uncalibrated observations; physical units and sensor scaling are not established.

## Setup and testing

See [hardware connections](docs/HARDWARE.md) and the [bench-test guide](docs/BENCH_TEST.md). Remove all propellers before powered motor testing.

The throttle logic passed 11 boundary cases on a host computer. The diagnostic and sensor helper passed host C++ syntax checks with simplified Arduino interfaces. Actual Arduino Uno builds and hardware validation of the supplied examples remain pending.

Run the logic tests from the repository root:

```bash
g++ -std=c++11 -Wall -Wextra -Werror tests/throttle_logic_test.cpp -o /tmp/drone-throttle-test
/tmp/drone-throttle-test
```

## Current scope

This repository provides component-level diagnostics. It does not implement sensor acquisition, attitude estimation, PID stabilization, or flight-control motor mixing. Stable flight has not been verified.

## References

- [Arduino Uno](https://docs.arduino.cc/hardware/uno-rev3/)
- [Servo library](https://github.com/arduino-libraries/Servo)
- [pulseIn reference](https://docs.arduino.cc/language-reference/en/functions/advanced-io/pulseIn/)
