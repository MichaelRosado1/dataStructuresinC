#ifndef VECTOR_H
#define VECTOR_H

#pragma once
typedef struct {
	int* data;
	int size;
	int capacity;	
} Vector;

void vector_init(Vector* vector);
void vector_append(Vector* vector, int value);
void vector_set(Vector* vector, int index, int value);
int vector_get(Vector* vector, int index);
void vector_resize(Vector* vector, int new_capacity);
void vector_free(Vector* vector);

#endif // VECTOR_H