//Implement Tower of Hanoi recursively in C.
#include <stdio.h>

void TOH(int n,char A, char B, char C){
    if(n==1){
        printf("Move disk %d from %c rod to %c rod\n", n, A, C);
        return;
    }
    TOH(n-1, A, C, B);
    printf("Move disk %d from %c rod to %c rod\n", n-1, A, C);
    TOH(n-1, B, A, C);
}

int main(){
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    TOH(num, 'A', 'B', 'C');
    return 0;
}
