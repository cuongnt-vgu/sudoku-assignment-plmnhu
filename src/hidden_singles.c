#include "hidden_singles.h"
#include <stdio.h>
#include <stdlib.h>
int hidden_singles(SudokuBoard *p_board)
{
    
    int count = 0;
    int l=0;
    int i,j,candidate;
    bool found;
    for ( i = 0; i < 9; i++) 
    {
        for (j = 0; j < 9; j++) 
        {
            if (p_board->data[i][j].num_candidates > 1) 
            {
                for (int k = 0; k < 9; k++) 
                {
                     candidate = p_board->data[i][j].candidates[k];
                    
                    found = true;
                    if (candidate !=0)
                    {
                     
                    found = false;
                    
                    for (l = 0; l < 9; l++) 
                        if ((l != j) &&
                            (p_board->data[i][l].candidates[k]>0)) 
                        {
                            found = true;
                         //   printf ("tim thay tren dong %d  %d %d  \n", k,  i, j);
                            break;

                        }
                    if (found)
                    {
                    found = false;
                    for (l = 0; l < 9; l++) 
                        if ((l != i) &&
                            (p_board->data[l][j].candidates[k]>0)) 
                        {
                            found = true;
                          //  printf (" tim thay tren cot %d  %d %d  \n", k , l,j);
                            break;
                        }
                    if (found)
                    {
                    found = false;                            
                    int box = (i / 3) * 3 + j / 3;
                    int box_cell = (i % 3) * 3 + j % 3;
                    for (l = 0; l < 9; l++) 
                    {
                        Cell cell=*p_board->p_boxes[box][l] ;
                        
                        if ((l != box_cell) &&
                            (cell.candidates[k]>0)) 
                        {
                            found = true;
                           // printf ("tim thay tren box   %d %d  %d \n", k, box , box_cell);
                            break;
                        }
                    }
                    }
                    }
                   // int m;                   
                    if (!found) 
                    {
                       // printf ("khong tim thay %d  %d  %d \n", k,i,j);
                        //   for ( m=0;m<9;m++)
                          //  p_board->data[i][j].candidates[m] = 0;

                        p_board->data[i][j].candidates[k] = 1;
                        p_board->data[i][j].value = k+1;
                        p_board->data[i][j].num_candidates = 1;
                    //    p_board->data[i][j].candidates[0] = candidate;
                      //  p_board->data[i][j].fixed = true;
                        count++;
                        break;
                    }
                } //for (int k = 0; k < 9; k++) 
            }
        }
        }
    }
    for ( i = 0; i < BOARD_SIZE; i++) 
    {
        for (j = 0; j < BOARD_SIZE; j++) 
        {
            if (p_board->data[i][j].num_candidates==1) 
            {
                for (int k = 0; k < BOARD_SIZE; k++) 
                {
                    if (k!= p_board->data[i][j].value-1)
                      p_board->data[i][j].candidates[k]=0;
                }
            }
        }
    }
    /*
    i=1;//for ( i = 0; i < 1; i++) 
    {
        j=0;//for (j = 5; j < 6; j++) 
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
    */

    return count;
}
    

int hidden_single2(SudokuBoard *p_board)
{
    int count = 0;
   // int l=0;
    int i,j;
   
    i=1;//for ( i = 0; i < 1; i++) 
    {
        j=0;//for (j = 5; j < 6; j++) 
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
    /*
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
            
            
        
    */   
    return count;
}


