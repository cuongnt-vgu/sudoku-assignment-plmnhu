#include "hidden_pairs.h"
#include <stdio.h>
#include <stdlib.h>
int hidden_pairs(SudokuBoard *p_board)
{
    
    
    int count = 0, countk;
    int foundk[10];
    int l=0;
    int i,j,candidate,k;
    int found[]={0,0,0,0,0,0,0,0,0};

    
    
    for ( i = 0; i < 9; i++) 
    {
        for (j = 0; j < 9; j++) 
        {
            if (p_board->data[i][j].num_candidates > 2) 
            {
                for ( l = 0; l < 9; l++) 
                    {
                    found[l]=0;
                    foundk[l]=0;
                    }
                for ( k = 0; k < 9; k++) 
                {
                    candidate = p_board->data[i][j].candidates[k];
                    if (candidate !=0)
                    {
                                      
                        for (l = 0; l < 9; l++) 
                            if ((l != j) &&
                                (p_board->data[i][l].candidates[k]>0)) 
                            {
                                found[k]++;
                                if (found[k]>1)
                                {
                                    //printf ("tim thay tren dong %d  %d %d  \n", k,  i, j);
                                    break;
                                }
                            }
                        if (found[k]>1)
                        {
                            found[k] = 0;
                            for (l = 0; l < 9; l++) 
                                if ((l != i) &&
                                    (p_board->data[l][j].candidates[k]>0)) 
                                {
                                    found[k]++;
                                    if (found[k]>1)
                                    {    
                                        //printf (" tim thay tren cot %d  %d %d  \n", k , l,j);
                                        break;
                                    }
                                }
                            if (found[k]>1)
                            {
                                found[k] = 0;                            
                                int box = (i / 3) * 3 + j / 3;
                                int box_cell = (i % 3) * 3 + j % 3;
                                for (l = 0; l < 9; l++) 
                                {
                                    Cell cell=*p_board->p_boxes[box][l] ;
                                    
                                    if ((l != box_cell) &&
                                        (cell.candidates[k]>0)) 
                                    {
                                        found[k]++;
                                        if(found[k]>1)
                                        {
                                            //printf ("tim thay tren box   %d %d  %d \n", k, box , box_cell);
                                            break;
                                        }
                                    }
                                }
                            } // if (found[k]>1)
                        } // if (found[k]>1)
                    } // if (candidate !=0)
                } //for (int k = 0; k < 9; k++) 
                    countk=0;
                    printf("1.---------------- \n");
                    for (l = 0; l < 9; l++) 
                        printf(" %d  ", found[l]);
                    printf("\n %d  %d\n",i,j );
                    for (l = 0; l < 9; l++) 
                        if(found[l]==1)
                           { 
                            countk++;
                            foundk[countk]=l;
                            if(countk>2)
                                break;
                           }
                    printf("2.---------------- \n");
                    
                        printf(" %d %d %d", countk,foundk[1],foundk[2]);
                    printf("\n %d  %d\n",i,j );
                   // int m;                   
                    if (countk==2) 
                    {
                       // printf ("khong tim thay %d  %d  %d \n", k,i,j);
                         //  for ( m=0;m<9;m++)
                           // p_board->data[i][j].candidates[m] = 0;

                        for ( l = 0; l < 9; l++) 
                        {
                            if ((l==foundk[1]) || (l==foundk[2]))
                                p_board->data[i][j].candidates[l] = 2;
                        }
                        //p_board->data[i][j].num_candidates = 5;
                        count++;
                    }
                    printf("3.-----------%d  %d   ", i,j );
                    for ( l = 0; l < 9; l++) 
                        printf("%d ", p_board->data[i][j].candidates[l]);
                    printf("   ----------- \n");


            } // if (p_board->data[i][j].num_candidates > 2) 
        } 
        
    }
    bool find;
    for ( i = 0; i < BOARD_SIZE; i++) 
    {
        for (j = 0; j < BOARD_SIZE; j++) 
        {
            find = false;
            for ( k = 0; k < BOARD_SIZE; k++) 
                if (p_board->data[i][j].candidates[k]==2)
                    {
                        find = true;
                        break;
                    }
            if (find)
                {
                    for ( k = 0; k < BOARD_SIZE; k++) 
                    {
                            if (p_board->data[i][j].candidates[k]==2)
                                p_board->data[i][j].candidates[k]=1;
                            else
                                p_board->data[i][j].candidates[k]=0;
                            
                    }
                    p_board->data[i][j].num_candidates=2;
                }
            
        }
    }
    //p_board->data[0][5].candidates[3]=1;
sosanhhaio(p_board->data[0][1],p_board->data[0][3],&l,found);
    printf("\n ------------%d  %d %d \n", l , found[0], found[1]);
    return count;

}

