#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// TODO: Implement Selection Sort
void selectionSort(int arr[], int n) {
    // 1. Outer loop 'i' from 0 to n-1
    // 2. Set min_idx = i
    // 3. Inner loop 'j' from i+1 to n
    // 4. If arr[j] < arr[min_idx], update min_idx = j
    // 5. After inner loop, if min_idx != i, swap arr[i] and arr[min_idx]
    for(int i=0; i<n; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        if(min_idx!=i) swap(&arr[i], &arr[min_idx]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}