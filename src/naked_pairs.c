#include "naked_pairs.h"

int naked_pairs(SudokuBoard *p_board)
{
    p_board->data[2][7].candidates[1]=0;
    p_board->data[2][7].num_candidates=2;

    return 2;
}