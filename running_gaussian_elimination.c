//
//  running_gaussian_elimination.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include "linalg_row_operations.h"


void rowReduce(int matrix[4][4], int vector[4], int pivot)
{
  int i;
  for (i=pivot+1; i<4; i++)
  {
    if (vector[i] != 0)
    {
      rowOpp(matrix, vector, pivot, i);
    }
  }
}

void initOperator(int E[7][4][4], int k)
{
  int i, j;
  if (k > 0) {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        E[k][i][j] = E[k-1][i][j];
      }
    }
  }
  else {
    for (int i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (i==j) {
          E[k][i][j] = 1;
        }
        else {
          E[k][i][j] = 0;
        }
      }
    }
  }
}

void initPivots(int pivots[7][4], int k)
{
  int i;
  if (k) {
    for (i=0; i<4; i++) {
      pivots[k][i] = pivots[k-1][i];
    }
  }
  else{
    for (i=0; i<4; i++) {
      pivots[k][i] = -1;
    }
  }
  
}



int gaussian(int E[4][4], int vector[4], int level)
{
  int i;
  for (i = level; i < 4; i++) {
    if (vector[i] != 0) {
      rowReduce(E, vector, i);
      if (i != level) {
        rowSwap(E, vector, i, level);
      }
      return 1;
    }
  }
  return 0;
}




void RGE_Solver(int k, int input[4], int E[7][4][4], int X[4], int piv[7][4])
{
  
  int i;
  /*
   We initialize the Operator Matrix
   by copying the previous entry
   */
    //Operater[k][i][j] = (i,j)th entries
  initOperator(E, k);
  initPivots(piv, k);
  matrixVector4(E[k], input, X);
  
  for (i = 0; i < 4; i++) {
    if (piv[k][i] == -1) {
      if(gaussian(E[k], X, i) == 1) {
        piv[k][i] = k;
      }
      break;  //escape the loop once level has been operated on
    }
  }
  
}//Ready for Thesis
 //end of loops functions