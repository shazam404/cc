#include <stdio.h>

int MissingNumber(int* arr, int n) {
	int sum = 0;
	for(int i=0;i<n-1;i++){
    	sum+=arr[i];
	}
	int total = n*(n+1)/2;
	int missingNumber = total - sum;
	return missingNumber;
}

int main() {
   int n;
	scanf("%d",&n);
	int* arr = (int*)malloc((n-1) * sizeof(int));
	for(int i=0;i<n-1;i++){
    	scanf("%d",&arr[i]);
	}
	printf("%d",MissingNumber(arr,n));
    free(arr);
    
	return 0;
}
