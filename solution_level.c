//
//  solution_level.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include <stdio.h>

typedef struct level {
  unsigned short int spread[4][128];
  unsigned short int parity[4][128][128];
} solution;


int get_spread_parity(int in[7], unsigned int out[2])
{
  int i, j;
  static int bits[7] = {1,2,4,8,16,32,64};
  int parity = 0, spread = 0;
  for (i = 0, j = 0; i < 7; i++) {
    if (in[i] != 0) {
      spread += bits[i];
      if (in[i] == -1) {
        parity += bits[j];
      }
      j++;
    }
  }
  out[0] = spread;
  out[1] = parity;
  return (j > 1);
}


void fill_solutions(int flag[4][30][7], solution *US, int len[4])
{
  unsigned int sp[2];
  int i, j, k;
  //first, initialize all entries to 0
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 128; j++) {
      US->spread[i][j] = 0;
      for (k = 0; k < 128; k++) {
        US->parity[i][j][k] = 0;
      }
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < len[i]; j++) {
      if(get_spread_parity(flag[i][j], sp)){
        US->spread[i][sp[0]] = 1;
        US->parity[i][sp[0]][sp[1]] = 1;
      }
    }
  }
}