#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double x;
  double y;
} Point;

int main() {
  Point first_point = {0.5, 5.9};
  printf("x: %f, y:%f\n", first_point.x, first_point.y);

  Point another_point = {.y = 7.5, .x = 5.3};
  printf("x: %f, y:%f\n", another_point.x, another_point.y);

  /* With pointer */
  Point *point = malloc(sizeof(Point));
  point->x = 2.3;
  point->y = 3.5;
  printf("x: %f, y:%f\n", point->x, point->y);

  free(point);
}
