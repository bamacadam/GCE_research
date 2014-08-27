  //
  //  main.c
  //  Comp2x2Search
  //
  //  Created by Ben MacAdam on 7/22/14.
  //  Copyright (c) 2014 Ben MacAdam. All rights reserved.
  //

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#include "first_tree.h"

void *dispatch(void *args)
{
  int *n = (int *) args;
  first_tree(*n);
  return NULL;
}

int main ( int argc, char* argv[] )
{
    //first, we initialize the pthread related variables
  
  pthread_t thread[6];
  pthread_attr_t attribute;
    //then we define the specific data
  int i; //counting variable
  int input[64];
    //we initialize the thread variables
  
  
    //now we run the threads
  
  for (i = 0; i < 1; i++) {
    input[i] = 8997;
    pthread_attr_init(&attribute);
    pthread_create(&thread[i], &attribute, dispatch, &input[i]);
  }
    //wait for threads to finish running
  for (i = 0; i < 2; i++) {
    pthread_join(thread[i], NULL);
  }
  return 0;
}






