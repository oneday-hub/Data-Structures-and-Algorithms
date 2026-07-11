#include<stdio.h>

void bubble_Sort(int array[], int n) {
    int i, j, swap;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap = array[j];
                array[j] = array[j+1]; 
                array[j+1] = swap;
            }
        }
    }
}

int main() {
    int array[100], n, i;
    
    printf("Enter length of array: ");
    scanf("%d", &n);
    printf("Enter %d Numbers:\n", n);
    
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    bubble_Sort(array, n);

    printf("Sorted Array:\n");
    
    for(i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    
    return 0;
}
