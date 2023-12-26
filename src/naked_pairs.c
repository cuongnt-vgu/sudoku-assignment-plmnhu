#include "naked_pairs.h"
#include <stdio.h>
#include <stdlib.h>

int naked_pairs(SudokuBoard *p_board)
{
   cas_naked_pairs cas[100];
   int n_cas,n;
   n=num_cas(p_board, cas , &n_cas);
  /*  //int num_cas[100][6];
    int cas1=-1,cas2=-1;
    int r1,c1,r2,c2;
    for (int i=0;i<80;i++)
        for(int j=i+1;j<81;j++)
        {
            r1 = i/9;  c1 = i%9; r2=j/9;  c2 = j%9;
            //   printf(" %d  %d  %d  %d \n", r1,c1,r2,c2);
            if (pair_2cell(p_board,r1,c1,r2,c2,&cas1, &cas2 )==2)
               printf(" %d  %d  %d  %d  %d  %d\n", r1,c1,r2,c2, cas1, cas2);
              //  printf("   %d   \n ",pair_2cell(p_board,r1,c1,r2,c2));
                // printf("   %d   \n ",pair_2cell(p_board,7,7,8,7));
        }
      */            
    return 2;
}
int pair_2cell(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int *cas1, int *cas2)
{
    int count=0;
    int cas[2];
    
    if((p_board->data[row1][col1].num_candidates==2) && (p_board->data[row2][col2].num_candidates==2) )
    {
       if ((row1==row2)||(col1==col2) || (    (((row1/3)*3)==((row2/3)*3))  &&  (((col1/3)*3)==((col2/3)*3))   ))
        {
           for (int i=0;i<9;i++)
           
               if ((p_board->data[row1][col1].candidates[i]==p_board->data[row2][col2].candidates[i]) && (p_board->data[row2][col2].candidates[i]!=0))
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
                printf(" %d  %d  %d  %d  %d  %d\n", r1,c1,r2,c2, cas1, cas2);

               }
              
        }
    *n_cas = count;
    return count;
}

