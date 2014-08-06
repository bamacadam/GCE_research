//
//  linalg_row_operations.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

unsigned int getRank(int spread)
{
  static unsigned int bits[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  static int ranks[128] = {
    0, 1, 1, 2, 1, 2, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 
    4, 5, 5, 6, 5, 6, 6, 7
  };
  return bits[ranks[spread]];
}

unsigned int extRank(int spread)
{
  static unsigned int bits[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  static int ranks[128] = {
    0, 1, 1, 2, 1, 2, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7
  };
  return bits[7 - ranks[spread]];
}

int dot4(int a[4], int b[4])
{
  return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
}

int dot7(int a[7], int b[7])
{
  return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3] + a[4]*b[4] +a[5]*b[5];
}

int paritySwitch(int rank, int parity)
{
  static int bits[8] = {1,2,4,8,16,32,64,128};
  return bits[rank] - (parity+1);
}


void transpose(int input[7][4], int output[4][7])
{
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 7; j++) {
      output[i][j] = input[j][i];
    }
  }
}



void tensor(int vector[4], int A, int B)
{
  static int table[5][2] = {
    {1,-1}, {1,1}, {1,0}, {0,1}, {0,0}
  };
  int i, j, k;
  for (i = 0, k = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++, k++)
    {
      vector[k] = table[A][i] * table[B][j];
    }
  }
}

void matrixVector4(int X[4][4], int y[4], int z[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    z[i] = dot4(X[i], y);
  }
}

void matrixVector47x7(int X[4][7], int y[7], int z[4]){
  int i, k[4] = {0};
  for (i = 0; i < 4; i++)
  {
    k[i] = dot7(X[i], y);
    z[i] = k[i];
  }
}

void rowOpp(int matrix[4][4], int coeffs[4], int A, int B)
{
  int i;
  for (i = 0; i < 4; i++)
  {
    matrix[B][i] =  coeffs[A]*matrix[B][i] - coeffs[B]*matrix[A][i];
  }
  coeffs[B] = 0;
}


void rowCopy(int in[4], int out[4])
{
  int i;
  for (i=0; i<4; i++)
  {
    out[i] = in[i];
  }
}

void rowSwap(int matrix[4][4], int vector[4], int A, int B)
{
  int i, j;
  for (i=0; i<4; i++)
  {
    j = matrix[A][i];
    matrix[A][i] = matrix[B][i];
    matrix[B][i] = j;
  }
  j = vector[A];
  vector[A] = vector[B];
  vector[B] = j;
}
