#ifndef DARTS_H
#define DARTS_H

#include <math.h>
#include <stdint.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t landing_position);

float coordinate_to_radius(coordinate_t landing_position);

#endif
