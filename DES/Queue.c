
// FILE: Queue.c
// Written By: Eunsoo Jang
// Date: April 23, 2018

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Queue.h"

Queue *newQueue(){
   Queue *q=malloc(sizeof(Queue));
   q->L=newList();
}
int sizeQ(const Queue *q){
  return size(q->L);
}

int emptyQ(const Queue *q){
  return empty(q->L);
}


void insertQ(Queue *q, void *item){
  add(q->L, item);
}

void *removeQ(Queue *q){
    return removeItem(q->L, 0);
}
