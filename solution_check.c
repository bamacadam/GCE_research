//
//  solution_check.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include "solution_level.h"
#include "solution_check_functions.h"



int prunecheck(solution *prev, solution *curr, int matrix[7][4], int zero)
{
  int i, j, k;
  int comp;
  for (i = 0; i < 4; i++)
  {
    if (zero == 1) {
      comp = 4;
    }
    else {
      comp = i;
    }
    for (j = 0,  k = 0; j < 128; j++) {
      if (prev->spread[i][j]) {
        curr->spread[i][j] = checkspread(j, matrix, curr->parity[i][j], comp);
        if (curr->spread[i][j]) {
          k++;
        }
      }
    }
    if (k == 0)
    {
      return 0;
    }
  }
  return 1;
}