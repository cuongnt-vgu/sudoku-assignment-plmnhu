#include "hidden_singles.h"
#include <stdio.h>
#include <stdlib.h>


int hidden_singles(SudokuBoard *p_board)
{
    
    int count = 0;
    int l=0;
    int i,j,candidate;
    bool found;
    for ( i = 0; i < 1; i++) 
    {
        for (j = 0; j < 1; j++) 
        {
            if (p_board->data[i][j].num_candidates > 1) 
            {
                for (int k = 0; k < 9; k++) 
                {
                     candidate = p_board->data[i][j].candidates[k];
                     printf ("%d \n", candidate);
                    found = true;
                    if (candidate !=0)
                    {
                     printf ("%d \n", k);
                     found = false;
                    
                    for (l = 0; l < 9; l++) 
                    
                        if ((l != j) &&
                            (p_board->data[i][l].num_candidates > 1) &&
                            (p_board->data[i][l].fixed == false) &&
                            (p_board->data[i][l].candidates[k]>0)) 
                        {
                            found = true;
                            //printf ("%d  %d %d  %d \n", k, candidate, i,l);
                            break;

                        }
                    for (l = 0; l < 9; l++) 
                        if ((l != i) &&
                            (p_board->data[l][j].num_candidates > 1) &&
                            (p_board->data[l][j].fixed == false) &&
                            (p_board->data[l][j].candidates[k]>0)) 
                        {
                            found = true;
                            //printf ("%d  %d %d  %d \n", k, candidate, l,j);
                            break;
                        }
                
  /*              
                     for (l = 0; l < 9; l++) 
                    {
                        int box_row = (i / 3) * 3 + j / 3;
                        int box_col = (i % 3) * 3 + j % 3;
                        if ((box_row != i) && (box_col != j) &&
                            (p_board->data[box_row][box_col].num_candidates > 1) &&
                            (p_board->data[box_row][box_col].fixed == false) &&
                            (p_board->data[box_row][box_col].candidates[k]>0)) 
                        {
                            found = true;
                            //printf ("%d  %d %d  %d \n", k, candidate, box_row, box_col);
                            break;
                        }

                    }
                     
                   
     */          
                    } //if (candidate !=0)
                
                   // printf ("%d  %d %d  %d \n", k, candidate, i,l);
                   // printf ("%d  %d %d  %d \n", k, candidate,l,j);
                    if (!found) 
                    {
                        p_board->data[i][j].value = candidate;
                        p_board->data[i][j].num_candidates = 1;
                    //    p_board->data[i][j].candidates[0] = candidate;
                        p_board->data[i][j].fixed = true;
                        count++;
                        break;
                    }
                } //for (int k = 0; k < 9; k++) 
            }
        }
    }
    return count;
}
int hidden_singles2(SudokuBoard *p_board)
{
    int count = 0;
   // int l=0;
    int i,j;
   
    for ( i = 0; i < 1; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
             for (int k = 0; k < 9; k++) 
                {
                     printf("%d  ", p_board->data[i][j].candidates[k]);
                }
                printf("\n");
            printf("%d  %d  %d  ", p_board->data[i][j].row_index,p_board->data[i][j].col_index , p_board->data[i][j].box_index);
            printf("%d  %d  %d  \n", p_board->data[i][j].num_candidates,p_board->data[i][j].value, p_board->data[i][j].fixed );
            
            
        }
    }
printf("\n");
    Cell cell=  *p_board->p_boxes[3][2] ;
    
    //Cell cell=  *p_board->p_boxes[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] ;
    
                           

    
             for (int k = 0; k < 9; k++) 
                {
                     printf("%d  ", cell.candidates[k]);
                }
                printf("\n");
          //  printf("%d  %d  %d  ", p_board->data[i][j].row_index,p_board->data[i][j].col_index , p_board->data[i][j].box_index);
          //  printf("%d  %d  %d  \n", p_board->data[i][j].num_candidates,p_board->data[i][j].value, p_board->data[i][j].fixed );
            
            
        
            
    return count;
}


