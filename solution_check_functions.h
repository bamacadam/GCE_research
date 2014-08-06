//
//  solution_check_functions.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_solution_check_functions_h
#define Comp2x2Search_solution_check_functions_h

#include "solution_level.h"
#include "linalg_row_operations.h"

int opfill(int sp, int in[7][4], int out[4][7]);

int rowcheck(int a[4], int b, unsigned short int chk[3]);

int parityfill(unsigned short int parity[128], int hold[128][4], int comp,
               unsigned int n);

  //This could be done with openCL
void matrixcheck(int out[4][7], int hold[128][4], int n);

int checkspread(int spread, int matrix[7][4], unsigned short int parity[128],
                int comp);

#endif
