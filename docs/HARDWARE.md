# Hardware and proposed wiring

This is a planning table, not a verified schematic. Photos do not establish component ratings or exact connections.

| Component | Evidence / specification status |
| --- | --- |
| Four-arm frame | Visible, red and white; exact model unknown |
| Four brushless motors | Visible; KV and electrical ratings unknown |
| Arduino Uno-format board | Visible; Uno selected in the IDE |
| Four ESC channels | Indicated by code; exact units and protocols unconfirmed |
| Radio transmitter | Visible; model, receiver, binding, and wiring unconfirmed |
| Flight battery / power distribution | Required for powered tests; ratings and topology unconfirmed |
| IMU / flight sensors | Not positively identified; not used by supplied example |

## Proposed signal connections

| Sketch channel | Uno signal pin | Physical motor position |
| --- | --- | --- |
| M1 / ESC1 | D3 | Must be labeled and confirmed |
| M2 / ESC2 | D5 | Must be labeled and confirmed |
| M3 / ESC3 | D6 | Must be labeled and confirmed |
| M4 / ESC4 | D9 | Must be labeled and confirmed |

These pins follow the visible historical code. Servo produces timed pulses; hardware PWM pins are not inherently required by this API. Flight motor ordering is not defined here.

## Power and signal requirements

- Confirm each ESC accepts standard servo-style pulse signals; this example does not implement DShot or other digital ESC protocols.
- Use the ESC manufacturer's specified battery, motor wiring, input voltage, pulse range, and arming procedure.
- Connect the Arduino ground to ESC signal ground as required by the ESC manual.
- Motor power must use a suitable battery and correctly rated distribution; do not route motor current through Arduino.
- Use USB power for the Arduino during development. Do not connect battery voltage to its 5V pin.
- Do not connect multiple BEC power outputs together or backfeed USB. Confirm the supply arrangement before connecting any ESC red power wire.
- Three motor phase wires connect to the corresponding ESC; never to Arduino signal pins.
- Remove propellers and disconnect battery before inspecting or changing connections.

A minimum command of 1000 microseconds and test command of 1100 microseconds are example values, not verified specifications. Minimum pulse is not electrical isolation and a software stop cannot replace unplugging the motor battery.
