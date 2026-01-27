#include <stdio.h>
#include <limits.h> // For INT_MIN

#define MAX_SIZE 100

// --- CORE HEAP FUNCTIONS ---

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintains heap property from top-down (Sink)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// --- PRIORITY QUEUE OPERATIONS ---

// Function to view the highest priority element
int peek(int arr[], int n) {
    if (n <= 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    return arr[0];
}

// Function to remove the highest priority element
int dequeue(int arr[], int *n) {
    if (*n <= 0) {
        printf("Queue Underflow!\n");
        return -1;
    }
    
    int maxVal = arr[0];
    
    // Move last element to root
    arr[0] = arr[*n - 1];
    (*n)--; // Decrease size
    
    // Fix the heap
    heapify(arr, *n, 0);
    
    return maxVal;
}

// Function to add an element
void enqueue(int arr[], int *n, int value) {
    if (*n >= MAX_SIZE) {
        printf("Queue Overflow!\n");
        return;
    }

    // Insert at end
    (*n)++;
    arr[*n - 1] = value;
    
    // Bubble Up (Fix the heap from bottom-up)
    int i = *n - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[i] > arr[parent]) {
            swap(&arr[i], &arr[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// --- DRIVER CODE ---

int main() {
    int pq[MAX_SIZE];
    int n = 0; // Current size of queue

    printf("--- Priority Queue Simulation ---\n");
    
    // Scenario: Tasks with priority levels
    printf("Enqueueing tasks with priority: 10, 50, 20\n");
    enqueue(pq, &n, 10);
    enqueue(pq, &n, 50);
    enqueue(pq, &n, 20);
    
    printf("Highest Priority Task: %d\n", peek(pq, n)); // Should be 50

    printf("Enqueueing Urgent Task: 100\n");
    enqueue(pq, &n, 100);
    
    printf("Processing (Dequeue): %d\n", dequeue(pq, &n)); // Should be 100
    printf("Processing (Dequeue): %d\n", dequeue(pq, &n)); // Should be 50
    
    printf("Remaining Highest: %d\n", peek(pq, n)); // Should be 20

    return 0;
}