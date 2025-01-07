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

// Function to display the board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if there is a winner
int checkWinner(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (board[i][0] == 'X') ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (board[0][i] == 'X') ? 1 : 2;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return (board[0][0] == 'X') ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return (board[0][2] == 'X') ? 1 : 2;

    // No winner yet
    return 0;
}
