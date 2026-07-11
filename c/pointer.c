#include<stdio.h>

void arraySort(int array[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(array[j] > array[j+1]) {
                int swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
}

int binarySearch(int arr[], int n, int x) {
    int fe = 0, le = n - 1;
    while(fe <= le) {
        int me = (fe + le) / 2;
        if(arr[me] < x)
            fe = me + 1;
        else if(arr[me] == x)
            return me;
        else
            le = me - 1;
    }
    return -1;
}

int main() {
    int n, x;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search in the array: ");
    scanf("%d", &x);
    
    arraySort(arr, n);
    int result = binarySearch(arr, n, x);
    if(result != -1) {
        printf("The element %d is found at index %d.\n", x, result);
    } else {
        printf("The element %d is not present in the array.\n", x);
    }
    return 0;
}

