#include "singlyLinkedList.c"
#include <stddef.h>
#include<stdlib.h>
#include <stdio.h>

void list_init(linkedList* list) {
	list->head = NULL;
	list->tail = NULL;
}

void push_front(linkedList* list, int value) {
	Node* temp = list->head;
}