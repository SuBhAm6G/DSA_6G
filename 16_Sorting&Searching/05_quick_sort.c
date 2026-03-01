#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// TODO: Implement the Partition function
int partition(int arr[], int low, int high) {
    // 1. Choose arr[high] as pivot
    // 2. Set i = low - 1
    // 3. Loop j from low to high - 1
    // 4. Inside loop: if arr[j] < pivot, increment i and swap arr[i] with arr[j]
    // 5. After loop: swap arr[i + 1] with arr[high] (the pivot)
    // 6. Return i + 1
    int pivot=high;
    int i=low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[pivot]);
    return i+1;
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}