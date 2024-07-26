#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#pragma once

typdef struct {
	int data;
	struct Node* nextNode;
} Node;

typedef struct {
	struct Node* head;
	struct Node* tail;
} linkedList;



void list_init(linkedList* list);

// insertion
void push_front(linkedList* list, int value);
void push_back(linkedList* list, int value);
void insert(linkedList* list, int index, int value);

// deletion
void pop_front(linkedList* list);
void pop_back(linkedList* list);
void remove(linkedList* list, int index);

// Traversal
void print_list(linkedList* list);

// search
Node* get(linkedList* list, int value);

// updating

void update_node(linkedList* list, int index, int newData);

// size
int get_size(linkedList* list);

// cleanup
void list_free(linkedList* list);
