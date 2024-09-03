#include <stdio.h>
#include <stdlib.h>

void find_row_major(int** matrix, int rows, int cols, int* result) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[index++] = matrix[i][j];
        }
    }
}

void find_column_major(int** matrix, int rows, int cols, int* result) {
    int index = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            result[index++] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    int* row_major = (int*)malloc(rows * cols * sizeof(int));
    int* column_major = (int*)malloc(rows * cols * sizeof(int));

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    find_row_major(matrix, rows, cols, row_major);
    find_column_major(matrix, rows, cols, column_major);

    printf("Row-major: ");
    for (int i = 0; i < rows * cols; i++) {
        printf("%d ", row_major[i]);
    }
    printf("\n");

    printf("Column-major: ");
    for (int i = 0; i < rows * cols; i++) {
        printf("%d ", column_major[i]);
    }
    printf("\n");

    free(matrix);
    free(row_major);
    free(column_major);

    return 0;
}
