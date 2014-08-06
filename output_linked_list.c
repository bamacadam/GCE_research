//
//  output_linked_list.c
//  Comp2x2Search
//
//  Created by Ben MacAdam on 7/22/14.
//  Copyright (c) 2014 Ben MacAdam. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *This is the node data structure, which we use as a stack.
 *It holds the u,v,s,t vectors as int[7], and the v,t parities
 *as int[128][128].
 */
struct node
{
  int u[7];
  int v[7];
  int s[7];
  int t[7];
  unsigned short int matrix[128][128];
  struct node *next;
};

/*
 *This is the push function, which pushes the newest solution to the top of
 *the stack.
 *Input:  u,v,s,t: the array of vectors
 *        matrix: the array of solution parities
 */
void push(int u[7], int v[7], int s[7], int t[7],
          unsigned short int matrix[128][128], struct node **head)
{
    //Declare variables
  struct node *hold;
  hold = malloc(sizeof(struct node));
  int i,j;
    //Fill struct values
  for (i=0; i<7; i++)
  {
    hold->u[i] = u[i];
    hold->s[i] = s[i];
    hold->v[i] = v[i];
    hold->t[i] = t[i];
  }
  for (i=0; i<128; i++) {
    for (j=0; j<128; j++) {
      hold->matrix[i][j] = matrix[i][j];
    }
  }
    //push struct to head
  hold->next = *head;
  *head = hold;
}

/*
 *This is the printResults function, which is essentially a
 *pop function for the stack which prints the node values to a JSON
 *file before freeing the node.
 */
void printResults(struct node **head, int branch)
{
    //Declare variables
  int i,j;
  struct node *next = NULL;
  static char name[30];
  sprintf(name, "math_results_%i.json", branch);
    //comma is for formatting, to keep the file in JSON format
  static char comma[7] = {',', ',', ',', ',', ',', ',', ' '};
    //Open the file
  FILE *results;
  results = fopen(name, "a+");
  while (*head != NULL)
  {   //iterate through the linked list
    next = (*head)->next;
      //print results in head
      //This begins the JSON object, and
    fprintf(results, "{\"u\": [");
    for (i = 0; i < 7; i++)
    { //print the integer, and comma(if it's not the last entry)
      fprintf(results, "%i%c", (*head)->u[i], comma[i]);
    }
    fprintf(results, "],\"v\": [");
    for (i = 0; i < 7; i++)
    {
      fprintf(results, "%i%c", (*head)->v[i], comma[i]);
    }
    fprintf(results, "],\"s\": [");
    for (i = 0; i < 7; i++)
    {
      fprintf(results, "%i%c", (*head)->s[i], comma[i]);
    }
    fprintf(results, "],\"t\": [");
    for (i = 0; i < 7; i++)
    {
      fprintf(results, "%i%c", (*head)->t[i], comma[i]);
    }
    fprintf(results, "],\"parities\": [");
      //Now all (i,j) entries of the solution matrix equal to 1 are printed
    for (i = 0; i < 128; i++)
    {
      for (j = 0; j < 128; j++)
      {
        if ((*head)->matrix[i][j])
        {
          fprintf(results, "[%i,%i],",i,j);
        }
      }
    }
    fprintf(results, "[512,512]]},"); //JSON formatting
                                      //free head
    free(*head);
    *head = next; //set head as the next entry in the linked list
  }
    //close the file
  fclose(results);
}

/*
 *This function overwrites the previous JSON file and handles formatting.
 */
void initResults(int branch)
{
  FILE *results;
  char name[30];
  sprintf(name, "math_results_%i.json", branch);
  results = fopen(name, "w+");
  fprintf(results, "[");
  fclose(results);
}
/*
 *This function ends the JSON file so it is in the correct format
 */
void endResults(int branch)
{
  FILE *results;
  char name[30];
  sprintf(name, "math_results_%i.json", branch);
  results = fopen(name, "a+");
  fprintf(results, "{}]");
  fclose(results);
  
}

