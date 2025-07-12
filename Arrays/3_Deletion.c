#include <stdio.h>
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9}, pos, num, size;
    printf("Enter the size of array: \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the position where you want to delete an element: ");
    scanf("%d", &pos);
    //Deletion through shifting to maintain order
    for (int i = pos-1; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    
    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
return 0;
}
//For unordered array:----

//arr[pos-1]=arr[size];
//size--;