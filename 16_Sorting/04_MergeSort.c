#include <stdio.h>

// TODO: Implement the Merge function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left temp array
    int n2 = right - mid;    // Size of right temp array
    
    int L[n1], R[n2]; // Create temp arrays
    
    // 1. Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0; // Initial index of first subarray (L)
    int j = 0; // Initial index of second subarray (R)
    int k = left; // Initial index of merged subarray (arr)
    
    // 2. Compare elements of L and R, and copy the smaller one back into arr[k]
    // Hint: Use a while loop that runs as long as i < n1 AND j < n2
    // YOUR CODE HERE
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    
    // 3. Copy any remaining elements of L[] (if any)
    // YOUR CODE HERE
    while(i<n1) arr[k++]=L[i++];
    
    // 4. Copy any remaining elements of R[] (if any)
    // YOUR CODE HERE
    while(j<n2) arr[k++]=R[j++];
}

// Recursive split function (Already done for you!)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}