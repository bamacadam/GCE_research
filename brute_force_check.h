//
//  brute_force_check.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_brute_force_check_h
#define Comp2x2Search_brute_force_check_h

#include "linalg_row_operations.h"

void count_solutions(int flag[2187][4], int len[4]);

int Brute_Force_Check(int matrix[4][7], int hold[2187][4]);

void fill_flag(int hold[2187][4], int flag[4][30][7], int len[4]);

int brute_force(int matrix[7][4], int flag[4][30][7], int len[4]);

#endif
