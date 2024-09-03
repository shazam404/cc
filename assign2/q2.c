#include <stdio.h>
#include<stdlib.h>

int main() {
    int n;
    
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    
    int matrix[n][n];
    
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("Upper triangular matrix memory mapping in row-major order: ");
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
    
    printf("Upper triangular matrix memory mapping in column-major order: ");
    for(int j = 0; j < n; j++) {
        for(int i = 0; i <= j; i++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    printf("Lower triangular matrix memory mapping in row-major order: ");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    printf("Lower triangular matrix memory mapping in column-major order: ");
    for(int j = 0; j < n; j++) {
        for(int i = j; i < n; i++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");

    return 0;
}
