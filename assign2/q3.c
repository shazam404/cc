#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, count = 0;
    
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);
    
    int matrix[rows][cols];
    
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sparseArray[300]; 
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparseArray[count++] = i;
                sparseArray[count++] = j;
                sparseArray[count++] = matrix[i][j];
            }
        }
    }
    
    printf("Memory mapping of sparse matrix (row index, column index, value):\n");
    for(int i = 0; i < count; i += 3) {
        printf("(%d, %d, %d) ", sparseArray[i], sparseArray[i+1], sparseArray[i+2]);
    }
    printf("\n");

    return 0;
}
