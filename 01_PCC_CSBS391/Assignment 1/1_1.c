// a) Implement Linear search on a List using Array in C.

//    i)Insertion at the specific position.

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
void Insertion(int **arr, int *n, int pos, int x){
    *arr=(int*)realloc(*arr,(*n+1)*sizeof(int));
    if(*arr==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = *n; i > pos; i--)
    {
        (*arr)[i]=(*arr)[i-1];
    }
    (*arr)[pos]=x;
    (*n)++;
}

int main() {
    int *arr,n, pos, x, key;
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
    // Print array before Insertion
    printf("\n");
    printf("Array before insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Collecting details of Insertion
    printf("Enter the index where you want to insert: ");
    scanf("%d", &pos);
    printf("Enter the value you want to insert: ");
    scanf("%d", &x);

    //Calling function
    Insertion(&arr,&n, pos, x);

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("Enter the elemnt you want to search: ");
    scanf("%d", &key);
    int index = LinearSearch(arr, n, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    free(arr);
    return 0;
}
