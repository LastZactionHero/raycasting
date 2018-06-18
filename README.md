# Test if Point is within a Polygon

Determine if a point lies within a polygon via the [raycasting technique](https://en.wikipedia.org/wiki/Point_in_polygon#Ray_casting_algorithm).

## Usage

```
// Construct a polygon from line segments
segment_t segments[] = {
    {{-5, -5}, {0, 5}},
    {{0, 5}, {5, -5}},
    {{5, -5}, {-5, -5}}
};
polygon_t triangle = {
  .segments = &segments[0],
  .segment_count = 3
};

// Pick the point to test
point_t point_inside = {0, 0};

// Check if within polygon
check_inside(&triangle, &point_inside);
```

## Running tests

```
g++ ./src/test.c ./src/segment.c ./src/polygon.c -o ./bin/test.o
./bin/tests.o
```