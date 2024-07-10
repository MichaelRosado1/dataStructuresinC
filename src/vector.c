#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include<stdlib.h>

void vector_init(Vector* vector) {
	// set vector size and capacity
	if (vector) {
		vector->size = 0;
		// Going to set the capacity to a larger number to reduce reallocations
		vector->capacity = 8;

		vector->data = (int*) malloc(sizeof(int) * vector->capacity);

		if (vector->data == NULL) {
			fprintf(stderr, "Memory Allocation error\n");
		}
	}
}

void vector_append(Vector* vector, int value) {
	// we are going to add this value to the end of the vector
	// we should first check if the size is at the capacity already.
	if (vector) {
		if (vector->data == NULL) {
			fprintf(stderr, "data is null\n");
			return;
		}
		if (vector->size == vector->capacity) {
			// this means we need to resize the entire array
			// to reduce the resizing again, I'm going to only add a few more positions to the array 
			vector->capacity *= 2;
			vector->data = (int*) realloc(vector->data, vector->capacity * sizeof(int));
			if (vector->data == NULL) {
				fprintf(stderr, "error allocating memory\n");
			}
		}	

		// now we have fixed the issue of the vector being at cap so we can append now
		vector->data[vector->size++] = value;
	}
}

void vector_set(Vector* vector, int index, int value) {
	// first I need to check if the index is within bounds
	if (vector) { 
		if (index < 0 || index >= vector->size) {
			return;
		}

		if (vector->data == NULL) {
			fprintf(stderr, "data is null\n");
		}
		vector->data[index] = value;
	}
}

int vector_get(Vector* vector, int index) {
	if (vector) {
		if (vector->data == NULL) {
			fprintf(stderr, "data is null\n");
		}
		if (index >= 0 && index < vector->size) {
			return vector->data[index];
		} else {
			fprintf(stderr, "Index not within bounds\n");
			return -1;
		}
	}
	return -1;
}

void vector_resize(Vector* vector, int new_capacity) {
	if (vector) {
		vector->capacity = new_capacity;
		if (vector->data) {
			vector->data = (int*) realloc(vector->data, vector->capacity * sizeof(int));
			if (vector->data == NULL) {
				fprintf(stderr, "Error reallocating memory\n");
			}
		}
	}
}

	void vector_free(Vector* vector) {
		if (vector) {

			if (vector->data == NULL) {
				fprintf(stderr, "Attempting to free null data\n");
				return;
			}

			free(vector->data);
			vector->data = NULL;
		}
	}

