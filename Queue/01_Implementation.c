//Static Array
#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int rear=-1;
int front=-1;

//isFull function
int isFull(){
    if(rear==N-1)
        return 1;
    else
        return 0;
}

//isEmpty 
int isEmpty(){
    if(rear==-1 && front==-1)
        return 1;
    else   
        return 0;
}

//enqueue from rear
void enqueue(int value){
    if (isFull())
    {
        printf("Overflow");
    }
    //first element insertion
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=value;
    }
    else{
        queue[++rear]=value;
    }
}

//dequeue from front
void dequeue(){
    //Empty Condition
    if(isEmpty()){
        printf("Underflow");
    }
    //one element in queue
    else if(front==rear){
        printf("Element %d is removed", queue[front]);
        front=rear=-1;
    }
    //multiple elements
    else{
        printf("Element %d is removed", queue[front]);
        front++;
    }
}
//peek
void peek(){
    if(isEmpty()){
        printf("Queue is empty");
    }
    else{
        printf("%d", queue[front]);
    }
}
//display
void display(){
    if(isEmpty()){
        printf("Queue is empty");
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("|%d", queue[i]);
        }
    }
}
int main() {
    int choice, value;
    while(1){
        printf("\n\n*********MENU*********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }

    
    return 0;
}
