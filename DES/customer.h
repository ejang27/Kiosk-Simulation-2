

// FILE: customer.h
// Written By: Eunsoo Jang
// Date: April 23, 2018

typedef struct{
  int arrivalTime;
  int serviceTime;
  char *id;
}Customer;

Customer *newCustomer(int arrivalTime);
char *genCustId();
char *getCustId(const Customer *c);
int getArrivalTime(const Customer *c);
int getServiceTime(const Customer *c);
char *custToString(const Customer *c);
