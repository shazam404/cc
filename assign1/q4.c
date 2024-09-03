#include <stdio.h>

int mergeAndCount(int* arr, int* temp, int left, int mid, int right) {
    int i = left;   
    int j = mid + 1; 
    int k = left;    
    int count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1); 
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

int mergeSortAndCount(int* arr, int* temp, int left, int right) {
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        count += mergeSortAndCount(arr, temp, left, mid);
        count += mergeSortAndCount(arr, temp, mid + 1, right);

        count += mergeAndCount(arr, temp, left, mid, right);
    }
    return count;
}

int inversionCount(int* arr, int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int result = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = inversionCount(arr, n);
    printf("%d\n", result);

    free(arr);
    return 0;
}
