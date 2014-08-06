//
//  running_gaussian_elimination.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_running_gaussian_elimination_h
#define Comp2x2Search_running_gaussian_elimination_h

#include "linalg_row_operations.h"


void rowReduce(int matrix[4][4], int vector[4], int pivot);

void initOperator(int E[7][4][4], int k);

void initPivots(int pivots[7][4], int k);


int gaussian(int E[4][4], int vector[4], int level);

void RGE_Solver(int k, int input[4], int E[7][4][4], int X[4], int piv[7][4]);

#endif
