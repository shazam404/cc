#include <stdio.h>

int twoSum(int* arr, int n, int x) {
	int left = 0;
	int right = n - 1;

	while (left < right) {
    	int sum = arr[left] + arr[right];
   	 
    	if (sum == x) {
        	return 1;
    	} else if (sum < x) {
        	left++;
    	} else {
        	right--;
    	}
	}

	return 0;
}

int main() {
	int n,x;
    scanf("%d",&n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
   	 scanf("%d",&arr[i]);
    }
	scanf("%d",&x);

	if (twoSum(arr, n, x)) {
    	printf("Array has two elements with sum %d\n", x);
	} else {
    	printf("Array does not have two elements with sum %d\n", x);
	}

	return 0;
}
