#include <stdio.h>

int checkTriplet(int* arr, int n) {
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int* hash = (int*)malloc(((max * max) + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        hash[arr[i] * arr[i]] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = (arr[i] * arr[i]) + (arr[j] * arr[j]);
            if (sum <= max * max && hash[sum]) {
                free(hash);
                return 1;
            }
        }
    }

    free(hash);
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (checkTriplet(arr, n)==1) {
        printf("Yes");
    } else {
        printf("No");
    }

    free(arr);
    return 0;
}