#ifndef SEGMENT_H
#define SEGMENT_H

#include "./bool.h"
#include "./point.h"

typedef struct {
  point_t a;
  point_t b;
} segment_t;

bool_t check_intersection(
  segment_t *segment_a,
  segment_t *segment_b
);

void print_segment(
  segment_t *segment
);

#endif