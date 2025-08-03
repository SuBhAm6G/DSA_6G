//  Write a program in C to implement a menu driven stack application. 
#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;
void push(int val){
    if(top>=MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=val;
        printf("%d pushed to stack\n", val);
    }
}

void pop(){
    if(top<0){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d popped from stack", stack[top--]);
    }
}

void display(){
    if(top<0){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack Elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
        
    }
}
int main(){
    int choice, val;
    while(1){
        printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Value to Push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}