#include "naked_triples.h"

#include <stdio.h>
#include <stdlib.h>
int naked_triples(SudokuBoard *p_board)
{
  // p_board->data[0][4].candidates[7]=0;
  //  p_board->data[0][4].candidates[5]=1;
   // cas_naked_triples cas[100];
   int cas1=-1,cas2=-1,cas3=-1;
    int r1,c1,r2,c2,r3,c3;
    int count=0;
    r1 = 0;  c1 = 3;  r2=0;  c2 = 6; r3=0 ; c3 =4;
    // r1 = 0;  c1 = 8; r2=1;  c2 = c1; r3=2 ; c3 =c1;
   // r1 = 0;  c1 = 4; r2=2;  c2 = 3 ; r3=0 ; c3 =4;
    count= pair_3cell(p_board,r1,c1,r2,c2,r3,c3,&cas1, &cas2,&cas3 );
    printf(" %d  %d  %d  %d  %d  %d  %d  %d  %d\n", r1,c1,r2,c2,r3,c3, cas1, cas2,cas3);
   //int n_cas,n;
  // n=num_cas3(p_board, cas , &n_cas);

 //  for (int i=1; i<=n_cas ; i++)
 //        printf(" %d  %d  %d  %d  %d  %d  %d  %d  %d \n", cas[i].row1, cas[i].col1, cas[i].row2, cas[i].col2, cas[i].row3,cas[i].col3, cas[i].cas1, cas[i].cas2, cas[i].cas3);
   // xuly_naked_triples(p_board, cas,n_cas); 
   
    return 0;
}
int pair_3cell(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int row3,int col3,int *cas1, int *cas2,int *cas3)
{
    //int count=0;
 //   int n_cas=0;
    int cas[]={-1,-1,-1,-1,-1};
    int n_cas1 = p_board->data[row1][col1].num_candidates;
    int n_cas2 = p_board->data[row2][col2].num_candidates;
    int n_cas3 = p_board->data[row3][col3].num_candidates;
    
    

 //   int rd1=(row1/3)*3 , cd1=(col1/3)*3, rd2=(row2/3)*3;
 //   int cd2=(col2/3)*3 , rd3=(row3/3)*3 , cd3=(col3/3)*3;
    
    if((n_cas1==1) || (n_cas2==1) || (n_cas3==1))
        return 0;
    if((n_cas1>3) || (n_cas2>3) || (n_cas3>3))
        return 0;
   
    int n_cas=0;
    for (int i=0; i<9 ; i++) //ghi chu i
        {
            if((p_board->data[row1][col1].candidates[i]==1) || (p_board->data[row2][col2].candidates[i]==1) 
                    || (p_board->data[row3][col3].candidates[i]==1))
            {
                n_cas++;
                cas[n_cas]=i;
            }
        }
        if (n_cas!=3) 
            return 0;
    
    *cas1 = cas[1];
    *cas2 = cas[2];
    *cas3 = cas[3];
    //tren cung mot dong
/* 
    if ((row1==row2) && (row2==row3))
    {
        printf("11111.  da vao day");
        for(int j=0;j<BOARD_SIZE;j++)//duyet qua cac cot
        {
            if ((j!=col1) && (j!=col2) && (j!=col3) )
            {
                if( (p_board->data[row1][j].candidates[cas[1]]==1 ) || (p_board->data[row1][j].candidates[cas[2]]==1 )
                        ||(p_board->data[row1][j].candidates[cas[3]]==1 ))
                        return 0;
            }
              
        }
        return 1;
    }

*/
 /*  
    //tren cung mot cot
    if ((col1==col2) && (col2==col3))
    {
        for(int j=0;j<BOARD_SIZE;j++)//duyet qua cac dong
        {
            if ((j!=row1) && (j!=row2) && (j!=row3) )
            {
                if( (p_board->data[j][col1].candidates[cas[1]]==1 ) || (p_board->data[j][col1].candidates[cas[2]]==1 )
                        ||(p_board->data[j][col1].candidates[cas[3]]==1 ))
                        return 0;
            }
              
        }
        return 1;
    }   
*/
/*  
    ////tren cung mot khoi   
    if ((rd1==rd2) && (rd2==rd3)&&(cd1==cd2) && (cd2==cd3))
    {
        for(j=rd1;j<rd1+3;j++)   //duyet qua cac cell
        for(int k=cd1;k<cd1+3;k++)
        {
            if ( ((j==row1) && (k==col1)) || ((j==row2) && (k==col2)) || ((j==row3) && (k==col3)) )
            {
                if( (p_board->data[j][k].candidates[cas[1]]==1 ) || (p_board->data[j][k].candidates[cas[2]]==1 )
                        ||(p_board->data[j][k].candidates[cas[3]]==1 ))
                        return 0;
            }
              
        }
    }   
*/
    
    return 1;

                
}

int num_cas3(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas)
{
    int cas1=-1,cas2=-1,cas3=-1;
    int r1,c1,r2,c2,r3,c3;
    int count=0;
    //r1 = 0;  c1 = 3;  r2=0;  c2 = 4; r3=0 ; c3 =5;
     r1 = 0;  c1 = 8; r2=1;  c2 = c1; r3=2 ; c3 =c1;
    //r1 = 0;  c1 = 3; r2=2;  c2 = 4; r3=1 ; c3 =8;
    count= pair_3cell(p_board,r1,c1,r2,c2,r3,c3,&cas1, &cas2,&cas3 );
    printf(" %d  %d  %d  %d  %d  %d  %d  %d  %d\n", r1,c1,r2,c2,r3,c3, cas1, cas2,cas3);
    return count;
/*    for (int i=0;i<79;i++)
        for(int j=i+1;j<80;j++)
            for (int k=j+1;k<81;k++)
        {
            r1 = i/9;  c1 = i%9; r2=j/9;  c2 = j%9; r3=k/9 ; c3 =k%9;
          
            if (pair_3cell(p_board,r1,c1,r2,c2,r3,c3,&cas1, &cas2,&cas3 )==3)
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
                cas[count].cas3 = cas3;
               // printf(" %d  %d  %d  %d  %d  %d\n", r1,c1,r2,c2, cas1, cas2);

               }
              
        }
    *n_cas = count;
    return count;
*/
}


void xuly_naked_triples(SudokuBoard *p_board, cas_naked_triples cas[],int n_cas)
{
    int r1,c1,r2,c2,r3,c3,cas1,cas2,cas3;
  //  int r1_dau,c1_dau,r2_dau,c2_dau;
    int i,j;
    
    for (i=1; i<=n_cas;i++)
    {
        r1 = cas[i].row1;c1=cas[i].col1;
        r2=cas[i].row2; c2= cas[i].col2;
        r3=cas[i].row3; c3= cas[i].col3;
        cas1=cas[i].cas1; cas2 = cas[i].cas2;cas3 = cas[i].cas3;
        printf("=========cac cas  %d  %d %d  \n",cas1, cas2,cas3);
        for (j=0;j<BOARD_SIZE;j++) // 
        {
            if( (j!=cas1) && (j!=cas2) && (j!=cas3)  )
            {
                if(p_board->data[r1][c1].candidates[j]==1)
                    {
                        p_board->data[r1][c1].candidates[j]=0;
                        p_board->data[r1][c1].num_candidates--;
                        printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                if(p_board->data[r2][c2].candidates[j]==1)
                    {
                        p_board->data[r2][c2].candidates[j]=0;
                        p_board->data[r2][c2].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,j,cas2);
                    }                   
                 if(p_board->data[r3][c3].candidates[j]==1)
                    {
                        p_board->data[r3][c3].candidates[j]=0;
                        p_board->data[r3][c3].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,j,cas2);
                    }                                      
            }
        }
        

    }
}
