#include "Vector.h"

void testVectors() {
	vector v0;
	v0.x = 3;
	v0.y = 4;

	vector v1 = {.x = -3, .y = -4};

	printf("\nv0.x %.2f, v0.y %.2f\n", v0.x, v0.y);
	printf("\nv1.x %.2f, v1.y %.2f\n", v1.x, v1.y);
}
