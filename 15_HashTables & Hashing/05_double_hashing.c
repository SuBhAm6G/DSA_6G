#include <stdio.h>

#define SIZE 7 
#define PRIME 5 // The smaller prime for h2
#define EMPTY -1

int hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return PRIME - (key % PRIME);
}

// TODO: Write the logic for Double Hashing insertion
void insert_double(int key) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    int i = 0;
    
    while(i < SIZE) {
        // Calculate the double hashing index
        int idx =(hash1(key) + i*hash2(key))%SIZE;
        
        if (hashTable[idx] == EMPTY) {
            hashTable[idx] = key;
            return;
        }
        i++;
    }
    printf("OVERFLOW: Could not insert %d\n", key);
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    initTable();
    
    // We will use the exact numbers from our dry run
    insert_double(10); 
    insert_double(17); 
    insert_double(24); 
    
    printf("--- Double Hashing Table ---\n");
    printTable(); // Look for 10 at index 3, 24 at index 4, and 17 at index 6!
    
    return 0;
}