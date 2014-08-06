//
//  solution_check.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_solution_check_h
#define Comp2x2Search_solution_check_h

#include "solution_level.h"
#include "solution_check_functions.h"

int prunecheck(solution prev[4], solution curr[4], int matrix[7][4], int zero);

#endif
