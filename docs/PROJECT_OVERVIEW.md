# Quadcopter Robot Design — Course Project

**Course:** Fundamentals of Robot Design

| Team member | الاسم |
| --- | --- |
| Anas Ibrahim Al-Mutairi | أنس إبراهيم المطيري |
| Abdulaziz Zayed Al-Mutairi | عبدالعزيز زايد المطيري |

## Project summary

This educational project explores a quadcopter as an integrated robotic system: a mechanical frame supports actuators and electronics, an Arduino provides an embedded programming platform, ESC channels receive motor commands, and sensor diagnostics expose acceleration and gyroscope variables.

The repository documents assembly photographs, historical throttle-code compilation output, and a sensor-data stream. It also includes a separately prepared individual-channel ESC bench example. Flight-control capability is a development goal rather than a verified result.

## System structure

| Subsystem | Role | Current evidence or limitation |
| --- | --- | --- |
| Mechanical platform | Supports motors and electronics | Assembled four-arm frame visible in the overview photo |
| Actuation | Four motors driven through ESC channels | Motors visible; ratings and exact ESC models require confirmation |
| Embedded controller | Runs development sketches and signal generation | Arduino Uno selected in the pictured IDE |
| Radio-control path | Intended operator input | Transmitter visible and throttle-input code pictured; complete receiver wiring unverified |
| Sensing | Acceleration and gyroscope data | Axis variables appear in Serial Monitor; model, scale, and calibration unconfirmed |
| Power | Supplies controller and motor circuits | Exact battery and distribution design not documented |
| Diagnostics | Exposes development behavior | IDE build output and serial values documented |

## Documented development workflow

1. Assemble and inspect the frame and motor mounts.
2. Integrate the Arduino and inspect electronic connections.
3. Develop diagnostic sketches for motor command signals and sensor data.
4. Inspect compiler output and Serial Monitor.
5. Document results before integrating a complete control loop.

This workflow summarizes the available evidence; it does not claim every subsystem passed a hardware test.

## Acceptance criteria and evidence

| Criterion | Current state | What would complete verification |
| --- | --- | --- |
| Assembly documentation | Available | Component identifiers and verified wiring drawing |
| Historical source-code build | Build-output photo available | Original sketch files and toolchain/library versions |
| Sensor-data output | Serial-output photo available | Sensor identification, units, calibration, and logged measurements |
| Repository bench example | Source available; host syntax check only | Actual Uno build and propeller-free hardware test |
| Radio input | Partial code evidence | Confirmed receiver pinout and signal-loss tests |
| Stable flight | Not established | Validated attitude estimation, control, motor mixing, and recorded controlled tests |

## Design limitations

The pictured throttle code applies the same command to all four ESC channels. A complete flight controller would require sensor processing, independent motor commands, and tested handling of operator input and faults. The supplied bench example intentionally covers one channel at a time and does not implement those functions.

Individual team roles are not assigned in this document because no verified task split was provided. No instructor name, course code, grades, or performance results have been assumed.

## ملخص بالعربي

مشروع مادة **Fundamentals of Robot Design** بإعداد **أنس إبراهيم المطيري** و**عبدالعزيز زايد المطيري**. يتناول بناء منصة درون رباعية واستكشاف دمج الهيكل والمحركات والمتحكم والحساسات. يعرض المستودع صور التجميع ونتيجة تجميع كود سابق وقراءات التسارع والجيروسكوب، إضافة إلى مثال مستقل لاختبار المحركات. يحتاج استكمال التحقق إلى الكود الأصلي ومواصفات القطع ومخطط التوصيل ونتائج الاختبار الفعلي.

## Related documents

- [Project README](../README.md)
- [التوثيق العربي](../README.ar.md)
- [Hardware and proposed wiring](HARDWARE.md)
- [Development evidence](DEVELOPMENT.md)
- [Bench-test guide](BENCH_TEST.md)
- [Project completeness review](REVIEW.ar.md)
- [Development roadmap](ROADMAP.md)


## Source reconstruction update

The team reports the original sketches were deleted. A new throttle diagnostic now reconstructs the visible pulse-validation logic without driving ESC outputs. A separate helper recreates the sensor print format; it does not read a sensor. Eleven host throttle boundary tests passed, along with host syntax checks for the diagnostic/helper using simplified Arduino interfaces. Original source recovery, actual Uno builds, sensor identification, and hardware validation remain incomplete. See [reconstruction notes](RECONSTRUCTION.ar.md).
