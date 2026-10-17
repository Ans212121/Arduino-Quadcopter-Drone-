#pragma once
#include <stdint.h>

// Reconstructed from the photographed loop. Values are pulse widths in us.
inline uint16_t throttleCommand(unsigned long pulseUs) {
  if (pulseUs < 900UL || pulseUs > 2100UL) return 1000;
  if (pulseUs < 1000UL) return 1000;
  if (pulseUs > 1500UL) return 1500;
  return static_cast<uint16_t>(pulseUs);
}
