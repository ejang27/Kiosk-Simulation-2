

// FILE: Kiosk.h
// Written By: Eunsoo Jang
// Date: April 23, 2018

#include "customer.h"

typedef struct{
  char *id;
  Customer *nowServing;
  int timeRemaining;
}Kiosk;

char *genKioId();
Kiosk *newKiosk();

char *getKioskId(const Kiosk *k);
Customer *getCustomer(const Kiosk *k);
void assignCustomer(Kiosk *k, Customer *c);
void tick(Kiosk *k);
int busy(const Kiosk *k);
int getNServed();
char *kioskToString(const Kiosk *k);
