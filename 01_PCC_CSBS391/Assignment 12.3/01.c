// 1. Write a C program for Collision avoidance in Hash table using Linear Probing.
// Note: No global variable or pointer will be allowed.
#include <stdio.h>
#include <stdlib.h>

int hash_func(int key, int n){
    return key%n;
}
void insert(int hash[],int n, int key){
    int idx=hash_func(key,n);
    for (int i = 0; i < n; i++)
    {
        int probe_idx=(idx+i)%n;
        if(hash[probe_idx]==-1){
            hash[probe_idx]=key;
            printf("%d is inserted at index: %d\n",key,probe_idx);
            return;
        }
    }
    printf("No space left\n");
}

void search(int hash[],int n, int key){
    int idx=hash_func(key,n);
    for (int i = 0; i < n; i++)
    {
        int probe_idx=(idx+i)%n;
        if(hash[probe_idx]==key){
            printf("%d is found at index: %d\n",key,probe_idx);
            return;
        }
        else if(hash[probe_idx]==-1){
            printf("%d is not found\n",key);
            return;
        }
    }
    printf("%d is not found\n",key);
}
    
void display(int hash[],int n){
    for (int i = 0; i < n; i++)
    {
        if(hash[i]!=-1){
            printf("Index %d: %d ",i,hash[i]);
        }
        else{
            printf("Index %d: Empty ",i);
        }
    }
}
int main() {
    int n;
    printf("Enter size of Hash Table: ");
    scanf("%d", &n);
    int *hash=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        hash[i]=-1;
    }
    int choice, key;
    while (1) {
        printf("Menu:\n");
        printf("1. Insert | ");
        printf("2. Search | ");
        printf("3. Display | ");
        printf("4. Exit | ");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(hash, n, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(hash, n, key);
                break;
            case 3:
                display(hash, n);
                break;
            case 4:
                free(hash);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    
    
    return 0;
}
