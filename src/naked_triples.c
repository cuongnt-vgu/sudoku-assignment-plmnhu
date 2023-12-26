#include "naked_triples.h"

#include <stdio.h>
#include <stdlib.h>
int naked_triples(SudokuBoard *p_board)
{
   
   cas_naked_triples cas[100];
   int n_cas,n;
   n=num_cas(p_board, cas , &n_cas);
   for (int i=1; i<=n_cas ; i++)
         printf(" %d  %d  %d  %d  %d  %d\n", cas[i].row1, cas[i].col1, cas[i].row2, cas[i].col2, cas[i].cas1, cas[i].cas2);
   // xuly_naked_triples(p_board, cas,n_cas);  
    return n_cas;
}
int pair_3cell(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int row3,int col3,int *cas1, int *cas2,int *cas3)
{
    int count=0;
    int cas[4];
    int n_cas1 = p_board->data[row1][col1].num_candidates;
    int n_cas2 = p_board->data[row2][col2].num_candidates;
    int n_cas3 = p_board->data[row3][col3].num_candidates
    int rd1=(row1/3)*3 , cd1=(col1/3)*3, rd2=(row2/3)*3 , cd2=(col2/3)*3,rd3=(row3/3)*3 , cd3=(col3/3)*3,
    if((n_cas1==1) || (n_cas2==) || (n_cas3==1))
        return 0;
    if((n_cas1<4) && (n_cas2<4) && (n_cas3<4))
    {
       if(  ((row1==row2) && (row2==row3)) || ((col1==col2)&&(col2==col3))  || 
             ( (rd1==rd2) && (rd2==rd3) && (cd1==cd2) && (cd2==cd3)     )   )

       {
           for (int i=0;i<9;i++)
           
               if ((p_board->data[row1][col1].candidates[i]==1) || (p_board->data[row2][col2].candidates[i]==1) 
                    || (p_board->data[row3][col3].candidates[i]==1))
                  {
                    cas[count] = i;
                    count++;
                    if (count>3)
                        return 0;
                  }
        }
    }
    *cas1 = cas[0];
    *cas2 = cas[1];
    *cas3 = cas[2];
    
    return count;
}

int num_cas(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas)
{
    int cas1=-1,cas2=-1,cas2=-1;
    int r1,c1,r2,c2,r3,c3;
    int count=0;
      
    for (int i=0;i<79;i++)
        for(int j=i+1;j<80;j++)
            for (k=j+1;k<81;k++)
        {
            r1 = i/9;  c1 = i%9; r2=j/9;  c2 = j%9; r3=k/9 ; c3 =k%9;
          
            if (pair_3cell(p_board,r1,c1,r2,c2,r3,c3,&cas1, &cas2,&cas3 )==2)
               {
                count++;
                cas[count].row1 = r1;
                cas[count].col1 = c1;
                cas[count].row2 = r2;
                cas[count].col2 = c2;
                cas[count].row3 = r3;
                cas[count].col3 = c3;
                cas[count].cas1 = cas1;
                cas[count].cas2 = cas2;
                cas[count].cas2 = cas2;
               // printf(" %d  %d  %d  %d  %d  %d\n", r1,c1,r2,c2, cas1, cas2);

               }
              
        }
    *n_cas = count;
    return count;
}

/*
void xuly_naked_triples(SudokuBoard *p_board, cas_naked_pairs cas[],int n_cas)
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
        printf("xu ly  %d  %d  %d  %d  %d  %d \n", r1,c1,r2,c2, cas1, cas2);
        printf("xu ly  %d  %d  %d  %d   \n", r1_dau,c1_dau,r2_dau,c2_dau);
        // xu ly dongcot
        if(r1==r2)
        {
            printf("xu ly cot  %d  %d   \n",i, r1);
            for(j=0;j<BOARD_SIZE;j++)
            {
                
                if((j!=c1) && (j!=c2))
                {
                    if(p_board->data[r1][j].candidates[cas1]==1)
                    {
                        p_board->data[r1][j].candidates[cas1]=0;
                        p_board->data[r1][j].num_candidates--;
                        printf("xu ly cot %d  %d %d  \n",r1,j,cas2);
                    }
                    if(p_board->data[r1][j].candidates[cas2]==1)
                    {
                        p_board->data[r1][j].candidates[cas2]=0;
                        p_board->data[r1][j].num_candidates--;
                        printf("xu ly cot %d  %d %d  \n",r1,j,cas2);
                    }
                }

            }
        }
    
        if(c1==c2) // xu ly dong
        {
            printf("xu ly dong  %d  %d   \n",i, c1);
            for(j=0;j<BOARD_SIZE;j++)
            {
                if((j!=r1) && (j!=r2))
                {
                    if(p_board->data[j][c1].candidates[cas1]==1)
                    {
                        p_board->data[j][c1].candidates[cas1]=0;
                        p_board->data[j][c1].num_candidates--;
                        printf("xu ly dong %d  %d %d  \n",j,c1,cas1);
                    }
                    if(p_board->data[j][c2].candidates[cas2]==1)
                    {
                        p_board->data[j][c2].candidates[cas2]=0;
                        p_board->data[j][c2].num_candidates--;
                        printf("xu ly dong %d  %d %d  \n",j,c1,cas2);
                    }
                }

            }
        }
        
        if((r1_dau==r2_dau) && (c1_dau==c2_dau)) // xu ly khoi
        {
            printf("xu ly khoi  %d  %d   \n",r1_dau, c1_dau);
            for(j=r1_dau;j<r1_dau+3;j++)
                for(k=c1_dau;k<c1_dau+3;k++)
                {
                    if(  ((j!=r1) || (k!=c1))   && ((j!=r2) || (k!=c2)))
                    {
                        printf("xu ly khoi dong = %d  cot = %d  \n",j,k);
                        if(p_board->data[j][k].candidates[cas1]==1)
                        {
                            p_board->data[j][k].candidates[cas1]=0;
                            p_board->data[j][k].num_candidates--;
                            printf("xu ly khoi %d  %d %d  \n",j,k,cas1);
                        }
                        if(p_board->data[j][k].candidates[cas2]==1)
                        {
                            p_board->data[j][k].candidates[cas2]=0;
                            p_board->data[j][k].num_candidates--;
                            printf("xu ly khoi %d  %d %d  \n",j,k,cas2);
                        }
                    }

                }
        }

    }
}
*/