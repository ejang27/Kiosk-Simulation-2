
// FILE: Queue.h
// Written By: Eunsoo Jang
// Date: April 23, 2018

#include "List.h"

typedef struct{
  List *L;
}Queue;

Queue *newQueue();
int sizeQ(const Queue *q);
int emptyQ(const Queue *q);
void insertQ(Queue *q, void *item);
void *removeQ(Queue *q);
