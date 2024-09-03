#include <stdio.h>

int nCr(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }
    
    int result = 1;
    
    for (int i = 0; i < r; i++) {
        result = result * (n - i);
        result = result / (i + 1);
    }
    
    return result;
}

int main() {
    int n, r;
    
    printf("Enter (N): ");
    scanf("%d", &n);
    
    printf("Enter (R): ");
    scanf("%d", &r);
    
    int result;
    if(r < n/2){
        result = nCr(n, r);
    }
    else{
        result = nCr(n, n-r);
    }
    
    printf("%d\n",result);
    
    return 0;
}
