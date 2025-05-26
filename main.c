#include<stdio.h>

// This is a simple console-based Tic-Tac-Toe game in C
// It allows two players to play against each other

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int player = 1;  // Player 1 starts

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check for a winner
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full (draw)
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return 0; // If any number is left, game is not a draw
            }
        }
    }
    return 1;
}

int main() {
    int move, row, col;
    char mark;

    while (1) {
        printBoard();
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d (%c), enter your move (1-9): ", player, mark);
        scanf("%d", &move);

        if (move < 1 || move > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Spot already taken! Try again.\n");
            continue;
        }

        board[row][col] = mark;

        if (checkWin()) {
            printBoard();
            printf("Player %d (%c) wins!\n", player, mark);
            break;
        }

        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1; // Switch player
    }

    return 0;
}