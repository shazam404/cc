#include <stdio.h>

void printBoard(int board[8][8], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[8][8], int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1;
}

int solveNQueens(int board[8][8], int col, int n) {
    if (col >= n) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)==1) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, n)==1) {
                return 1;
            }

            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the size of the chessboard (n): ");
    scanf("%d", &n);

    int board[8][8] = {0};

    if (solveNQueens(board, 0, n)==1) {
        printf("Solution:\n");
        printBoard(board, n);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
