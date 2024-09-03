#include <stdio.h>

int countTriplet(int* arr, int N) {
	int count = 0;
    
	int* hash = (int*)malloc(1001 * sizeof(int));
    
	for (int i = 0; i < N; ++i) {
    	hash[arr[i]] = 1;
	}
    
	for (int i = 0; i < N - 1; ++i) {
    	for (int j = i + 1; j < N; ++j) {
        	int sum = arr[i] + arr[j];
        	if (hash[sum]==1) {
            	count++;
        	}
    	}
	}
	free(hash);
    
	return count;
    
}

int main() {
    int n;
	scanf("%d",&n);
	int* arr = (int*)malloc(n * sizeof(int));
	for(int i=0;i<n;i++){
    	scanf("%d",&arr[i]);
	}
	printf("%d\n",countTriplet(arr,n));
    free(arr);
    
	return 0;
}
