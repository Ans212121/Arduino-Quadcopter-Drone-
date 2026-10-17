# ESC bench-test procedure

## Scope and prerequisites

This sketch is for propeller-free bench checks only. Remove every propeller, secure the frame, keep the battery disconnect accessible, and verify ESC compatibility from its manual. Do not infer flight readiness from a spinning motor.

Default pins: D3, D5, D6, D9. Default stop/arming signal: 1000 us. Default test: 1100 us for at most 2000 ms. These are assumptions that must match your ESC. The example does not perform automatic ESC calibration or maximum-throttle sweeps.

## Setup

1. With motor power disconnected, check signal pins, common signal ground, power isolation, and motor wiring.
2. Open the sketch in Arduino IDE. Select Arduino Uno and the connected port. Install official Servo if needed, then Verify and Upload.
3. Open Serial Monitor at **115200 baud**. Allow the board to restart and display the help text. Opening Serial Monitor can reset an Uno; do so before connecting motor power.
4. After confirming minimum throttle is being commanded, connect motor power following your ESC manufacturer's procedure. If the ESC behaves unexpectedly, disconnect it.
5. Wait at least three seconds after board startup. Send `a` to enable a single test session.
6. Send one of `1`, `2`, `3`, or `4` to test only that channel. A test returns every output to minimum after two seconds and disarms automatically.
7. Send `s` at any time to command minimum on every channel and disarm. Disconnect motor power after testing.

| Command | Behavior |
| --- | --- |
| `h` | Print help |
| `a` | Allow one test after startup wait; remains at minimum |
| `1` to `4` | Run selected channel only, if armed |
| `s` | Minimum pulse on all channels and disarm |
| Any other non-whitespace character | Stop and disarm |

A pending armed session expires after ten seconds. Serial disconnection during a running test does not prevent the two-second timer from ending the test while the program is running normally. This is a software timer, not an independent hardware watchdog; a hang or power fault can defeat it. A low test pulse may not start every motor; do not blindly increase it.

## Evidence log

No hardware results have been entered. Record date, board/core/library versions, component models, signal settings, tested channel, observed behavior, and any faults after real tests. Mark measured results separately from expected behavior.
