#include "hidden_triples.h"
#include <stdio.h>
#include <stdlib.h>
int hidden_triples(SudokuBoard *p_board)
{
    int count = 0;   
 
    for (int i=0 ; i<9 ; i++)
        for (int j=0; j<9 ; j++)
            XuLy_Mot_cell3(p_board,i,j,&count);

    
    return count;
}


void  XuLy_Mot_cell3(SudokuBoard *p_board,int row, int col, int *count)
{
   // printf(" ----- %d -----%d-----\n ", row, col);
    if (p_board->data[row][col].num_candidates>1)
    {
        int n=-1,k;
        int nx1[5],nx2[5];
        bool Xuly=false;
        for (int i=0 ; i<7; i++)
            for (int j=i+1 ; j<8 ; j++)
                for (int k=j+1 ; k<9 ; k++)
                    if (( p_board->data[row][col].candidates[i]!=0) &&( p_board->data[row][col].candidates[j]!=0) 
                            && ( p_board->data[row][col].candidates[k]!=0))
                    {
                        n=XuLy_cell_row(p_board,row,col,i,j,k,nx1);
                        if (n>-1)
                        {
                            for(l=0;l<9;l++)
                                if((l!=i) && (l!=j)&& (l!=k))
                                {
                                    if (p_board->data[row][col].candidates[l]!=0)
                                    {
                                        p_board->data[row][col].candidates[l]=0;
                                        p_board->data[row][col].num_candidates--;
                                        Xuly=true;
                                    }
                                    if (p_board->data[row]][nx1[1]].candidates[l]!=0)
                                    {
                                        p_board->data[row][nx1[1]].candidates[l]=0;
                                        p_board->data[row][nx1[1]].num_candidates--;
                                        Xuly=true;
                                    }
                                    if (p_board->data[row]][nx1[2]].candidates[l]!=0)
                                    {
                                        p_board->data[row][nx1[2]].candidates[l]=0;
                                        p_board->data[row][nx1[2]].num_candidates--;
                                        Xuly=true;
                                    }
                                }
                            if(xuly) 
                                *count = *count +1;                           
                        }
                        n=XuLy_cell_col(p_board,row,col,i,j,k,nx1);
                        if (n>-1)
                        {
                            
                            for(l=0;l<9;l++)
                                if((l!=i) && (l!=j)&& (l!=k))
                                {
                                    if (p_board->data[row][col].candidates[l]!=0)
                                    {
                                        p_board->data[row][col].candidates[l]=0;
                                        p_board->data[row][col].num_candidates--;
                                        Xuly=true;
                                    }
                                    if (p_board->data[nx1[1]][col].candidates[l]!=0)
                                    {
                                        p_board->data[nx1[1]][col].candidates[l]=0;
                                        p_board->data[nx1[1]][col].num_candidates--;
                                        Xuly=true;
                                    }
                                    if (p_board->data[nx1[2]][col].candidates[l]!=0)
                                    {
                                        p_board->data[nx1[2]][col].candidates[l]=0;
                                        p_board->data[nx1[2]][col].num_candidates--;
                                        Xuly=true;
                                    }
                                }
                            if(xuly) 
                                *count = *count +1;
                            
                        //printf(" cot -- %d  %d  %d   %d   %d   \n", row,col,i,j,n);
                        // for(k=0;k<9;k++)
                            //   printf("  %d ",p_board->data[row][col].candidates[k]);
                           // printf("\n");
                        }
                            
                        n=XuLy_cell_box(p_board,row,col,i,j,k,nx2);
                        if (n>-1)
                        {
                            for(l=0;l<9;l++)
                                if((l!=i) && (l!=j)&& (l!=k))
                                {
                                    if (p_board->data[row][col].candidates[l]!=0)
                                    {
                                        p_board->data[row][col].candidates[l]=0;
                                        p_board->data[row][col].num_candidates--;
                                        Xuly=true;
                                    }
                                    if (p_board->data[nx2[1,1]][nx2[1,2]].candidates[l]!=0)
                                    {
                                        p_board->data[nx2[1,1]][nx2[1,2]].candidates[l]=0;
                                        p_board->data[nx2[1,1]][nx2[1,2]].num_candidates--;
                                        Xuly=true;
                                    }
                                    if (p_board->data[nx2[2,1]][nx2[2,2]].candidates[l]!=0)
                                    {
                                        p_board->data[nx2[2,1]][nx2[2,2]].candidates[l]=0;
                                        p_board->data[nx2[2,1]][nx2[2,2]].num_candidates--;
                                        Xuly=true;
                                    }
                                }
                            if(xuly) 
                                *count = *count +1;
                            //   printf(" box -- %d  %d  %d   %d   %d   \n", row,col,i,j,n);
                        }
                    }
    }
}

int  XuLy_cell_row3(SudokuBoard *p_board,int row,int col,int i,int j,int k,int nx[])
{
    //nx chua cac o tren cot, dong, box
    int count=0;
    nx[1]=-1; nx[2]=-1;nx[3]=-1;
    
    for (int n=0 ; n<9; n++)
        if (n!=col)
        {
            //if ((p_board->data[row][n].num_candidates>2) ||(p_board->data[row][col].num_candidates>2))
            if ((p_board->data[row][n].num_candidates>1) ))
            {
                if (( p_board->data[row][n].candidates[i]!=0) || ( p_board->data[row][n].candidates[j]!=0) 
                        || ( p_board->data[row][n].candidates[k]!=0) )
                    {
                        count++;
                        nx[count] = n;
                        
                        if (count==3)
                            return -1;
                    }
                
            }
        }

    return count;
}
int  XuLy_cell_col3(SudokuBoard *p_board,int row,int col,int i,int j,int k,int nx[])
{
    int count=0;
     nx[1]=-1; nx[2]=-1;nx[3]=-1;
    for (int n=0 ; n<9; n++)
        if (n!=row)
        {
            if ((p_board->data[n][col].num_candidates>2) ||(p_board->data[row][col].num_candidates>2))
            {
                if (( p_board->data[n][col].candidates[i]!=0) || ( p_board->data[n][col].candidates[j]!=0) 
                        || ( p_board->data[n][col].candidates[k]!=0))
                    {
                        count++;
                        nx[count] = n;
                        if (count==3)
                            return -1;
                    }
                
            }
        }

    return count;
}
int  XuLy_cell_box3(SudokuBoard *p_board,int row,int col,int i,int j,int k,int nx[])
{
    int row_box = (row/3)*3, col_box=(col/3)*3;
    
    nx[1,1]=-1; nx[1,2]=-1
    nx[2,1]=-1; nx[2,2]=-1;
    nx[3,1]=-1; nx[3,2]=-1;
    int count=0;
    int n=-1;
    for (int n_row=row_box ; n_row<row_box+3; n_row++)
        for( int n_col = col_box ; n_col < col_box+3;n_col++)
        if ((n_row!= row) || (n_col!=col))
        { 
            //if ((p_board->data[n_row][n_col].num_candidates>2) ||(p_board->data[row][col].num_candidates>2))
            if ( (p_board->data[row][col].num_candidates>1))
            {
                if (( p_board->data[n_row][n_col].candidates[i]!=0) ||( p_board->data[n_row][n_col].candidates[j]!=0) 
                        ||( p_board->data[n_row][n_col].candidates[k]!=0))
                    {
                        count++;
                        nx[count,1]=n_row ; nx[count,2]=n_col;
                        if (count==3)
                            return -1;
                        
                    }
                
            }
        }

    return count;
}