
// FILE: customer.c
// Written By: Eunsoo Jang
// Date: April 23, 2018

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "customer.h"

static int count =0;
char *genCustId(){
  char *Id = malloc(5*sizeof(char));
  count++;
  sprintf(Id, "C%d", count);
  return Id;
}

Customer *newCustomer(int at){
  Customer *c = malloc(sizeof(Customer));
  c->arrivalTime=at;
  c->serviceTime=5+rand()%4;
  c->id=genCustId();
  return c;
}

char *getCustId(const Customer *c){
  return c->id;
}

int getArrivalTime(const Customer *c){
  return c->arrivalTime;
}

int getServiceTime(const Customer *c){
  return c->serviceTime;
}

char *custToString(const Customer *c){
  char *result = malloc(20*sizeof(char));
  sprintf(result, "<%s: %d, %d>", c->id, c->arrivalTime, c->serviceTime);
  return result;
}
