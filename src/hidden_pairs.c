#include "hidden_pairs.h"

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
                for ( k = 0; k < 9; k++) 
                    {
                    found[k]=0;
                    foundk[k]=0;
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
                                printf ("tim thay tren dong %d  %d %d  \n", k,  i, j);
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
                                printf (" tim thay tren cot %d  %d %d  \n", k , l,j);
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
                                printf ("tim thay tren box   %d %d  %d \n", k, box , box_cell);
                                break;
                            }
                        }
                    }
                    }
            }
                    countk=0;
                    for (l = 0; l < 9; l++) 
                        printf("%d  ", found[k])
                    printf("\n");
                    for (l = 0; l < 9; l++) 
                        if(found[l]==1)
                           { 
                            countk++;
                            foundk[countk]=k;
                            if(countk>2)
                                break;
                           }

                   // int m;                   
                    if (countk==2) 
                    {
                       // printf ("khong tim thay %d  %d  %d \n", k,i,j);
                        //   for ( m=0;m<9;m++)
                          //  p_board->data[i][j].candidates[m] = 0;

                        for ( k = 0; k < 9; k++) 
                        {
                            if ((k!=foundk[1]) && (k!=foundk[2]))
                                p_board->data[i][j].candidates[k] = 0;
                        }
                        p_board->data[i][j].num_candidates = 2;
                        count++;
                    }
                } //for (int k = 0; k < 9; k++) 
            }
        }
        }
    }


    return count;

}

