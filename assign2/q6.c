#include <stdio.h>

int towerOfHanoi(int n, char source, char temp, char destination, int* count) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*count)++;  
        return 1;
    }
    
    int steps = 0;
    
    steps += towerOfHanoi(n - 1, source, destination, temp, count);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*count)++;  
    steps += 1;  
    
    steps += towerOfHanoi(n - 1, temp, source, destination, count);
    
    return steps;
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    
    int count = 0;  
    
    printf("Tower of Hanoi:\n");
    towerOfHanoi(numDisks, 'A', 'B', 'C', &count);
    
    printf("Total number of steps: %d\n", count);
    
    return 0;
}
