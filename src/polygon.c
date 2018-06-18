#include <stdio.h>

#include "../headers/polygon.h"
#include "../headers/segment.h"
#include "../headers/math.h"

bool_t check_inside(polygon_t *polygon, point_t *point) {
  // Find the furthest left point of the polygon
  float min_x = polygon->segments[0].a.x;
  for(int i = 0; i < polygon->segment_count; i++) {
    int min_segment_x = MIN(polygon->segments[i].a.x, polygon->segments[i].b.x);
    min_x = MIN(min_segment_x, min_x);
  }

  // Create a segment from this far left position to the point
  point_t far_left_point = { min_x - 1,  point->y};
  segment_t test_segment = {far_left_point, *point};

  // Count how many times the test segment intersects the polygon
  int intersection_count = 0;
  for(int i = 0; i < polygon->segment_count; i++) {
    if(check_intersection(&polygon->segments[i], &test_segment)) {
      intersection_count++;
    }
  }

  return (intersection_count % 2 == 1) ? TRUE : FALSE;
}