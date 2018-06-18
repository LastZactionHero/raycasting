#ifndef POLYGON_H
#define POLYGON_H

#include "./segment.h"
#include "./point.h"

typedef struct {
  segment_t *segments;
  int segment_count;
} polygon_t;

bool_t check_inside(polygon_t *polygon, point_t *point);

#endif