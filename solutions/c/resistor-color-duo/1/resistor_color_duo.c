#include "resistor_color_duo.h"

// Return two-digit resistance value from two int color codes
unsigned int color_code(resistor_band_t band_colors[]) {

  // convert the first code to a tens-place int
  // (i.e. 2 --> 20, 3 --> 30, etc...)
  int tens_place = band_colors[0] * 10;

  // the second band_colors array int becomes the ones place value
  int ones_place = band_colors[1];

  // return the tens_place value plus the ones-place value
  return tens_place + ones_place;
}
