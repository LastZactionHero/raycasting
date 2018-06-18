#include <stdio.h>

#include "../headers/bool.h"
#include "../headers/segment.h"
#include "../headers/polygon.h"

void assert(const char * name, const bool_t expectation, const bool_t result);
void test_segment();
void test_segment_check_intersection();
void test_polygon();
void test_polygon_check_inside();

int main() {
  printf("Running tests...\n");

  test_segment();
  test_polygon();

  return 0;
}

void test_segment() {
  test_segment_check_intersection();
}

void test_segment_check_intersection() {
  // Two crossing segments
  segment_t seg_a = {{-50, 50}, {50, -50}};
  segment_t seg_b = {{-50, -50}, {50, 50}};
  assert("Two crossing segments", TRUE, check_intersection(&seg_a, &seg_b));

  // Two segments, horizontal and vertical
  segment_t seg_c = {{-100, 0}, {100, 0}};
  segment_t seg_d = {{0, -100}, {0, 100}};
  assert("Two segments, horizontal and vertical", TRUE, check_intersection(&seg_c, &seg_d));

  // Two crossing segments that do not intersect
  segment_t seg_e = {{-3, 1}, {-1, 5}};
  segment_t seg_f = {{1, -1}, {10, -3}};
  assert("Two crossing segments that do not intersect", FALSE, check_intersection(&seg_e, &seg_f));

  // Two parallel segments
  segment_t seg_g = {{0, 0}, {10, 10}};
  segment_t seg_h = {{0, 5}, {10, 15}};
  assert("Two parallel segments", FALSE, check_intersection(&seg_g, &seg_h));

  // Intersecting segments
  segment_t seg_i = {{-5, -5}, {0, 5}};
  segment_t seg_j = {{-6, 0}, {0, 0}};
  assert("Intersecting segments", TRUE, check_intersection(&seg_i, &seg_j));
}

void test_polygon(){
  test_polygon_check_inside();
}

void test_polygon_check_inside() {
  // Define a simple triangle
  segment_t segments[] = {
      {{-5, -5}, {0, 5}},
      {{0, 5}, {5, -5}},
      {{5, -5}, {-5, -5}}
  };
  polygon_t triangle = {
    .segments = &segments[0],
    .segment_count = 3
  };

  point_t point_inside = {0, 0};
  point_t point_left = {-50, 0};
  point_t point_right = {50, 0};
  point_t point_above = {0, 50};
  point_t point_below = {0, -50};

  assert("Point inside", TRUE, check_inside(&triangle, &point_inside));
  assert("Point left", FALSE, check_inside(&triangle, &point_left));
  assert("Point right", FALSE, check_inside(&triangle, &point_right));
  assert("Point above", FALSE, check_inside(&triangle, &point_above));
  assert("Point below", FALSE, check_inside(&triangle, &point_below));
}

void assert(const char * name, const bool_t expectation, const bool_t result) {
  if(expectation != result) {
    printf("FAILURE: %s\n", name);
    printf("Expected %d, got %d\n", expectation, result);
  }
}