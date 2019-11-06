
// FILE: Kiosk.c
// Written By: Eunsoo Jang
// Date: April 23, 2018

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Kiosk.h"

static int count =0;
static int nServed =0;


char *genKioId(){
  char *Id = malloc(5*sizeof(char));
  count++;
  sprintf(Id, "K%d", count);
  return Id;
}

Kiosk *newKiosk(){
  Kiosk *k = malloc(sizeof(Kiosk));
  k->id=genKioId();
  k->nowServing=NULL;
  k->timeRemaining=0;
  return k;
}


char*getKioskId(const Kiosk *k){
  return k->id;
}

Customer *getCustomer(const Kiosk *k){
  return k->nowServing;
}

void assignCustomer(Kiosk *k, Customer *c){
  k->nowServing = c;
  k->timeRemaining = getServiceTime(c);
}

void tick(Kiosk *k){
  if (k->nowServing) {
     k->timeRemaining--;
     if (k->timeRemaining == 0) {
        k->nowServing = NULL;
        nServed++;
     }
  }
}

int busy(const Kiosk *k){
  return (k->nowServing!=NULL);
}

int getNServed(){
  return nServed;
}

char *kioskToString(const Kiosk *k){
  char *result = malloc(30*sizeof(char));
  sprintf(result, "%s: %s", k->id, (k->nowServing ? custToString(k->nowServing): "[]"));
  return result;
}
