#include <stdio.h>

void leader(int* arr, int n) {
    int max = arr[n - 1]; 
    int* leaders = (int*)malloc(n * sizeof(int));
    int index = 0;
    
    leaders[index++] = max;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max) {
            max = arr[i];
            leaders[index++] = max;
        }
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");
    free(leaders);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    leader(arr, n);
    free(arr);
    return 0;
}