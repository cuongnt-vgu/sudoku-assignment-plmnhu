#include "hidden_pairs.h"
#include <stdio.h>
#include <stdlib.h>
int hidden_pairs(SudokuBoard *p_board)
{

    int count = 0;   
    cas_naked_pairs cas[100];
    for (int i=0 ; i<9 ; i++)
        for (int j=0; j<9 ; j++)
    XuLy_Mot_cell(p_board,i,j,&count,cas);
    xuly_hidden_pair(p_board, cas,count);
    for(int i=1; i<=count;i++)
        {
        printf("cuoi cung  %d %d  %d  %d  %d  %d  %d\n", count, cas[i].row1, cas[i].col1, cas[i].row2, cas[i].col2, cas[i].cas1, cas[i].cas2);
        }
    return count;
}

void  XuLy_Mot_cell(SudokuBoard *p_board,int row, int col, int *count, cas_naked_pairs cas[])
{
    if (p_board->data[row][col].num_candidates>1)
    {
        int n=-1;
        for (int i=0 ; i<8; i++)
            for (int j=i+1 ; j<9 ; j++)
            if (( p_board->data[row][col].candidates[i]!=0) &&( p_board->data[row][col].candidates[j]!=0) )
                {
                    n=XuLy_cell_row(p_board,row,col,i,j);
                    if ((n>-1) && (n>col))
                    {
                        *count= *count+1;
                        cas[*count].row1=row; cas[*count].col1=col;
                        cas[*count].row2=row; cas[*count].col2=n;
                        cas[*count].cas1=i; cas[*count].cas2=j;
                  }
                    if(n==-1)
                        n=XuLy_cell_col(p_board,row,col,i,j);
                    if ((n>-1) && (n>row))
                    {
                        *count = *count +1;
                        cas[*count].row1=row; cas[*count].col1=col;
                        cas[*count].row2=n; cas[*count].col2=col;
                        cas[*count].cas1=i; cas[*count].cas2=j;
                    }
                    if(n==-1)    
                        n=XuLy_cell_box(p_board,row,col,i,j);
                    if ((n>-1)&&(n>(row*9+col)))
                    {
                        *count = *count+1;
                        cas[*count].row1=row; cas[*count].col1=col;
                        cas[*count].row2=n/9; cas[*count].col2=n%9;
                        cas[*count].cas1=i; cas[*count].cas2=j;
                    }
                }
    }
}

int  XuLy_cell_row(SudokuBoard *p_board,int row,int col,int i,int j)
{
    int count=0;
    int n_col=-1;
    
    for (int n=0 ; n<9; n++)
        if (n!=col)
        {
            if ((p_board->data[row][n].num_candidates>2) ||(p_board->data[row][col].num_candidates>2))
            {
                if (( p_board->data[row][n].candidates[i]!=0) &&( p_board->data[row][n].candidates[j]!=0) )
                    {
                        count++;
                        n_col = n;
                        
                        if (count==2)
                            return -1;
                    }
                else 
                    if (( p_board->data[row][n].candidates[i]!=0) || ( p_board->data[row][n].candidates[j]!=0) )
                    {
                        return -1;
                    }
            }
        }
    return n_col;
}
int  XuLy_cell_col(SudokuBoard *p_board,int row,int col,int i,int j)
{
    int count=0;
    int n_row=-1;
    for (int n=0 ; n<9; n++)
        if (n!=row)
        {
            if ((p_board->data[n][col].num_candidates>2) ||(p_board->data[row][col].num_candidates>2))
            {
                if (( p_board->data[n][col].candidates[i]!=0) &&( p_board->data[n][col].candidates[j]!=0) )
                    {
                        count++;
                        n_row = n;
                        if (count==2)
                            return -1;
                    }
                else 
                    if (( p_board->data[n][col].candidates[i]!=0) || ( p_board->data[n][col].candidates[j]!=0) )
                    {
                        return -1;
                    }
            }
        }
    return n_row;
}
int  XuLy_cell_box(SudokuBoard *p_board,int row,int col,int i,int j)
{
    int row_box = (row/3)*3, col_box=(col/3)*3;
    int count=0;
    int n=-1;
    for (int n_row=row_box ; n_row<row_box+3; n_row++)
        for( int n_col = col_box ; n_col < col_box+3;n_col++)
        if ((n_row!= row) || (n_col!=col))
        { 
            if ((p_board->data[n_row][n_col].num_candidates>2) ||(p_board->data[row][col].num_candidates>2))
            {
                if (( p_board->data[n_row][n_col].candidates[i]!=0) &&( p_board->data[n_row][n_col].candidates[j]!=0) )
                    {
                        count++;
                        n = n_row*9 + n_col;
                        if (count==2)
                            return -1;
                    }
                else 
                    if (( p_board->data[n_row][n_col].candidates[i]!=0) || ( p_board->data[n_row][n_col].candidates[j]!=0) )
                    {
                        return -1;
                    }
            }
        }
    return n;
}
void xuly_hidden_pair(SudokuBoard *p_board, cas_naked_pairs cas[],int n_cas)
{
    for (int i=1; i<=n_cas;i++)
    {
        for(int j=0; j<BOARD_SIZE;j++)
        {
            if((j!=cas[i].cas1) && (j!=cas[i].cas2))
            {
                if(p_board->data[cas[i].row1][cas[i].col1].candidates[j]==1)
                {
                    p_board->data[cas[i].row1][cas[i].col1].candidates[j]=0;
                    p_board->data[cas[i].row1][cas[i].col1].num_candidates--;
                }
                if(p_board->data[cas[i].row2][cas[i].col2].candidates[j]==1)
                {
                    p_board->data[cas[i].row2][cas[i].col2].candidates[j]=0;
                    p_board->data[cas[i].row2][cas[i].col2].num_candidates--;
                }
            }
        }
 
    }
}
