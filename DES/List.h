
// FILE: List.h
// Written By: Deepak Kumar (rewrote by: Eunsoo Jang)
// Date: April 23, 2018

#ifndef LIST_H
#define LIST_H
#include "node.h"

typedef struct {
   int size;
   struct node *head;
   struct node * tail;
} List;

List *newList();			// Creates a new empty list
int size(const List *l);		// Returns the size of list-l
int empty(const List *l);		// is the list-l empty?
void add(List *l, void *item);	// Add item at end of list-l
void *removeItem(List *l, int index);	// Remove item at index and return it

#endif
