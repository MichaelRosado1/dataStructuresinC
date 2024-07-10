#include <stdio.h>
#include "vector.h"

void print_vector(Vector* vector, int bound) {
	for (int i = 0; i < bound; i++) {
		printf("%d ", vector_get(vector, i));
	}

	printf("\n");
}

int main() {
	Vector vector;
	vector_init(&vector);

	vector_append(&vector, 1);
	vector_append(&vector, 2);
	vector_append(&vector, 3);
	vector_append(&vector, 4);
	vector_append(&vector, 5);
	vector_append(&vector, 6);
	vector_append(&vector, 7);
	vector_append(&vector, 8);
	vector_append(&vector, 9);
	vector_append(&vector, 10);

	print_vector(&vector, 10);
	printf("\n");

	vector_set(&vector, 0, 100);
	vector_set(&vector, 9, 100);


	print_vector(&vector, 10);


	vector_resize(&vector, 5);

	print_vector(&vector, 5);


	vector_free(&vector);

	return 0;
}

