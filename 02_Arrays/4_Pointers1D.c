#include <stdio.h>

int main() {
    int a[5] = {11, 2, 3, 4, 5}; // Initialize an array of integers

    // Accessing the third element of the array (index 2)
    printf("a[2]=%d\n", a[2]);            // Output: 3
    printf("*(a+2)=%d\n", *(a+2));        // Output: 3 (pointer arithmetic)
    printf("*(2+a)=%d\n", *(2+a));        // Output: 3 (same as above)
    printf("2[a]=%d\n", 2[a]);            // Output: 3 (array indexing is commutative)

    printf("\n");

    // Loop through the array to print each element and its address
    for (int i = 0; i < 5; i++) {
        printf("a[%d]=%d @%p\n", i, a[i], (void*)&a[i]); 
        // Output: Element value and address for each index
    }

    printf("\n");

    // Print the address of the entire array and its first element
    printf("&a=%p\n", &a);                // Output: Address of the array
    printf("&a+1=%p\n", (&a + 1));        // Output: Address after the array
    printf("&a[0]+1=%p\n", (&a[0] + 1));  // Output: Address of the second element
    printf("4&a[0]+1=%d\n", 4 & a[0] + 1); // Output: Bitwise AND operation (undefined behavior)

    printf("\n");

    // Demonstrate dereferencing the array
    printf("*a=%d\n", *a);                       // Output: 11 (first element)
    printf("*(a+1)=%d\n", *(a+1));               // Output: 2 (second element)
    printf("*a+1=%d\n", *a+1);                   // Output: 12 (first element + 1)

    printf("\n");

    int *p = a; // Pointer to the first element of the array
    printf("*p=%d\n", *p);                       // Output: 11 (value at pointer)
    printf("*p*2=%d\n", *p * 2);                 // Output: 22 (value at pointer multiplied by 2)

    // Additional operations demonstrating pointer behavior
    printf("%d\n", a[0,3]); // Output: Undefined behavior, should be avoided
    printf("%d\n", *p++);   // Output: 11 (current value), then increments pointer
    printf("%d\n", (*p)++); // Output: 2 (current value), then increments the value at pointer

    int (*pa)[5] = &a; // Pointer to the entire array
    int *q=a;
    printf("\n%d", q[0]);
    return 0; // Return 0 to indicate successful execution
}