#include <stdio.h>

void reverseArray(int arr[], int n) {
	int start = 0;
	int end = n - 1;
    
	while (start < end) {
    	arr[start] ^= arr[end];
    	arr[end] ^= arr[start];
    	arr[start] ^= arr[end];
   	 
    	start++;
    	end--;
	}
}


int main() {
    
    int n;
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
   	 scanf("%d",&arr[i]);
    }
    
	reverseArray(arr, n);
    
	for (int i = 0; i < n; i++) {
    	printf("%d ", arr[i]);
	}
	printf("\n");
    
	return 0;
}
