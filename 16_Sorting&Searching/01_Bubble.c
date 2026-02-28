#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// TODO: Write this function
// Implement optimized Bubble Sort with the 'swapped' flag
void bubbleSort(int arr[], int n) {
    // 1. Outer loop for passes: i from 0 to n-1
    // 2. Initialize a swapped flag inside the outer loop to false
    // 3. Inner loop for comparisons: j from 0 to n-i-1 (shrinking the boundary)
    // 4. If arr[j] > arr[j+1], swap them and set swapped to true
    // 5. If after inner loop swapped is still false, break out of outer loop
    for(int i=0; i<n; i++){
        int flag=0;
        for (int j = 0; j < n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        if(!flag) break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}