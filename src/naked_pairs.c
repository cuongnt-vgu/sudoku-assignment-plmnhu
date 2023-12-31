/*
#include "naked_pairs.h"

int naked_pairs(SudokuBoard *p_board)
{
    return 0;
}
*/
#include "naked_pairs.h"
#include <stdio.h>
#include <stdlib.h>

int naked_pairs(SudokuBoard *p_board)
{
   cas_naked_pairs cas[100];
   int n_cas,n;
   n=num_cas(p_board, cas , &n_cas);
   for (int i=1; i<=n_cas ; i++)
         printf(" %d  %d  %d  %d  %d  %d\n", cas[i].row1, cas[i].col1, cas[i].row2, cas[i].col2, cas[i].cas1, cas[i].cas2);
    xuly_naked_pair(p_board, cas,n_cas);  
    return n_cas;
}
int pair_2cell(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int *cas1, int *cas2)
{
    int count=0;
    int cas[2];
    
    if((p_board->data[row1][col1].num_candidates==2) && (p_board->data[row2][col2].num_candidates==2) )
    {
       if ((row1==row2)||(col1==col2) || 
            (p_board->data[row1][col1].box_index==p_board->data[row2][col2].box_index)   )
        {
           for (int i=0;i<9;i++)
                  if ((p_board->data[row1][col1].candidates[i]==1) && (p_board->data[row2][col2].candidates[i]==1))
                  {
                    cas[count] = i;
                    count++;
                  }
        }
    }
    *cas1 = cas[0];
    *cas2 = cas[1];
    
    return count;
}

int num_cas(SudokuBoard *p_board, cas_naked_pairs cas[],int *n_cas)
{
    int cas1=-1,cas2=-1;
    int r1,c1,r2,c2;
    int count=0;
      
    for (int i=0;i<80;i++)
        for(int j=i+1;j<81;j++)
        {
            r1 = i/9;  c1 = i%9; r2=j/9;  c2 = j%9;
          
            if (pair_2cell(p_board,r1,c1,r2,c2,&cas1, &cas2 )==2)
               {
                count++;
                cas[count].row1 = r1;
                cas[count].col1 = c1;
                cas[count].row2 = r2;
                cas[count].col2 = c2;
                cas[count].cas1 = cas1;
                cas[count].cas2 = cas2;
                }
              
        }
    *n_cas = count;
    return count;
}

void xuly_naked_pair(SudokuBoard *p_board, cas_naked_pairs cas[],int n_cas)
{
    int r1,c1,r2,c2,cas1,cas2;
    int r1_dau,c1_dau,r2_dau,c2_dau;
    int i,j,k;
    for (i=1; i<=n_cas;i++)
    {
        r1 = cas[i].row1;c1=cas[i].col1;
        r2=cas[i].row2; c2= cas[i].col2;
        cas1=cas[i].cas1; cas2 = cas[i].cas2;
        r1_dau=(r1/3)*3; c1_dau = (c1/3)*3;
        r2_dau = (r2/3)*3; c2_dau = (c2/3)*3;
        // xu ly dongcot
        if(r1==r2)
        {
            for(j=0;j<BOARD_SIZE;j++)
            {
                
                if((j!=c1) && (j!=c2))
                {
                    if(p_board->data[r1][j].candidates[cas1]==1)
                    {
                        p_board->data[r1][j].candidates[cas1]=0;
                        p_board->data[r1][j].num_candidates--;
                    }
                    if(p_board->data[r1][j].candidates[cas2]==1)
                    {
                        p_board->data[r1][j].candidates[cas2]=0;
                        p_board->data[r1][j].num_candidates--;
                    }
                }
            }
        }
    
        if(c1==c2) // xu ly dong
        {
            for(j=0;j<BOARD_SIZE;j++)
            {
                if((j!=r1) && (j!=r2))
                {
                    if(p_board->data[j][c1].candidates[cas1]==1)
                    {
                        p_board->data[j][c1].candidates[cas1]=0;
                        p_board->data[j][c1].num_candidates--;
                    }
                    if(p_board->data[j][c2].candidates[cas2]==1)
                    {
                        p_board->data[j][c2].candidates[cas2]=0;
                        p_board->data[j][c2].num_candidates--;
                    }
                }
            }
        }
         if(p_board->data[r1][c1].box_index==p_board->data[r2][c2].box_index) // xu ly kho
        {
            for(j=r1_dau;j<r1_dau+3;j++)
                for(k=c1_dau;k<c1_dau+3;k++)
                {
                    if(  ((j!=r1) || (k!=c1))   && ((j!=r2) || (k!=c2)))
                    {
                        if(p_board->data[j][k].candidates[cas1]==1)
                        {
                            p_board->data[j][k].candidates[cas1]=0;
                            p_board->data[j][k].num_candidates--;
                        }
                        if(p_board->data[j][k].candidates[cas2]==1)
                        {
                            p_board->data[j][k].candidates[cas2]=0;
                            p_board->data[j][k].num_candidates--;
                        }
                    }
                }
        }
    }
}
