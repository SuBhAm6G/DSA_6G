#include <stdio.h>

// TODO: Implement Shell Sort
void shellSort(int arr[], int n) {
    // 1. Outer loop controls the gap: start gap at n/2, loop while gap > 0, gap = gap/2
    // 2. Middle loop: i from 'gap' to 'n-1' (This is the insertion sort pass)
    // 3. Inside middle loop:
    //      a. Store arr[i] in a 'temp' variable
    //      b. Set j = i
    //      c. Inner loop: While j >= gap AND arr[j - gap] > temp:
    //          - Shift element by gap: arr[j] = arr[j - gap]
    //          - Decrement j by gap: j -= gap
    //      d. Put 'temp' into arr[j]
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int temp=arr[i];
            int j=i;
            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j -= gap;
            }
            arr[j]=temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}