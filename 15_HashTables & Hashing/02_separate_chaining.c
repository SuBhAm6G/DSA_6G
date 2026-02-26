#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Linked List Node
struct Node {
    int key;
    struct Node* next;
};

// The Hash Table (Array of Pointers)
struct Node* hashTable[SIZE];

// Initialize table with NULL
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

// TODO: Write this function
// 1. Calculate hash index. 2. Create new node. 3. Insert at HEAD of the list at that index.
void insert(int key) {
    // Your code here
    int idx=key% SIZE;
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->key=key;
    newnode->next=hashTable[idx];
    hashTable[idx]=newnode;
}

// TODO: Write this function
// 1. Calculate hash index. 2. Traverse the linked list at that index to find the key.
// Return 1 if found, 0 if not found.
int search(int key) {
    // Your code here
    int idx=key% SIZE;
    struct Node* x=hashTable[idx];
    while(x!=NULL){
        if(x->key==key){
            return 1;
        }
        x=x->next;
    }
    return 0;

}

// Delete a key from the hash table
void delete(int key) {
    int idx = key % SIZE;
    struct Node* temp = hashTable[idx];
    struct Node* prev = NULL;
    
    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                hashTable[idx] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Function to print the table (for visualization)
void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("[%d] -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initTable();
    
    insert(12);
    insert(22);
    insert(15);
    insert(25);
    insert(32);
    
    printTable();
    
    printf("\nSearch 22: %s\n", search(22) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");
    
    return 0;
}