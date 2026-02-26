#include <stdio.h>

#define SIZE 7
#define EMPTY -1

int hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// TODO: Write this function
// 1. Calculate original hash index.
// 2. Loop: Check if current index is empty. If yes, insert and break.
// 3. If not empty, move to next index: idx = (idx + 1) % SIZE.
// 4. Important: Prevent infinite loops if table is full! 
void insert(int key) {
    // Your code here
    int idx=key%SIZE;
    int i=0;
    while(i<SIZE){
        if (hashTable[idx]==EMPTY){
            hashTable[idx]=key;
            return;
        }
        idx=(idx+1)%SIZE;
        i++;
    }
    if (i>=SIZE) printf("OVERFLOW");
}

// TODO: Write this function
// 1. Calculate original hash index.
// 2. Loop: Check if hashTable[idx] == key. If yes, return 1.
// 3. If hashTable[idx] == EMPTY, the element doesn't exist. return 0.
// 4. Move to next index: idx = (idx + 1) % SIZE.
// 5. Prevent infinite loops.
int search(int key) {
    // Your code here
    int idx=key%SIZE;
    int i=0;
    while(i<SIZE){
        if (hashTable[idx]==EMPTY){
            return 0;
        }
        else if (hashTable[idx]==key){
            return 1;
        }
        else idx=(idx+1)%SIZE;
        i++;
    }
    return 0;
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    initTable();
    
    // Size is 7. Let's force some collisions.
    insert(10); // 10 % 7 = 3
    insert(17); // 17 % 7 = 3 (Collision -> 4)
    insert(24); // 24 % 7 = 3 (Collision -> 5)
    
    printTable();
    
    printf("\nSearch 17: %s\n", search(17) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");
    
    return 0;
}