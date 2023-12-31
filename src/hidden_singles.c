#include "hidden_singles.h"
#include <stdlib.h>
#include <stdio.h>
int hidden_singles(SudokuBoard *p_board)
{
    HiddenSingle cas[100];
    int num_cas=0;
    int count;
    for (int row=0;row<BOARD_SIZE;row++)
    for (int col=0;col<BOARD_SIZE;col++)
    {
        count = check__hidden_single(p_board,row,col);
        
        if(count!=-1)
        {
            num_cas++;
            cas[num_cas].row=row;
            cas[num_cas].col=col;
            cas[num_cas].cad=count;
        }
    }
    for (int i=1;i<=num_cas;i++){
        printf("----------   %d  %d   %d  \n",cas[i].row,cas[i].col,cas[i].cad);
    }
    sol__hidden_single(p_board,cas , num_cas);
    return num_cas;
    
    
}
    
void sol__hidden_single(SudokuBoard *p_board,HiddenSingle cas[] , int num_cas) 
{
    for(int i=1; i<=num_cas;i++ ){
        for (int j=0;j<BOARD_SIZE;j++){
        
            if(  (p_board->data[cas[i].row][cas[i].col].candidates[j]==1) 
                  && (j!= cas[i].cad)){
                p_board->data[cas[i].row][cas[i].col].candidates[j]=0;
                p_board->data[cas[i].row][cas[i].col].num_candidates--;
            }

        }
    }
}

int check__hidden_single(SudokuBoard *p_board,int row, int col) 
{
    
    int count=0;
    if(p_board->data[row][col].num_candidates==1)
    {
        return -1;
    }
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        if(p_board->data[row][col].candidates[i]!=0)
        {
            count=0;
            for(int j=0;j<BOARD_SIZE;j++){
                if(p_board->data[j][col].candidates[i]==1){
                    count++;
                }
            }
            
            if(count==1){
                return i;
            }
            
            
            count=0;
            for(int j=0;j<BOARD_SIZE;j++){
                if(p_board->data[row][j].candidates[i]==1){
                    count++;
                }
            }
            if(count==1)
                return i;
            count=0;
            for(int j=(row/3)*3;j<(row/3)*3+3;j++){
                for(int k=(col/3)*3;k<(col/3)*3+3;k++)
                if(p_board->data[j][k].candidates[i]==1){
                    count++;
                }
            }
            if(count==1)
                return i;
        }
    }
    
    return -1;
}    

