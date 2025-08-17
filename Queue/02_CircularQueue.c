#include <stdio.h>
#include <stdlib.h>
#define N 5
int arr[N];
int front=-1;
int rear=-1;
void enqueue(int value){
    if((rear+1)%N==front){
        printf("Queue is full");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        arr[rear]=value;
    }
    else{
        rear=(rear +1)%N;
        arr[rear]=value;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("front to rear linear queue is:\n");
        int i=front;
        while(i!=rear){
            printf("%d ",arr[i]);
            i=(i+1)%N;
        }
        printf("%d ",arr[rear]);

        printf("\nBut according to index: ");
        for(int i=0;i<N;i++){
            printf("%d ",arr[i]);
        }
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("Element %d is removed\n", arr[front]);
        int temp=front;
        arr[temp]='\0';
        front=(front+1)%N;
    }
}

int main() {
    int choice, value;
    while(1){
        printf("\n\n*********MENU*********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n"); // Added Display option
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
            case 3: // Added case for Display
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }


    return 0;
}
