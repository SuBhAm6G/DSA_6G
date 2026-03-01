#include <stdio.h>

// TODO: Implement Linear Search
// Return the index if found, or -1 if not found
int linearSearch(int arr[], int n, int target) {
    // Loop through the array. If arr[i] == target, return i.
    // If loop finishes without returning, return -1.
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

// TODO: Implement Iterative Binary Search
// Return the index if found, or -1 if not found
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    // While left pointer is less than or equal to right pointer:
    // 1. Calculate mid = left + (right - left) / 2
    // 2. If arr[mid] == target, return mid
    // 3. If arr[mid] < target, ignore left half: left = mid + 1
    // 4. If arr[mid] > target, ignore right half: right = mid - 1
    // If loop finishes, return -1.
    while(left<=right){
        int mid = left +(right -left)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) left=mid+1;
        else if(arr[mid]>target) right=mid-1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // Array is sorted!
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 23;
    
    int lin_result = linearSearch(arr, n, target);
    printf("Linear Search: Element %d found at index %d\n", target, lin_result);
    
    int bin_result = binarySearch(arr, n, target);
    printf("Binary Search: Element %d found at index %d\n", target, bin_result);
    
    return 0;
}