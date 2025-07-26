// a) Implement Linear search on a List using Array in C.

//    ii)Deletion at the specific  position.
#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}

void Deletion(int **arr, int *n, int pos){
    for (int i = pos; i < *n-1; i++)
    {
        (*arr)[i]=(*arr)[i+1];
    }
    (*n)--;
    *arr=(int*)realloc(*arr, (*n)*sizeof(int));
}

int main() {
    int *arr, n, pos,key;;
    printf("Enter the number of element in the array: ");
    scanf("%d", &n);
    arr=(int*)malloc((n)*sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    // Print array before Deletion
    printf("\n");
    printf("Array before Deletion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Collecting details of Deletion
    printf("Enter the index of the element you want to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        free(arr);
        return -1;
    }
    // Calling function
    Deletion(&arr, &n, pos);
    // Print array after Insertion
    printf("\n");
    printf("Array after Deletion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    int index = LinearSearch(arr, n, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
    free(arr);
}