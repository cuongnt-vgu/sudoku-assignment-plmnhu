#pragma once

#include <stdbool.h>

#define BOARD_SIZE 9

struct Cell_impl
{
    int row_index;
    int col_index;
    int box_index;
    int num_candidates;
    int candidates[BOARD_SIZE];
    int value; // solved or 0
    bool fixed;
};

typedef struct Cell_impl Cell;

struct SudokuBoard_impl
{
    int solved_counter;
    Cell **data; // 9x9 cell board

    Cell **p_rows[BOARD_SIZE];  // rows pointers
    Cell **p_cols[BOARD_SIZE];  // cols pointers
    Cell **p_boxes[BOARD_SIZE]; // boxes pointers
    Cell *solved_cells[BOARD_SIZE *
                       BOARD_SIZE]; // solved cell pointers (maximum)
};

typedef struct SudokuBoard_impl SudokuBoard;

struct cas_naked_pairs_impl
{
    int row1;
    int col1;
    int row2;
    int col2;
    int cas1;
    int cas2;
    
};
typedef struct cas_naked_pairs_impl cas_naked_pairs;
struct cas_naked_triples_impl
{
    int row1;
    int col1;
    int row2;
    int col2;
    int row3;
    int col3;
    int cas1;
    int cas2;
    int cas3;
    
};
typedef struct cas_naked_triples_impl cas_naked_triples;
void init_sudoku(SudokuBoard *p_board);
void load_sudoku(SudokuBoard *p_board, char *input_text);
bool apply_constraint(Cell **p_cells, int value);
bool is_in_list(Cell **p_array, int size, Cell *p);
void print_candidate_num(SudokuBoard *p_board);
void print_solution(SudokuBoard *p_board);

void set_candidate(Cell *cell, int value);
void unset_candidate(Cell *cell, int value);
void set_candidates(Cell *cell, int *candidates, int size);
int *get_candidates(Cell *cell);

int check_solved_cells(SudokuBoard *p_board, Cell ***p_solved_cells);
bool show_possible(SudokuBoard *p_board, Cell **p_solved_cells, int counter);
void free_sudoku(SudokuBoard *p_board);
void sosanhhaio(Cell cell1, Cell cell2, int *So_gtgn, int *Day_gtgn);
void r_c_box(int row, int col , int *n_box, int *n_cell );
void  XuLy_Mot_cell(SudokuBoard *p_board,int row, int col,int *count);
int  XuLy_cell_row(SudokuBoard *p_board,int row,int col,int i,int j);
int  XuLy_cell_col(SudokuBoard *p_board,int row,int col,int i,int j);
int  XuLy_cell_box(SudokuBoard *p_board,int row,int col,int i,int j);
void  XuLy_Mot_cell3(SudokuBoard *p_board,int row, int col, int *count);
int  XuLy_cell_row3(SudokuBoard *p_board,int row,int col,int i,int j,int k,int nx[]);
int  XuLy_cell_col3(SudokuBoard *p_board,int row,int col,int i,int j,int k,int nx[]);
int  XuLy_cell_box3(SudokuBoard *p_board,int row,int col,int i,int j,int k,int nx[][5]);
void print_cell(SudokuBoard *p_board,int row, int col);
int pair_2cell(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int *cas1, int *cas2);
int num_cas(SudokuBoard *p_board, cas_naked_pairs cas[],int *n_cas);
void xuly_naked_pair(SudokuBoard *p_board, cas_naked_pairs cas[],int n_cas);
int pair_3cell(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int row3,int col3,int *cas1, int *cas2,int *cas3);
int num_cas3(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas);
void xuly_naked_triples(SudokuBoard *p_board, cas_naked_triples cas[],int n_cas);
int pair_3cellh(SudokuBoard *p_board,int row1, int col1,int row2, int col2,int row3,int col3,int *cas1, int *cas2,int *cas3);
int num_cas3h(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas);
void xuly_naked_triplesh(SudokuBoard *p_board, cas_naked_triples cas[],int *n_cas);