#include <stdio.h>

void printCombination(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int j = 0; j < r; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        printCombination(arr, data, i + 1, end, index + 1, r);
    }
}

void generateCombinations(int arr[], int n, int r) {
    int data[r];
    printCombination(arr, data, 0, n - 1, 0, r);
}

int main() {
    int n, r;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &r);

    generateCombinations(arr, n, r);

    return 0;
}
