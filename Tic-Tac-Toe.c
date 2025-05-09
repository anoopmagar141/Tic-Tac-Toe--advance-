#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Function prototypes
void displayBoard(char board[SIZE][SIZE]);
int checkWinner(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char symbol);
void computerMove(char board[SIZE][SIZE], char symbol);
int isMoveValid(char board[SIZE][SIZE], int row, int col);
int isBoardFull(char board[SIZE][SIZE]);

// Main function
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

// Function for player move
void playerMove(char board[SIZE][SIZE], char symbol) {
    int row, col;

    while (1) {
        printf("Enter row and column (1-3 1-3): ");
        scanf("%d %d", &row, &col);

        // Adjust for zero-based index
        row--;
        col--;

        if (isMoveValid(board, row, col)) {
            board[row][col] = symbol;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

// Function for computer move
void computerMove(char board[SIZE][SIZE], char symbol) {
    srand(time(NULL));
    int row, col;

    while (1) {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if (isMoveValid(board, row, col)) {
            board[row][col] = symbol;
            break;
        }
    }
}

// Function to check if a move is valid
int isMoveValid(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
