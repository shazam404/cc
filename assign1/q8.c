#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findMinDiff(int* arr, int n, int m) {
    if (m > n) {
        return -1;
    }

    qsort(arr, n, sizeof(int), compare);

    int min = INT_MAX; 

    for (int i = 0; i + m - 1 < n; i++) {
        int current = arr[i + m - 1] - arr[i];
        if (current < min) {
            min = current;
        }
    }

    return min;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = findMinDiff(arr, n, m);
    if (result == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }

    free(arr);
    return 0;
}
