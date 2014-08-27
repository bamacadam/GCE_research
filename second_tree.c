//
//  second_tree.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include <stdio.h>

#include "tree_functions.h"
#include "solution_level.h"
#include "output_linked_list.h"
#include "solution_check.h"
#include "third_tree.h"

int icheck2(int i[7]) {
  if (
    i[0] == 4 && i[1] == 3 && i[2] == 3 && i[3] == 4 && i[4] == 13 && i[5] == 16 
    )
  {
    return 1;
  }
  else {
    return 0;
  }
}

int second_tree(int inU[7], int inS[7], int inZ[7], struct node **head,
                solution *US)
{
  int late_index[7], outZ[7]; //zero case variables
  int i[7]; //index variable
  int u[7], v[7], s[7];
  getLateIndices(late_index, inZ, 17);
  int matrix[7][4];
  solution *VS = malloc(sizeof(solution));
  init_level(VS);
  int branches = 0;
  int vc = 0, l2c = 0, pc = 0;
  for (i[0] = 0; i[0] < 5; i[0]++)
  {//open loop 0
    tree2(0, i[0], matrix, inZ, outZ, inU, inS, u, s, v);
    for (i[1] = 0; i[1] < 5; i[1]++)
    {//open loop 1
      tree2(1, i[1], matrix, inZ, outZ, inU, inS, u, s, v);
      for (i[2] = 0; i[2] < 5; i[2]++)
      {//open loop 2
        tree2(2, i[2], matrix, inZ, outZ, inU, inS, u, s, v);
        for (i[3] = 0; i[3] < 5; i[3]++)
        {//open loop 3
          tree2(3, i[3], matrix, inZ, outZ, inU, inS, u, s, v);
          for (i[4] = 0; i[4] < late_index[4]; i[4]++)
          {//open loop 3
            tree2(4, i[4], matrix, inZ, outZ, inU, inS, u, s, v);
            for (i[5] = getLowerIndex(i[4], inZ, 5);
                 i[5] < late_index[5]; i[5]++)
            {//open loop 3
              tree2(5, i[5], matrix, inZ, outZ, inU, inS, u, s, v);
              for (i[6] = getLowerIndex(i[5], inZ, 6);
                   i[6] < late_index[6]; i[6]++)
              {//open loop 3
                tree2(6, i[6], matrix, inZ, outZ, inU, inS, u, s, v);
                vc = vCheck(v);
                l2c = levelTWOcheck(matrix);
                if (l2c) {
                  pc = prunecheck(US, VS, matrix, 1);
                  if (pc) {
                    branches++;
                    third_tree(u, v, s, outZ, VS, US, head);
                  }
                  
                }
              }//close loop 6
            }//close loop 5
          }//close loop 4
        }//close loop 3
      }//close loop 2
    }//close loop 1
  }//close loop 0
  free(VS);
  return branches;
}
