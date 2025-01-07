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

int main() {
    char board[SIZE][SIZE];
    int mode, winner = 0;

    // Initialize the board with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Select mode:\n1. Multiplayer\n2. Single-player (vs Computer)\n");
    printf("Enter your choice: ");
    scanf("%d", &mode);

    // Game loop
    int turn = 0;
    while (!winner && !isBoardFull(board)) {
        displayBoard(board);

        if (turn % 2 == 0) {
            printf("Player 1's Turn (X):\n");
            playerMove(board, 'X');
        } else {
            if (mode == 1) {
                printf("Player 2's Turn (O):\n");
                playerMove(board, 'O');
            } else {
                printf("Computer's Turn (O):\n");
                computerMove(board, 'O');
            }
        }

        winner = checkWinner(board);
        turn++;
    }

    displayBoard(board);

    // Display game result
    if (winner == 1) {
        printf("Player 1 (X) wins!\n");
    } else if (winner == 2) {
        if (mode == 1) {
            printf("Player 2 (O) wins!\n");
        } else {
            printf("Computer (O) wins!\n");
        }
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}