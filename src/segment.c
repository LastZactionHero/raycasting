#include <stdio.h>

#include "../headers/segment.h"
#include "../headers/math.h"

bool_t check_intersection(
  segment_t *segment_a,
  segment_t *segment_b
) {
  // Find the minimum and maximum Y values of segment A
  float min_a_y = MIN(segment_a->a.y, segment_a->b.y);
  float max_a_y = MAX(segment_a->a.y, segment_a->b.y);

  // Convert Segment A into an equation
  float m = (segment_a->a.y - segment_a->b.y) / (segment_a->a.x - segment_a->b.x);
  float C = segment_a->a.y - m * segment_a->a.x;

  // Check if Segment B crosses Segment A
  // On what side of the line is Segment B, Point A?
  float horizontal_intersection_a = m * segment_b->a.x + C;
  int side_a = horizontal_intersection_a - segment_b->a.y > 0;

  // On what side of the line is Segment B, Point B?
  float horizontal_intersection_b = m * segment_b->b.x + C;
  int side_b = horizontal_intersection_b - segment_b->b.y > 0;

  // Intersection occurs if points fall on different sides of the segment
  return (side_b == side_a) ? FALSE : TRUE;
}

void print_segment(
  segment_t *segment
) {
  printf("(%f, %f) - (%f, %f)\n",
    segment->a.x,
    segment->a.y,
    segment->b.x,
    segment->b.y
  );
}