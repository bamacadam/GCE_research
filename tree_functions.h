//
//  tree_functions.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_tree_functions_h
#define Comp2x2Search_tree_functions_h

#include "linalg_row_operations.h"
#include "running_gaussian_elimination.h"

int vCheck(int v[7]);

void tree1(int k, int i, int matrix[7][4], int E[7][4][4], int pivots[7][4],
              int rge[7][4], int u[7], int s[7], int zero[7]);

void tree2(int k, int i, int matrix[7][4], int inZero[3], int outZero[7],
              int inU[7], int inS[7], int outU[7], int outS[7], int outV[7]);

int levelTWOcheck(int matrix[7][4]);

void getLateIndices(int lateArr[7], int inZ[7], int number);

void tree3(int k, int i, int VT[7][4], int UT[7][4], int rge[7][4],
                int E[7][4][4], int pivots[7][4], int inZero[3], int inU[7],
                int inS[7], int inV[7], int outU[7], int outV[7], int outS[7],
                int outT[7]);

int getLowerIndex(int index, int flag[3], int entry);


#endif
