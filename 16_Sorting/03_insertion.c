#include <stdio.h>

// TODO: Implement Insertion Sort
void insertionSort(int arr[], int n) {
    // 1. Loop 'i' from 1 to n-1
    // 2. Set key = arr[i]
    // 3. Set j = i - 1
    // 4. While j >= 0 AND arr[j] > key:
    //      a. Shift arr[j] to the right: arr[j + 1] = arr[j]
    //      b. Decrement j
    // 5. Insert key at arr[j + 1]
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}