#include <stdio.h>

int* subarraySum(int* arr, int n, int s) {
    int start = 0;
    int sum = arr[0];
    for (int i = 1; i <= n; i++) {
        while (sum > s && start < i - 1) {
            sum -= arr[start];
            start++;
        }
        
        if (sum == s) {
            int* res = (int*)malloc(2 * sizeof(int));
            res[0] = start + 1; 
            res[1] = i;  
            return res;
        }
        
        if (i < n) {
            sum += arr[i];
        }
    }

    int* res = (int*)malloc(sizeof(int));
    res[0] = -1;
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int s;
    scanf("%d", &s);
    int* res = subarraySum(arr, n, s);
    if (res[0] == -1) {
        printf("%d\n", res[0]);
    } else {
        printf("%d %d\n", res[0], res[1]);
    }
    free(arr);
    free(res);
    return 0;
}
