#include <stdio.h>
int main(){
    int arr[10]={1,2,3,4,5}, pos, num, size;
    printf("Enter the size of array: \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the position where you want to insert an element: ");
    scanf("%d", &pos);
    printf("Enter the element you want to insert: ");
    scanf("%d", &num);
    //Shifting
    for (int i = size-1; i >=pos-1; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;//Inserting
    size++;
    printf("New array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
return 0;
}
//Best Case for Unsorted Array:-----

//arr[size]=arr[pos-1];
//arr[pos-1]=num;