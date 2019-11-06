

// File: des.c
// PURPOSE: This program makes given number of kiosks and assigns customers to
//          the kiosks and gives info on the average number of customers in
//          queue during the simulation, how many customers arrived, and also
//          how many customers were served during given time.
//Written by (partially): Eunsoo Jang
//Date due: 4/2/2018


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"
#include "Kiosk.h"

void simulate(int m, int k);
int arrivals();


int main(int argc, char * argv[]){
  srand(time(NULL));

  simulate(atoi(argv[1]),atoi(argv[2]));

  return 0;
}

void simulate(int m, int nk){
  Kiosk *kiosks[nk];
  for(int i=0; i<nk; i++){
    kiosks[i] = newKiosk();
  }
  printf("There are %d kiosks.\n", nk );

  printf("[");
  for(int i=0; i<nk; i++){
    printf("%s ", kioskToString(kiosks[i]));
  }
  printf("]\n");

  Queue *checkInQueue;
  checkInQueue = newQueue();
  int queueLength =0;
  int nc = 0;

  for(int t=1; t<=m; t++){
    int n = arrivals();
    for(int i=1; i<=n; i++){
      Customer *c = newCustomer(t);
      insertQ(checkInQueue,c);
      nc++;
    }
    queueLength+=sizeQ(checkInQueue);
    printf("At time %d there are %d customers on Q.\n", t, sizeQ(checkInQueue));
    for (int k =0; k<nk;k++){
      tick(kiosks[k]);
      if(!busy(kiosks[k]) && !emptyQ(checkInQueue)){
        Customer *c = removeQ(checkInQueue);
        assignCustomer(kiosks[k], c);
      }
    }
    printf("[");
    for(int i=0; i<nk; i++){
      printf("%s ", kioskToString(kiosks[i]));
    }
    printf("]\n");
  }

  float avgQueue=queueLength/m;

  printf("Simulation: %d minutes, with %d kiosks\n", m, nk);
  printf("%d customers arrived.\n%d customers served.\n", nc, getNServed());
  printf("Average queue length: %2f\n", avgQueue);
}

int arrivals(){
  int n=0+rand()%4;
  return n;
}
