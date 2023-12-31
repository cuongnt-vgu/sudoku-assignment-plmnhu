#include "naked_triples.h"

#include <stdio.h>
#include <stdlib.h>
int naked_triples(SudokuBoard *p_board)
{

   cas_naked_triples cas[100];
   int n_cas,n;
   n=num_cas3(p_board, cas , &n_cas);

   for (int i=1; i<=n_cas ; i++)
        printf(" cac truongw hop tim thay    %d  %d  %d  %d  %d  %d  %d  %d  %d \n", cas[i].row1, cas[i].col1, cas[i].row2, cas[i].col2, cas[i].row3,cas[i].col3, cas[i].cas1, cas[i].cas2, cas[i].cas3);
   xuly_naked_triples(p_board, cas,n_cas); 
   
    return n_cas;
}
int Threecellnaker(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int row3,int col3,int *cas1, int *cas2,int *cas3)
{
    int cas[10];
    int n_cas1 = p_board->data[row1][col1].num_candidates;
    int n_cas2 = p_board->data[row2][col2].num_candidates;
    int n_cas3 = p_board->data[row3][col3].num_candidates;
    
    if((n_cas1==1) || (n_cas2==1) || (n_cas3==1))
        return 0;
    if((n_cas1>3) || (n_cas2>3) || (n_cas3>3))
        return 0;
    int n_cas=0;
    // dem so ghi chu trong 3 cell
    for (int i=0; i<9 ; i++) //ghi chu i
        {
            if((p_board->data[row1][col1].candidates[i]==1) || (p_board->data[row2][col2].candidates[i]==1) 
                    || (p_board->data[row3][col3].candidates[i]==1))
            {
                n_cas++;
                cas[n_cas]=i;
                 if (n_cas>3) 
                    return 0;
            }
        }
    *cas1 = cas[1];
    *cas2 = cas[2];
    *cas3 = cas[3];
     if (((row1==row2) && (row2==row3)) || ((col1==col2) && (col2==col3)) || 
        ((p_board->data[row1][col1].box_index==p_board->data[row2][col2].box_index) 
         && (p_board->data[row2][col2].box_index==p_board->data[row3][col3].box_index)))
    {
       
            return 1;
    }
    return 0;
                    
}

int num_cas3(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas)
{
    int cas1=-1,cas2=-1,cas3=-1;
    int r1,c1,r2,c2,r3,c3;
    int count=0;
    for (int i=0;i<79;i++)
        for(int j=i+1;j<80;j++)
            for (int k=j+1;k<81;k++)
        {
            r1 = i/9;  c1 = i%9; r2=j/9;  c2 = j%9; r3=k/9 ; c3 =k%9;
          
            if (Threecellnaker(p_board,r1,c1,r2,c2,r3,c3,&cas1, &cas2,&cas3 )==1)
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
               }
              
        }
    *n_cas = count;
    return count;
}


void xuly_naked_triples(SudokuBoard *p_board, cas_naked_triples cas[],int n_cas)
{
    int r1,c1,r2,c2,r3,c3,cas1,cas2,cas3;
    for (int i=1; i<=n_cas;i++)
    {
        r1 = cas[i].row1;c1=cas[i].col1;
        r2=cas[i].row2; c2= cas[i].col2;
        r3=cas[i].row3; c3= cas[i].col3;
        cas1=cas[i].cas1; cas2 = cas[i].cas2;cas3 = cas[i].cas3;
        printf("=========cac cas %d  %d  %d %d  \n",i,cas1, cas2,cas3);
        if((r1==r2) && (r2==r3))
        {
            for (int j=0;j<BOARD_SIZE;j++) //cot j
            {
                if( (j!=c1) && (j!=c2) && (j!=c3)  )
                {
                    if(p_board->data[r1][j].candidates[cas1]!=0)
                    {
                        p_board->data[r1][j].candidates[cas1]=0;
                        p_board->data[r1][j].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                    if(p_board->data[r1][j].candidates[cas2]!=0)
                    {
                        p_board->data[r1][j].candidates[cas2]=0;
                        p_board->data[r1][j].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                    if(p_board->data[r1][j].candidates[cas3]!=0)
                    {
                        p_board->data[r1][j].candidates[cas3]=0;
                        p_board->data[r1][j].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                }
            }
        }
        if((c1==c2) && (c2==c3))
        {
            for (int j=0;j<BOARD_SIZE;j++) //dong j
            {
                if( (j!=r1) && (j!=r2) && (j!=r3)  )
                {
                    if(p_board->data[j][c1].candidates[cas1]!=0)
                    {
                        p_board->data[j][c1].candidates[cas1]=0;
                        p_board->data[j][c1].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                    if(p_board->data[j][c1].candidates[cas2]!=0)
                    {
                        p_board->data[j][c1].candidates[cas2]=0;
                        p_board->data[j][c1].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                    if(p_board->data[j][c1].candidates[cas3]!=0)
                    {
                        p_board->data[j][c1].candidates[cas3]=0;
                        p_board->data[j][c1].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }

                }
            }
        }        
        int box1, box2, box3;
        box1=p_board->data[r1][c1].box_index;
        box2=p_board->data[r2][c2].box_index;
        box3=p_board->data[r3][c3].box_index;
        if((box1==box2) && (box2==box3))
        {
            for (int j=(r1/3)*3;j<(r1/3)*3+3;j++) //dong j
            for (int k=(c1/3)*3; k<(c1/3)*3+3;k++) // cot k
            {
                if( ((j!=r1) || (k!=c1) ) &&   ((j!=r2) || (k!=c2) ) &&  ((j!=r3) || (k!=c3) ) )
                {
                    if(p_board->data[j][k].candidates[cas1]!=0)
                    {
                        p_board->data[j][k].candidates[cas1]=0;
                        p_board->data[j][k].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                    if(p_board->data[j][k].candidates[cas2]!=0)
                    {
                        p_board->data[j][k].candidates[cas2]=0;
                        p_board->data[j][k].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }
                    if(p_board->data[j][k].candidates[cas3]!=0)
                    {
                        p_board->data[j][k].candidates[cas3]=0;
                        p_board->data[j][k].num_candidates--;
                        //printf("xu ly cot %d  %d %d  \n",r1,c1,cas2);
                    }

                }
            }
        }  
    }   

}
