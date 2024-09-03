#include <stdio.h>
#include <stdlib.h>

void row_major(int n, int matrix[n][n]) {
    int result[n * 3 - 2], index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j <= i + 1; j++) {
            if (j >= 0 && j < n) {
                result[index++] = matrix[i][j];
            }
        }
    }
    printf("Row-major order: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void column_major(int n, int matrix[n][n]) {
    int result[n * 3 - 2], index = 0;
    for (int j = 0; j < n; j++) {
        for (int i = j - 1; i <= j + 1; i++) {
            if (i >= 0 && i < n) {
                result[index++] = matrix[i][j];
            }
        }
    }
    printf("Column-major order: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void diagonal_major(int n, int matrix[n][n]) {
    int result[n * 3 - 2], index = 0;
    for (int d = 0; d <= 2 * (n - 1); d++) {
        for (int i = 0; i < n; i++) {
            int j = d - i;
            if (j >= 0 && j < n && abs(i - j) <= 1) {
                result[index++] = matrix[i][j];
            }
        }
    }
    printf("Diagonal-wise: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the elements of the matrix row-wise:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    row_major(n, matrix);
    column_major(n, matrix);
    diagonal_major(n, matrix);
    return 0;
}
