//
//  final_prune.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_final_prune_h
#define Comp2x2Search_final_prune_h

#include "output_linked_list.h"
#include "solution_level.h"

int intersectSol(unsigned short int sol[5][128][128]);

void expand(unsigned int a, unsigned int b, unsigned short int sol[128][128],
            unsigned int spread);

void fill(unsigned short int sol[128][128], unsigned int spread, int rank,
          unsigned short int sol_inter[128][128]);

void intersect(unsigned short int v[128], unsigned short int t[128],
               unsigned short int vt[128], unsigned short int inter[128][128],
               int limit);

void prune_operation(unsigned int spread, unsigned int rank,
                     unsigned short int US[128], unsigned short int VS[128],
                     unsigned short int UT[128], unsigned short int VT[128],
                     unsigned short int sol[128][128]);

int final_prune(struct node **head, int u[7], int v[7], int s[7], int t[7],
                solution *US, solution *VS, solution *UT, solution *VT);

#endif
