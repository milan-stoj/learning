#include "darts.h"

uint8_t score(coordinate_t landing_position) {

  // calculate radius
  float landing_radius = coordinate_to_radius(landing_position);

  // determine the score from the radius
  if (landing_radius <= 1) {
    return 10;
  } else if (landing_radius <= 5) {
    return 5;
  } else if (landing_radius <= 10) {
    return 1;
  } else {
    return 0;
  }
}

// calculate radius by using a^2 + b^2 = c^2
// c = sqrt(a^2 + b^2)
float coordinate_to_radius(coordinate_t landing_position) {
  return sqrt(landing_position.x * landing_position.x +
              landing_position.y * landing_position.y);
}
