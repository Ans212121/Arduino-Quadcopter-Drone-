#include <cassert>
#include <iostream>
#include "../firmware/throttle_diagnostic/throttle_logic.h"

int main() {
  // Signal timeout, acceptance boundaries, and saturation at both limits.
  const unsigned long inputs[] = {0, 899, 900, 999, 1000, 1200, 1500, 1501, 2100, 2101, 0xFFFFFFFFUL};
  const uint16_t expected[] = {1000, 1000, 1000, 1000, 1000, 1200, 1500, 1500, 1500, 1000, 1000};
  for (unsigned int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); ++i)
    assert(throttleCommand(inputs[i]) == expected[i]);
  std::cout << "11 throttle boundary cases passed.\\n";
}
