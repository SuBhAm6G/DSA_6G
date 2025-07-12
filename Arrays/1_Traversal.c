#include <stdio.h>
#define N 50
int main(){
    int arr[N],size;
    printf("Enter the size of array: \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element of arr[%d]", i+1);
        scanf("%d", &arr[i]);
    }
    //Traversal through printing
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

return 0;
}