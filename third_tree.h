//
//  third_tree.h
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#ifndef Comp2x2Search_third_tree_h
#define Comp2x2Search_third_tree_h

#include <stdio.h>
#include "tree_functions.h"
#include "solution_level.h"
#include "output_linked_list.h"
#include "brute_force_check.h"
#include "solution_check.h"

void third_tree(int inU[7], int inV[7], int inS[7], int inZ[3],
                solution *VS, solution *inUS, struct node **head);


#endif
