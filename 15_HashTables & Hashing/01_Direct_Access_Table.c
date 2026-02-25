#include <stdio.h>

#define MAX_KEYS 10 // Universe of keys is 0 to 9

// 9.2.1 Initialize Table
// TODO: Write this function to set all elements in T to -1
void initTable(int T[], int size) {
    // Your code here
    for(int i=0; i<MAX_KEYS; i++){
        T[i]=-1;
    }
}

// 9.2.3 Insert Element
// TODO: Write this function to insert value at index 'key'
void insert(int T[], int key, int value) {
    // Your code here
    T[key]=value;
}

// 9.2.2 Search Element
// TODO: Write this function to return the value at 'key', or print "Not found" and return -1 if empty
int search(int T[], int key) {
    // Your code here
    if(T[key]==-1){
        printf("Not Found\n");
        return -1;
    }
    else return T[key];
}

// 9.2.4 Delete Element
// TODO: Write this function to set the slot at 'key' back to -1
void deleteKey(int T[], int key) {
    // Your code here
    T[key]=-1;
}

int main() {
    int T[MAX_KEYS];
    
    initTable(T, MAX_KEYS);
    
    insert(T, 5, 500);
    insert(T, 2, 200);
    insert(T, 9, 900);
    
    printf("Value at key 5: %d\n", search(T, 5));
    printf("Value at key 3: %d\n", search(T, 3)); // Should say not found
    
    deleteKey(T, 2);
    printf("Value at key 2 after deletion: %d\n", search(T, 2)); // Should say not found
    
    return 0;
}