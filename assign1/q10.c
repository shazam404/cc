#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char* num1 = *(char**)a;
    char* num2 = *(char**)b;

    char x[strlen(num1) + strlen(num2) + 1];
    char y[strlen(num1) + strlen(num2) + 1];
    strcpy(x, num1);
    strcat(x, num2);
    strcpy(y, num2);
    strcat(y, num1);

    return strcmp(y, x);
}

char* printLargest(char* arr[], int n) {
    qsort(arr, n, sizeof(char*), compare);

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += strlen(arr[i]);
    }

    char* result = (char*)malloc((total + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < n; i++) {
        strcat(result, arr[i]);
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    char* arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(12 * sizeof(char));
        scanf("%s", arr[i]);
    }

    char* result = printLargest(arr, n);
    printf(result);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(result);

    return 0;
}
