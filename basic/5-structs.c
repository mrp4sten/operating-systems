#include <stdio.h>
#include <stdlib.h>

struct Point {
	double x;
	double y;
};

int main() {
	struct Point point = {0.5, 5.9};
	printf("x: %f, y:%f\n", point.x, point.y);
}
