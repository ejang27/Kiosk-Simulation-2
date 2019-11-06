
// FILE: node.h
// Written By: Deepak Kumar (rewrote by: Eunsoo Jang)
// Date: April 23, 2018

#ifndef NODE_H
#define NODE_H

struct node {
  void *data;
   struct node *next;
};

struct node *newNode(void *item);

#endif
