//
//  solution_check_functions.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include "solution_level.h"
#include "linalg_row_operations.h"
#include <string.h>

int opfill(int sp, int in[7][4], int out[4][7])
{
  static int spread[128][7] =
  {
    {0,0,0,0,0,0,0},{1,0,0,0,0,0,0},{0,1,0,0,0,0,0},{1,1,0,0,0,0,0},
    {0,0,1,0,0,0,0},{1,0,1,0,0,0,0},{0,1,1,0,0,0,0},{1,1,1,0,0,0,0},
    {0,0,0,1,0,0,0},{1,0,0,1,0,0,0},{0,1,0,1,0,0,0},{1,1,0,1,0,0,0},
    {0,0,1,1,0,0,0},{1,0,1,1,0,0,0},{0,1,1,1,0,0,0},{1,1,1,1,0,0,0},
    {0,0,0,0,1,0,0},{1,0,0,0,1,0,0},{0,1,0,0,1,0,0},{1,1,0,0,1,0,0},
    {0,0,1,0,1,0,0},{1,0,1,0,1,0,0},{0,1,1,0,1,0,0},{1,1,1,0,1,0,0},
    {0,0,0,1,1,0,0},{1,0,0,1,1,0,0},{0,1,0,1,1,0,0},{1,1,0,1,1,0,0},
    {0,0,1,1,1,0,0},{1,0,1,1,1,0,0},{0,1,1,1,1,0,0},{1,1,1,1,1,0,0},
    {0,0,0,0,0,1,0},{1,0,0,0,0,1,0},{0,1,0,0,0,1,0},{1,1,0,0,0,1,0},
    {0,0,1,0,0,1,0},{1,0,1,0,0,1,0},{0,1,1,0,0,1,0},{1,1,1,0,0,1,0},
    {0,0,0,1,0,1,0},{1,0,0,1,0,1,0},{0,1,0,1,0,1,0},{1,1,0,1,0,1,0},
    {0,0,1,1,0,1,0},{1,0,1,1,0,1,0},{0,1,1,1,0,1,0},{1,1,1,1,0,1,0},
    {0,0,0,0,1,1,0},{1,0,0,0,1,1,0},{0,1,0,0,1,1,0},{1,1,0,0,1,1,0},
    {0,0,1,0,1,1,0},{1,0,1,0,1,1,0},{0,1,1,0,1,1,0},{1,1,1,0,1,1,0},
    {0,0,0,1,1,1,0},{1,0,0,1,1,1,0},{0,1,0,1,1,1,0},{1,1,0,1,1,1,0},
    {0,0,1,1,1,1,0},{1,0,1,1,1,1,0},{0,1,1,1,1,1,0},{1,1,1,1,1,1,0},
    {0,0,0,0,0,0,1},{1,0,0,0,0,0,1},{0,1,0,0,0,0,1},{1,1,0,0,0,0,1},
    {0,0,1,0,0,0,1},{1,0,1,0,0,0,1},{0,1,1,0,0,0,1},{1,1,1,0,0,0,1},
    {0,0,0,1,0,0,1},{1,0,0,1,0,0,1},{0,1,0,1,0,0,1},{1,1,0,1,0,0,1},
    {0,0,1,1,0,0,1},{1,0,1,1,0,0,1},{0,1,1,1,0,0,1},{1,1,1,1,0,0,1},
    {0,0,0,0,1,0,1},{1,0,0,0,1,0,1},{0,1,0,0,1,0,1},{1,1,0,0,1,0,1},
    {0,0,1,0,1,0,1},{1,0,1,0,1,0,1},{0,1,1,0,1,0,1},{1,1,1,0,1,0,1},
    {0,0,0,1,1,0,1},{1,0,0,1,1,0,1},{0,1,0,1,1,0,1},{1,1,0,1,1,0,1},
    {0,0,1,1,1,0,1},{1,0,1,1,1,0,1},{0,1,1,1,1,0,1},{1,1,1,1,1,0,1},
    {0,0,0,0,0,1,1},{1,0,0,0,0,1,1},{0,1,0,0,0,1,1},{1,1,0,0,0,1,1},
    {0,0,1,0,0,1,1},{1,0,1,0,0,1,1},{0,1,1,0,0,1,1},{1,1,1,0,0,1,1},
    {0,0,0,1,0,1,1},{1,0,0,1,0,1,1},{0,1,0,1,0,1,1},{1,1,0,1,0,1,1},
    {0,0,1,1,0,1,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,1},{1,1,1,1,0,1,1},
    {0,0,0,0,1,1,1},{1,0,0,0,1,1,1},{0,1,0,0,1,1,1},{1,1,0,0,1,1,1},
    {0,0,1,0,1,1,1},{1,0,1,0,1,1,1},{0,1,1,0,1,1,1},{1,1,1,0,1,1,1},
    {0,0,0,1,1,1,1},{1,0,0,1,1,1,1},{0,1,0,1,1,1,1},{1,1,0,1,1,1,1},
    {0,0,1,1,1,1,1},{1,0,1,1,1,1,1},{0,1,1,1,1,1,1},{1,1,1,1,1,1,1}
  };
    //static int bits[8] = {1,2,4,8,16,32,64,128};
  int i, j;
  int tmp[7][4] = {0};
  for (i = 0, j = 0; i < 7; i++) {
    if (spread[sp][i] != 0) {
      rowCopy(in[i], tmp[j]);
      j++;
    }
  }
  transpose(tmp, out);
  return j;
}

void rowcheck(int a[4], int b, unsigned short int chk[3])
{
  static int comp[4][4] = {
    {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}
  };
  if (b == 4) {
    chk[0] = (a[0] == 0 && a[1] == 0 & a[2] == 0 && a[3] == 0);
    chk[1] = chk[0];
  }
  else {
    chk[0] = (a[0] == comp[b][0] && a[1] == comp[b][1] &&
              a[2] == comp[b][2] && a[3] == comp[b][3]);
    chk[1] = (a[0] == -comp[b][0] && a[1] == -comp[b][1] &&
              a[2] == -comp[b][2] && a[3] == -comp[b][3]);
  }
  chk[2] = chk[0] | chk[1];
}

int parityfill(unsigned short int parity[128], int hold[128][4], int comp,
             unsigned int n)
{
  static int bits[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  unsigned short int i, j, k;
  unsigned short int chk[3] = {0};
  for (i = 0, j = bits[n]-1, k = 0; i < bits[n-1]; i++, j--)
  {
    rowcheck(hold[i], comp, chk);
    parity[i] = chk[0];
    parity[j] = chk[1];
    k |= chk[2];
  }
  return (k > 0);
}



  //This could be done with openCL
void matrixcheck(int out[4][7], int hold[128][4], int n)
{
  int i;
  static int bits[9] = {0,1,2,4,8,16,32,64,128};
  static int parities[128][7] = {
    {1, 1, 1, 1, 1, 1, 1},	{-1, 1, 1, 1, 1, 1, 1},
    {1, -1, 1, 1, 1, 1, 1},	{-1, -1, 1, 1, 1, 1, 1},
    {1, 1, -1, 1, 1, 1, 1},	{-1, 1, -1, 1, 1, 1, 1},
    {1, -1, -1, 1, 1, 1, 1},	{-1, -1, -1, 1, 1, 1, 1},
    {1, 1, 1, -1, 1, 1, 1},	{-1, 1, 1, -1, 1, 1, 1},
    {1, -1, 1, -1, 1, 1, 1},	{-1, -1, 1, -1, 1, 1, 1},
    {1, 1, -1, -1, 1, 1, 1},	{-1, 1, -1, -1, 1, 1, 1},
    {1, -1, -1, -1, 1, 1, 1},	{-1, -1, -1, -1, 1, 1, 1},
    {1, 1, 1, 1, -1, 1, 1},	{-1, 1, 1, 1, -1, 1, 1},
    {1, -1, 1, 1, -1, 1, 1},	{-1, -1, 1, 1, -1, 1, 1},
    {1, 1, -1, 1, -1, 1, 1},	{-1, 1, -1, 1, -1, 1, 1},
    {1, -1, -1, 1, -1, 1, 1},	{-1, -1, -1, 1, -1, 1, 1},
    {1, 1, 1, -1, -1, 1, 1},	{-1, 1, 1, -1, -1, 1, 1},
    {1, -1, 1, -1, -1, 1, 1},	{-1, -1, 1, -1, -1, 1, 1},
    {1, 1, -1, -1, -1, 1, 1},	{-1, 1, -1, -1, -1, 1, 1},
    {1, -1, -1, -1, -1, 1, 1},	{-1, -1, -1, -1, -1, 1, 1},
    {1, 1, 1, 1, 1, -1, 1},	{-1, 1, 1, 1, 1, -1, 1},
    {1, -1, 1, 1, 1, -1, 1},	{-1, -1, 1, 1, 1, -1, 1},
    {1, 1, -1, 1, 1, -1, 1},	{-1, 1, -1, 1, 1, -1, 1},
    {1, -1, -1, 1, 1, -1, 1},	{-1, -1, -1, 1, 1, -1, 1},
    {1, 1, 1, -1, 1, -1, 1},	{-1, 1, 1, -1, 1, -1, 1},
    {1, -1, 1, -1, 1, -1, 1},	{-1, -1, 1, -1, 1, -1, 1},
    {1, 1, -1, -1, 1, -1, 1},	{-1, 1, -1, -1, 1, -1, 1},
    {1, -1, -1, -1, 1, -1, 1},	{-1, -1, -1, -1, 1, -1, 1},
    {1, 1, 1, 1, -1, -1, 1},	{-1, 1, 1, 1, -1, -1, 1},
    {1, -1, 1, 1, -1, -1, 1},	{-1, -1, 1, 1, -1, -1, 1},
    {1, 1, -1, 1, -1, -1, 1},	{-1, 1, -1, 1, -1, -1, 1},
    {1, -1, -1, 1, -1, -1, 1},	{-1, -1, -1, 1, -1, -1, 1},
    {1, 1, 1, -1, -1, -1, 1},	{-1, 1, 1, -1, -1, -1, 1},
    {1, -1, 1, -1, -1, -1, 1},	{-1, -1, 1, -1, -1, -1, 1},
    {1, 1, -1, -1, -1, -1, 1},	{-1, 1, -1, -1, -1, -1, 1},
    {1, -1, -1, -1, -1, -1, 1},	{-1, -1, -1, -1, -1, -1, 1},
    {1, 1, 1, 1, 1, 1, -1},	{-1, 1, 1, 1, 1, 1, -1},
    {1, -1, 1, 1, 1, 1, -1},	{-1, -1, 1, 1, 1, 1, -1},
    {1, 1, -1, 1, 1, 1, -1},	{-1, 1, -1, 1, 1, 1, -1},
    {1, -1, -1, 1, 1, 1, -1},	{-1, -1, -1, 1, 1, 1, -1},
    {1, 1, 1, -1, 1, 1, -1},	{-1, 1, 1, -1, 1, 1, -1},
    {1, -1, 1, -1, 1, 1, -1},	{-1, -1, 1, -1, 1, 1, -1},
    {1, 1, -1, -1, 1, 1, -1},	{-1, 1, -1, -1, 1, 1, -1},
    {1, -1, -1, -1, 1, 1, -1},	{-1, -1, -1, -1, 1, 1, -1},
    {1, 1, 1, 1, -1, 1, -1},	{-1, 1, 1, 1, -1, 1, -1},
    {1, -1, 1, 1, -1, 1, -1},	{-1, -1, 1, 1, -1, 1, -1},
    {1, 1, -1, 1, -1, 1, -1},	{-1, 1, -1, 1, -1, 1, -1},
    {1, -1, -1, 1, -1, 1, -1},	{-1, -1, -1, 1, -1, 1, -1},
    {1, 1, 1, -1, -1, 1, -1},	{-1, 1, 1, -1, -1, 1, -1},
    {1, -1, 1, -1, -1, 1, -1},	{-1, -1, 1, -1, -1, 1, -1},
    {1, 1, -1, -1, -1, 1, -1},	{-1, 1, -1, -1, -1, 1, -1},
    {1, -1, -1, -1, -1, 1, -1},	{-1, -1, -1, -1, -1, 1, -1},
    {1, 1, 1, 1, 1, -1, -1},	{-1, 1, 1, 1, 1, -1, -1},
    {1, -1, 1, 1, 1, -1, -1},	{-1, -1, 1, 1, 1, -1, -1},
    {1, 1, -1, 1, 1, -1, -1},	{-1, 1, -1, 1, 1, -1, -1},
    {1, -1, -1, 1, 1, -1, -1},	{-1, -1, -1, 1, 1, -1, -1},
    {1, 1, 1, -1, 1, -1, -1},	{-1, 1, 1, -1, 1, -1, -1},
    {1, -1, 1, -1, 1, -1, -1},	{-1, -1, 1, -1, 1, -1, -1},
    {1, 1, -1, -1, 1, -1, -1},	{-1, 1, -1, -1, 1, -1, -1},
    {1, -1, -1, -1, 1, -1, -1},	{-1, -1, -1, -1, 1, -1, -1},
    {1, 1, 1, 1, -1, -1, -1},	{-1, 1, 1, 1, -1, -1, -1},
    {1, -1, 1, 1, -1, -1, -1},	{-1, -1, 1, 1, -1, -1, -1},
    {1, 1, -1, 1, -1, -1, -1},	{-1, 1, -1, 1, -1, -1, -1},
    {1, -1, -1, 1, -1, -1, -1},	{-1, -1, -1, 1, -1, -1, -1},
    {1, 1, 1, -1, -1, -1, -1},	{-1, 1, 1, -1, -1, -1, -1},
    {1, -1, 1, -1, -1, -1, -1},	{-1, -1, 1, -1, -1, -1, -1},
    {1, 1, -1, -1, -1, -1, -1},	{-1, 1, -1, -1, -1, -1, -1}
  };
  for (i = 0; i < bits[n]; i++)
  {
    matrixVector47x7(out, parities[i], hold[i]);
  }
}

int checkspread(int spread, int matrix[7][4], unsigned short int parity[128],
                int comp)
{
  int hold[128][4] = {0};
  int op[4][7] = {0};
  int chk = 0;
  int rank = opfill(spread, matrix, op);
  matrixcheck(op, hold, rank);
  chk = parityfill(parity, hold, comp, rank);
  return chk;
}
