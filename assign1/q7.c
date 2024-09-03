#include <stdio.h>
#include <stdlib.h>

int trappingWater(int* arr, int n) {

    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));

    left[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if(arr[i] > left[i - 1]) {
            left[i] = arr[i];
        } else {
            left[i] = left[i - 1];
        }
    }

    right[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if(arr[i] > right[i + 1]) {
            right[i] = arr[i];
        } else {
            right[i] = right[i + 1];
        }
    }

    int total = 0;

    for (int i = 0; i < n; i++) {
        int current = 0;
        if (left[i] < right[i]) {
            current = left[i];
        } else {
            current = right[i];
        }
        current -= arr[i];
        if (current > 0) {
            total += current;
        }
    }

    free(left);
    free(right);

    return total;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = trappingWater(arr, n);
    printf("%d",result);

    free(arr);
    return 0;
}
