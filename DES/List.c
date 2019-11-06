

// FILE: List.c
// Written By: Deepak Kumar (rewrote by: Eunsoo Jang)
// Date: April 23, 2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

List *newList() {			// Creates a new empty list
  List *L = malloc(sizeof(List));
  L->head = NULL;
  L->tail = NULL;
  L->size = 0;
  return L;
} // newList()

int size(const List *l) {		// Returns the size of list-l
   return l->size;
} // size()

int empty(const List *l) {		// is the list-l empty?
   return l->size == 0;
} // empty()


void add(List *l, void *item) {	// Add item at end of list-l
   struct node *n= newNode(item);
   if (l->size == 0)
     l->head = l->tail = n;
   else {
      l->tail->next = n;
      l->tail = n;
   }
   l->size++;
} // add()

void *removeItem(List *l, int index) {// Remove item at index and return it

   if (index < 0 || index >= l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   void *item;	// item removed
   if (index == 0) {	// removing the first item
       item = l->head->data;
       if (l->size == 1) { // from a list with 1 item
         free(l->head);
         l->head = l->tail = NULL;
       }
       else {		// from a list with >1 items
          struct node *n = l->head;
          l->head = n->next;
          n->next = NULL;
          free(n);
       }
   }
   else if (index == l->size-1) {// removing the last item
         item = l->tail->data;
         if (l->size == 1) { // from a list with 1 item
            free(l->tail);
            l->head = l->tail = NULL;
         }
         else {		// from a list with >1 items
            struct node *n = l->head;
            for (int i=1; i < index-1; i++)
               n = n->next;
            l->tail = n;
            free(n->next);
            l->tail->next = NULL;
         }
   }
   // still have to remove other item in the middle of the list
   l->size--;
   return item;
} // removeItem()
