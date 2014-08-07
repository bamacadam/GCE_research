//
//  first_tree.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/23/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include <stdio.h>

#include "tree_functions.h"
#include "solution_level.h"
#include "output_linked_list.h"
#include "brute_force_check.h"
#include "second_tree.h"

void first_tree(int n)
{
  int i[7] = {0}; //the index
  int matrix[7][4];  //the unsolved matrix
  int rge[7][4], E[7][4][4], pivots[7][4];  //the rge variables
  int u[7] = {0}, s[7] = {0};     //the (u,s) indices
  int Z[7] = {0};    //the zero index flag
  int flag[4][30][7] = {0}, len[4] = {0};   //the raw solutions
  solution *US = malloc(sizeof(solution));  //the solution struct
  struct node *head = NULL;
  
  initResults(n);
  static int second_index[3] = {0, 4, 12};
  int branch[2] = {0};
  for(i[0] = 0; i[0] < 3; i[0]++)
  {//Opens loop 0
    tree1(0, i[0], matrix, E, pivots, rge, u, s, Z);
    for(i[1] = second_index[i[0]]; i[1] < 16; i[1]++)
    {//opens loop1
      tree1(1, i[1], matrix, E, pivots, rge, u, s, Z);
      for(i[2] = i[1]; i[2]<16; i[2]++)
      {//opens loop2
        tree1(2, i[2], matrix, E, pivots, rge, u, s, Z);
        for(i[3] = i[2]; i[3] < 16; i[3]++)
        {//opens loop3
          tree1(3, i[3], matrix, E, pivots, rge, u, s, Z);
          for(i[4] = i[3]; i[4] < 17; i[4]++)
          {//opens loop4
            tree1(4, i[4], matrix, E, pivots, rge, u, s, Z);
            for(i[5] = i[4]; (i[5] < 17) && (pivots[4][1] > 0) ; i[5]++)
            {//opens loop 5
              tree1(5, i[5], matrix, E, pivots, rge, u, s, Z);
              for(i[6] = i[5]; (i[6] < 17) && (pivots[4][2] > 1); i[6]++)
              {//opens loop 6
                tree1(6, i[6], matrix, E, pivots, rge, u, s, Z);
                if (pivots[6][3] > 0)
                {
                  if (brute_force(matrix, flag, len))
                  {
                    if (branch[0] % 10000 == n)
                    {
                        //initUS(US);
                        //printf("%i", branch);
                      fill_solutions(flag, US, len);
                      branch[1] += second_tree(u, s, Z, &head, US);
                    }
                    branch[0]++;
                  }
                }
              }//closes loop 6
            }//closes loop 5
          }//closes loop 4
        }//closes loop 3
      }//closes loop 2
    }//closes loop 1
  }//closes loop 0
  printResults(&head, n);
  endResults(n);
  printf("\n %i, %i", branch[0], branch[1]);
}

