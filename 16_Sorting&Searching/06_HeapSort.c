#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard max heapify
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// TODO: Implement Heap Sort
void heapSort(int arr[], int n) {
    // 1. Build a Max-Heap from the array
    // Hint: Loop from (n/2 - 1) down to 0, calling heapify(arr, n, current_index)
    
    // 2. Extract elements one by one from the heap
    // Hint: Loop i from (n - 1) down to 1
    //    a. Swap the root (arr[0]) with the last element (arr[i])
    //    b. Call heapify on the reduced heap: heapify(arr, i, 0)
    for(int i = n/2 -1; i>=0; i--){
        heapify(arr,n,i);
    }
    for(int i = n-1; i>0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    heapSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}