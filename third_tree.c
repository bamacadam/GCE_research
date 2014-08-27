//
//  third_tree.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include <stdio.h>
#include "tree_functions.h"
#include "solution_level.h"
#include "output_linked_list.h"
#include "brute_force_check.h"
#include "solution_check.h"
#include "final_prune.h"

int icheck3(int i[7])
{
  if (i[0] == 4 && i[1] == 3 && i[2] == 4 && i[3] == 3
      && i[4] == 2 && i[5] == 51 && i[6] == 81) {
    return 1;
  }
  return 0;
}

void third_tree(int inU[7], int inV[7], int inS[7], int inZ[7],
                solution *VS, solution *US, struct node **head)
{
  int i[7];   //index variable
  int rge[7][4], E[7][4][4], pivots[7][4];  //the rge variables
  int u[7], v[7], s[7], t[7]; //uvst variables
  int late_index[7] = {0}; //zero case variables
  getLateIndices(late_index, inZ, 96);
  int matU[7][4] = {0}, matV[7][4] = {0};
  solution *UT = malloc(sizeof(solution)), *VT = malloc(sizeof(solution));
  int count = 0;
  init_level(UT);
  init_level(VT);
  for (i[0] = 0; i[0] < 5; i[0]++)
  {//open loop 0
    tree3(0, i[0], matV, matU, rge, E, pivots, inZ,inU, inS, inV, u, v, s, t);
    for (i[1] = 0; i[1] < 5; i[1]++)
    {//open loop 1
      tree3(1, i[1], matV, matU, rge, E, pivots, inZ, inU, inS, inV, u, v,
            s, t);
      for (i[2] = 0; i[2] < 5; i[2]++)
      {//open loop 2
        tree3(2, i[2], matV, matU, rge, E, pivots, inZ, inU, inS, inV, u,
              v, s, t);
        for (i[3] = 0; i[3] < 5; i[3]++)
        {//open loop 3
          tree3(3, i[3], matV, matU, rge, E, pivots, inZ, inU, inS, inV, u,
                v, s, t);
          for (i[4] = 0; i[4] < late_index[4] && (pivots[3][0] > -1); i[4]++)
          {//open loop 3
            tree3(4, i[4], matV, matU, rge, E, pivots, inZ,inU, inS, inV,
                  u, v, s, t);
            for (i[5] = getLowerIndex(i[4], inZ, 5);
                 (i[5] < late_index[5]) && (pivots[4][1] > -1); i[5]++)
            {//open loop 3
              tree3(5, i[5], matV, matU, rge, E, pivots, inZ,
                    inU, inS, inV, u, v, s, t);
              for (i[6] = getLowerIndex(i[5], inZ, 6);
                   i[6] < late_index[6] && pivots[5][2] > -1; i[6]++)
              {//open loop 3
                tree3(6, i[6], matV, matU, rge, E, pivots, inZ, inU, inS, inV,
                      u, v, s, t);
                
                count++;
                if (pivots[6][3] > 0) {
                  if(prunecheck(VS, UT, matU, 1)) {
                    if (prunecheck(UT, VT, matV, 0)) {
                        final_prune(head, u, v, s, t, US, VS, UT, VT);
                    }
                  }
                }
              }//close loop 6
            }//close loop 5
          }//close loop 4
        }//close loop 3
      }//close loop 2
    }//close loop 1
  }//close loop 0
  free(UT);
  free(VT);
}