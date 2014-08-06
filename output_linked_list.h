//
//  output_linked_list.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_output_linked_list_h
#define Comp2x2Search_output_linked_list_h

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int u[7];
  int v[7];
  int s[7];
  int t[7];
  unsigned short int matrix[128][128];
  struct node *next;
};

void push(int u[7], int v[7], int s[7], int t[7],
          unsigned short int matrix[128][128],struct node **head);
void printResults(struct node **head, int branch);
void initResults(int branch);
void endResults(int branch);

#endif
