//
//  linalg_row_operations.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_linalg_row_operations_h
#define Comp2x2Search_linalg_row_operations_h

unsigned int getRank(int spread);
unsigned int extRank(int spread);

int dot4(int a[4], int b[4]);
int dot7(int a[7], int b[7]);

int paritySwitch(int rank, int parity);


void transpose(int input[7][4], int output[4][7]);
void tensor(int vector[4], int A, int B);

void matrixVector4(int X[4][4], int y[4], int z[4]);
void matrixVector47x7(int X[4][7], int y[7], int z[4]);

void rowOpp(int matrix[4][4], int coeffs[4], int A, int B);
void rowCopy(int in[4], int out[4]);
void rowSwap(int matrix[4][4], int vector[4], int A, int B);


#endif
