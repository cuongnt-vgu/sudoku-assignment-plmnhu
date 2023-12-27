#include "hidden_triples.h"
#include <stdio.h>
#include <stdlib.h>
int hidden_triples(SudokuBoard *p_board)
{
    cas_naked_triples cas[100];
   int n_cas,n;
   n=num_cas3h(p_board, cas , &n_cas);
   for (int i=1; i<=n_cas ; i++)
         printf(" %d  %d  %d  %d  %d  %d  %d  %d  %d \n", cas[i].row1, cas[i].col1, cas[i].row2, cas[i].col2, cas[i].row3,cas[i].col3, cas[i].cas1, cas[i].cas2, cas[i].cas3);
    xuly_naked_triplesh(p_board, cas,n_cas); 
   
    return 1;//n_cas;
}
int pair_3cellh(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int row3,int col3,int *cas1, int *cas2,int *cas3)
{
    int count=0;
    int n_cas=0;
    int cas[4];
    int n_cas1 = p_board->data[row1][col1].num_candidates;
    int n_cas2 = p_board->data[row2][col2].num_candidates;
    int n_cas3 = p_board->data[row3][col3].num_candidates;
    bool trong, ngoai;
    int j;

    int rd1=(row1/3)*3 , cd1=(col1/3)*3, rd2=(row2/3)*3;
    int cd2=(col2/3)*3 , rd3=(row3/3)*3 , cd3=(col3/3)*3;
    if((n_cas1==1) || (n_cas2==1) || (n_cas3==1))
        return 0;

    //tren cung mot dong
    if ((row1==row2) && (row2==row3))
        {
            
            for (int i=0; i<9 ; i++) //ghi chu i
            {
                trong= false;
                ngoai = false;
                for ( j=0;j<9;j++) //cot j
                {
                    n_cas= p_board->data[row1][j].num_candidates;
                    
                    if ((j!=col1) && (j!=col2) && (j!=col3) )
                    {
                        if ( p_board->data[row1][j].candidates[i]==1)
                            ngoai=true;
                    }
                    if ((j==col1) || (j==col2) || (j==col3) )
                    {
                        if (p_board->data[row1][j].candidates[i]==1)
                            trong=true;

                    }

                }
                if((trong) && (!ngoai))
                {
                    cas[count]=i;
                    count++;
                    
                }
            }
        }
    
    if(count==3)
    {
        *cas1 = cas[0];
        *cas2 = cas[1];
        *cas3 = cas[2];
        return count;
    }
    //tren cung mot cot 
    count=0;
    if ((col1==col2) && (col2==col3))
        {
            
            for (int i=0; i<9 ; i++) //ghi chu i
            {
                trong= false;
                ngoai = false;
                for ( j=0;j<9;j++) //dong j
                {
                    n_cas= p_board->data[j][col1].num_candidates;
                    
                    if ((j!=row1) && (j!=row2) && (j!=row3) )
                    {
                        if ( p_board->data[j][col1].candidates[i]==1)
                            ngoai=true;
                    }
                    if ((j==row1) || (j==row2) || (j==row3) )
                    {
                        if (p_board->data[j][col1].candidates[i]==1)
                            trong=true;

                    }

                }
                if((trong) && (!ngoai))
                {
                    cas[count]=i;
                    count++;
                    
                }
            }
        }
    if(count==3)
    {
        *cas1 = cas[0];
        *cas2 = cas[1];
        *cas3 = cas[2];
        return count;
    }
   
 
//tren cung mot khoi
   

    count=0;
    if ((rd1==rd2) && (rd2==rd3)&&(cd1==cd2) && (cd2==cd3))
        {
            //printf("------------vao khoi roi \n");
            for (int i=0; i<9 ; i++) //ghi chu i
            {
                trong= false;
                ngoai = false;
                for ( j=rd1;j< rd1+3;j++) //dong j
                for (int k=cd1 ;k< cd1+3 ; k++) // cot k
                {
                    n_cas= p_board->data[j][k].num_candidates;
                    
                    
                    if ( ((j==row1) && (k==col1)) || ((j==row2) && (k==col2)) || ((j==row3) && (k==col3)) )
                    {
                        if (p_board->data[j][k].candidates[i]==1)
                            trong=true;

                    }
                    else
                    {
                        if (p_board->data[j][k].candidates[i]==1)
                            ngoai=true;
                    }


                }
                if((trong) && (!ngoai))
                {
                    cas[count]=i;
                    count++;
                    
                }
            }
        }
    if(count==3)
    {
        *cas1 = cas[0];
        *cas2 = cas[1];
        *cas3 = cas[2];
        return count;
    }


    
    return count;
}

int num_cas3h(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas)
{
    int cas1=-1,cas2=-1,cas3=-1;
    int r1,c1,r2,c2,r3,c3;
    int count=0;
      
    for (int i=0;i<79;i++)
        for(int j=i+1;j<80;j++)
            for (int k=j+1;k<81;k++)
        {
            r1 = i/9;  c1 = i%9; r2=j/9;  c2 = j%9; r3=k/9 ; c3 =k%9;
          
            if (pair_3cellh(p_board,r1,c1,r2,c2,r3,c3,&cas1, &cas2,&cas3 )==3)
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
}


void xuly_naked_triplesh(SudokuBoard *p_board, cas_naked_triples cas[],int n_cas)
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