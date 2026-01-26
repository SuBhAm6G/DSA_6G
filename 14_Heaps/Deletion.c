#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// TODO: Write this function
// n is size of heap, i is index to heapify
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
// Returns the deleted value, updates n (pass n by reference or handle size externally)
int deleteRoot(int arr[], int *n) {
    // Your code here
    if (*n==0) return -1;
    int max_val=arr[0];
    arr[0]=arr[(*n)-1];
    (*n)--;
    heapify(arr,*n,0);
    return max_val;
}

int main() {
    int arr[] = {50, 30, 20, 15, 10};
    int n = 5;
    
    printf("Deleted: %d\n", deleteRoot(arr, &n));
    
    printf("Heap after deletion: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    
    return 0;
}