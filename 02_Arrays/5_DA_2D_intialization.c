#include <stdio.h>
#include <stdlib.h>

int main() {
    int r,c;
    int **arr;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);
    arr=(int**)malloc(r*sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        arr[i]=(int*)malloc(c*sizeof(int));
    }
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("You entered:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    // Free allocated memory
    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }
    
    return 0;
}