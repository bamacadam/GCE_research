//
//  solution_level.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_solution_level_h
#define Comp2x2Search_solution_level_h

typedef struct level {
  unsigned short int spread[4][128];
  unsigned short int parity[4][128][128];
} solution;

void init_level (solution *input);
 
int get_spread_parity(int in[7], unsigned int out[2]);

void fill_solutions(int flag[4][30][7], solution *US, int len[4]);


#endif
