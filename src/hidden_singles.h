#pragma once

#include "sudoku.h"
int hidden_singles(SudokuBoard *p_board);
typedef struct HiddenSingle_impl
{
    int row;
    int col;
    int cad;
    
} HiddenSingle;
// kiem tra cell(x,y) cos chua thuoc tinh xuat hien duy nhat khong
int check__hidden_single(SudokuBoard *p_board,int row, int col) ;
//giai quyet 
void sol__hidden_single(SudokuBoard *p_board,HiddenSingle cas[] , int num_cas) ;


