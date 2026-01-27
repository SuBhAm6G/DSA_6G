#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// TODO: Write this function
// Adds value to heap, updates n (pass by reference)
void insertNode(int arr[], int *n, int value) {
    // 1. Increase size (assume array has enough capacity)
    // 2. Insert at end
    // 3. Loop to Heapify Up (Bubble Up)
    (*n)++;
    arr[*n-1]=value;
    int i=*n-1;
    while(i>0){
        int parent=(i-1)/2;
        if(arr[i]>arr[parent]){
            swap(&arr[i],&arr[parent]);
            i=parent;
        }
        else return;
    }

}

int main() {
    // Array with extra capacity for insertion
    int arr[10] = {50, 30, 20, 15, 10}; 
    int n = 5;

    printf("Original: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Test Insertion
    insertNode(arr, &n, 60);

    printf("After inserting 60: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    
    return 0;
}