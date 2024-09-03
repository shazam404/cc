#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    
    printf("Enter the size of the symmetric matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Row-major order: ");
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    printf("Column-major order: ");
    for(j = 0; j < n; j++) {
        for(i = 0; i <= j; i++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    return 0;
}
