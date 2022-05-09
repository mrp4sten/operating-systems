#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double x;
	double y;
} Point;

int main() {
	Point point = {0.5, 5.9};
	printf("x: %f, y:%f\n", point.x, point.y);
}
