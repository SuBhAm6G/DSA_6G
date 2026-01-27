#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) {
    // Your code here
    int largest=i;
    int l=2*i+1,r=2*i+2;
    //check for left child if exists
    if (l<n && arr[l]>arr[largest]) largest=l;
    //check for right child if exists
    if(r<n && arr[r]>arr[largest]) largest=r;
    //swap?
    if (largest!=i){
        swap(&arr[i],&arr[largest]);
        //Recursive fix for subtrees
        heapify(arr,n,largest);
    }
}
// TODO: Write this function
// Converts an arbitrary array into a max heap
void buildHeap(int arr[], int n) {
    // 1. Find last non-leaf node: (n/2) - 1
    // 2. Loop from that index down to 0
    // 3. Call heapify() for each
    int i=(n/2)-1;
    for(i;i>=0;i--){
        heapify(arr,n,i);
    }
}

int main() {
    int arr[] = {10, 20, 15, 12, 40, 25, 18};
    int n = 7;
    buildHeap(arr, n);

    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    
    return 0;
}