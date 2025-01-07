#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3


void displayBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char symbol);
void computerMove(char board[SIZE][SIZE], char symbol);
int isMoveValid(char board[SIZE][SIZE], int row, int col);
int isBoardFull(char board[SIZE][SIZE]);