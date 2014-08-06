//
//  tree_functions.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include <stdio.h>
#include "linalg_row_operations.h"
#include "running_gaussian_elimination.h"


void tree1(int k, int i, int matrix[7][4], int E[7][4][4], int pivots[7][4],
              int rge[7][4], int u[7], int s[7], int zero[3])
{
    //lookup table for indices
  static int first[3][2] = {{0,1}, {0,2}, {2,2}};
  static int index[17][2] =
  {
    {0,1}, {1,0}, {0,0}, {1,1},
    {2,0}, {3,0}, {2,1}, {3,1},
    {0,2}, {1,2}, {0,3}, {1,3},
    {2,2}, {3,2}, {2,3}, {3,3},
    {4,4}
  };
    //set u,s indices
  if (k == 0) {
    u[k] = first[i][0];
    s[k] = first[i][1];
  }
  else {
    u[k] = index[i][0];
    s[k] = index[i][1];
  }
    //handle zero case
  zero[k] = (i == 16);
  tensor(matrix[k], u[k], s[k]);  //fill raw matrix
  RGE_Solver(k, matrix[k], E, rge[k], pivots);  //Running Gaussian Elimination
}

void tree2(int k, int i, int matrix[7][4], int inZero[7], int outZero[7],
              int inU[7], int inS[7], int outU[7], int outS[7], int outV[7])
{
    //lookup table for indices
  static int alt[17][2] =
  {
    {0,1}, {1,0}, {0,0}, {1,1}, {2,0}, {3,0}, {2,1}, {3,1},
    {0,2}, {1,2}, {0,3}, {1,3}, {2,2}, {3,2}, {2,3}, {3,3}, {4,4}
  };
    //set indices
  if (inZero[k] == 1) {
    outU[k] = 4;
    outV[k] = alt[i][0];
    outS[k] = alt[i][1];
  }
  else {  //set indices for zero case
    outU[k] = inU[k];
    outV[k] = i;
    outS[k] = inS[k];
  }
    //check for zero case
  if (k > 3 && k < 7) {
    if (i == 16) {
      outZero[k - 4] = 1;
    }
    else {
      outZero[k - 4] = 0;
    }
  }
  tensor(matrix[k], outV[k], outS[k]);  //fill raw matrix
}

int levelTWOcheck(int matrix[7][4]){
  int i, j;
  for (i = 0; i < 7; i++) {
    for (j=0; j<4; j++) {
      if (matrix[i][j]) {
        return 1;
      }
    }
  }
  return 0;
}

void tree3(int k, int i, int VT[7][4], int UT[7][4], int rge[7][4],
                int E[7][4][4], int pivots[7][4], int inZero[3], int inU[7],
                int inS[7], int inV[7], int outU[7], int outV[7], int outS[7],
                int outT[7])
{
  static int alt[96][3] =
  { //u:0, v:1, t:2, s = 4
    {0,0,0}, {0,0,1}, {0,0,2}, {0,0,3}, {0,1,0}, {0,1,1}, {0,1,2}, {0,1,3},
    {0,2,0}, {0,2,1}, {0,2,2}, {0,2,3}, {0,3,0}, {0,3,1}, {0,3,2}, {0,3,3},
    {0,4,0}, {0,4,1}, {0,4,2}, {0,4,3}, {1,0,0}, {1,0,1}, {1,0,2}, {1,0,3},
    {1,1,0}, {1,1,1}, {1,1,2}, {1,1,3}, {1,2,0}, {1,2,1}, {1,2,2}, {1,2,3},
    {1,3,0}, {1,3,1}, {1,3,2}, {1,3,3}, {1,4,0}, {1,4,1}, {1,4,2}, {1,4,3},
    {2,0,0}, {2,0,1}, {2,0,2}, {2,0,3}, {2,1,0}, {2,1,1}, {2,1,2}, {2,1,3},
    {2,2,0}, {2,2,1}, {2,2,2}, {2,2,3}, {2,3,0}, {2,3,1}, {2,3,2}, {2,3,3},
    {2,4,0}, {2,4,1}, {2,4,2}, {2,4,3}, {3,0,0}, {3,0,1}, {3,0,2}, {3,0,3},
    {3,1,0}, {3,1,1}, {3,1,2}, {3,1,3}, {3,2,0}, {3,2,1}, {3,2,2}, {3,2,3},
    {3,3,0}, {3,3,1}, {3,3,2}, {3,3,3}, {3,4,0}, {3,4,1}, {3,4,2}, {3,4,3},
    {4,0,0}, {4,0,1}, {4,0,2}, {4,0,3}, {4,1,0}, {4,1,1}, {4,1,2}, {4,1,3},
    {4,2,0}, {4,2,1}, {4,2,2}, {4,2,3}, {4,3,0}, {4,3,1}, {4,3,2}, {4,3,3}
  };
  
  if ((k > 3) && (inZero[k - 4])) {
    outU[k] = alt[i][0];
    outV[k] = alt[i][1];
    outS[k] = 4;
    outT[k] = alt[i][2];
  }
  else {
    outU[k] = inU[k];
    outV[k] = inV[k];
    outS[k] = inS[k];
    outT[k] = i;
  }
  tensor(VT[k], outV[k], outT[k]);
  tensor(UT[k], outU[k], outT[k]);
  RGE_Solver(k, VT[k], E, rge[k], pivots);
  
}


int vCheck(int v[7]){
  int i,j;
  for (i = 0, j = 0; i < 7; i++) {
    if (v[7]==4) {
      j++;
    }
  }
  return (j < 4);
}

void getLateIndices(int lateArr[7], int inZ[7], int number){
  int i;
  for (i = 0; i < 7; i++) {
    if (inZ[i] == 1) {
      lateArr[i] = number;
    }
    else {
      lateArr[i] = 5;
    }
  }
}
int getLowerIndex(int index, int flag[3], int entry)
{
  if(flag[entry-1] == 0) {
    return 0;
  }
  else {
    return index;
  }
}
