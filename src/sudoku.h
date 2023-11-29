#pragma once

#include <stdbool.h>

#define BOARD_SIZE 9

<<<<<<< HEAD
struct Cell_impl
{
=======
struct Cell_impl {
>>>>>>> 691fb2b (Initial commit)
    int row_index;
    int col_index;
    int box_index;
    int num_candidates;
    int candidates[BOARD_SIZE];
<<<<<<< HEAD
    int value; // solved or 0
    bool fixed;
=======
    int value;  // solved or 0
>>>>>>> 691fb2b (Initial commit)
};

typedef struct Cell_impl Cell;

<<<<<<< HEAD
struct SudokuBoard_impl
{
    int solved_counter;
    Cell **data; // 9x9 cell board

    Cell **p_rows[BOARD_SIZE];  // rows pointers
    Cell **p_cols[BOARD_SIZE];  // cols pointers
    Cell **p_boxes[BOARD_SIZE]; // boxes pointers
    Cell *solved_cells[BOARD_SIZE *
                       BOARD_SIZE]; // solved cell pointers (maximum)
=======
struct SudokuBoard_impl {
    int solved_counter;
    Cell **data;  // 9x9 cell board

    Cell **p_rows[BOARD_SIZE];   // rows pointers
    Cell **p_cols[BOARD_SIZE];   // cols pointers
    Cell **p_boxes[BOARD_SIZE];  // boxes pointers
    Cell *solved_cells[BOARD_SIZE *
                       BOARD_SIZE];  // solved cell pointers (maximum)
>>>>>>> 691fb2b (Initial commit)
};

typedef struct SudokuBoard_impl SudokuBoard;

void init_sudoku(SudokuBoard *p_board);
void load_sudoku(SudokuBoard *p_board, char *input_text);
bool apply_constraint(Cell **p_cells, int value);
bool is_in_list(Cell **p_array, int size, Cell *p);
void print_candidate_num(SudokuBoard *p_board);
void print_solution(SudokuBoard *p_board);

void set_candidate(Cell *cell, int value);
void unset_candidate(Cell *cell, int value);
void set_candidates(Cell *cell, int *candidates, int size);
<<<<<<< HEAD
int *get_candidates(Cell *cell);

int check_solved_cells(SudokuBoard *p_board, Cell ***p_solved_cells);
bool show_possible(SudokuBoard *p_board, Cell **p_solved_cells, int counter);
void free_sudoku(SudokuBoard *p_board);
=======
int *get_candidates(Cell *cell);
>>>>>>> 691fb2b (Initial commit)
