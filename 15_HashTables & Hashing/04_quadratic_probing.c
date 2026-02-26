#include <stdio.h>

#define SIZE 7 // Prime numbers are best for Quadratic Probing
#define EMPTY -1

int hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// TODO: Write the math for Quadratic Probing insertion
void insert_quadratic(int key) {
    int original_idx = key % SIZE;
    int i = 0;
    
    while(i < SIZE) {
        // Calculate the quadratic index for this attempt
        int idx = (original_idx + (i*i))%SIZE; 
        if (hashTable[idx] == EMPTY) {
            hashTable[idx] = key;
            return;
        }
        i++;
    }
    printf("OVERFLOW OR STUCK IN CYCLE FOR KEY %d\n", key);
}

// TODO: Write the math for Quadratic Probing search
int search_quadratic(int key) {
    int original_idx = key % SIZE;
    int i = 0;
    
    while(i < SIZE) {
        // Calculate the quadratic index for this attempt
        int idx = (original_idx + (i*i))%SIZE; 
        
        if (hashTable[idx] == EMPTY) {
            return 0; // Found an empty spot, so it doesn't exist
        }
        else if (hashTable[idx] == key) {
            return 1; // Found it!
        }
        i++;
    }
    return 0; // Table full and not found
}

void printTable() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    initTable();
    
    // Let's force some collisions to test the quadratic jumps!
    // 10 % 7 = 3
    // 17 % 7 = 3 (Collision 1: should jump to 3 + 1^2 = 4)
    // 24 % 7 = 3 (Collision 2: should jump to (3 + 2^2) % 7 = 0)
    
    insert_quadratic(10); 
    insert_quadratic(17); 
    insert_quadratic(24); 
    
    printf("--- Quadratic Probing Table ---\n");
    printTable();
    
    printf("\nSearch 17: %s\n", search_quadratic(17) ? "Found" : "Not Found");
    printf("Search 24: %s\n", search_quadratic(24) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search_quadratic(99) ? "Found" : "Not Found");
    
    return 0;
}