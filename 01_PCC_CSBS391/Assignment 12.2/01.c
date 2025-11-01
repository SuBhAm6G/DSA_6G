#include <stdio.h>
#include <stdlib.h>

void merge(int *arr,int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        L[i]=arr[l+i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=l;
    while (i<n1 && j<n2)
    {
        if(L[i]<R[j]){
            arr[k]=L[i++];
        }
        else{
            arr[k]=R[j++];
        }
        k++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
    free(L);
    free(R);
}

void mergesort(int *arr,int l, int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergesort(arr,0,n-1);
    printf("Array after sorting:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    
    return 0;
}
