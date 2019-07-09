#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H
#include<stdio.h>
//takes puzzles  as 9 by 9 2d arrays

//print formated puzzle to stdout
void print_sudoku(int sudoku[9][9]);

//helper functions
int check_sudoku(int sudoku[9][9],int y,int x,int val);
int recursive_helper(int sudoku[9][9],int y ,int x, int depth);

//pass in any 9 by 9 matrix that represents the Sudoku Puzzle.
//if succeeded, the solved matrix will replace the argument
//if failed, the argument will not be mutated. 
void solve_sudoku(int sudoku[9][9]);

#endif
