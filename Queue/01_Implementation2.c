//Using dynamic array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty(int *front, int *rear){
    if(*front==-1 && *rear==-1)
        return 1;
    else
        return 0;
}

int isFull(int n, int *rear){
    if(*rear==n-1)
        return 1;
    else
        return 0;
}

void enqueue(int *queue,int n, int *front, int *rear, int val){
    if(isFull(n, rear)){
        printf("Overflow\n");
        return;
    }
    else if(isEmpty(front, rear)){
        *front=*rear=0;
        queue[*rear]=val;
    }
    else{
        queue[++(*rear)]=val;
    }
}

void dequeue(int *queue, int *front, int *rear){
    if(isEmpty(front, rear)){
        printf("Underflow\n");
        return;
    }
    else if(*front==*rear){
        printf("Element %d is removed\n", queue[*front]);
        *front=*rear=-1;
    }
    else{
        printf("Element %d is removed\n", queue[*front]);
        (*front)++;
    }
}

void display(int *queue, int *front, int *rear){
    if(isEmpty(front, rear)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for(int i = *front; i <= *rear; i++){
        printf("%d ", queue[i]);
    }
        printf("\n");
}

void peek(int *queue, int *front, int *rear){
    if(isEmpty(front, rear)){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is: %d\n", queue[*front]);
}

int main() {
    int *queue,n,front=-1,rear=-1;   
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    queue=(int*)malloc(n*sizeof(int));
    if(!queue){
        printf("Memory allocation failed\n");
        return 1;
    }
    int choice,value;
    while(1){
        printf("\n\n*********MENU*********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue,n,&front,&rear,value);
                break;
            case 2:
                dequeue(queue,&front,&rear);
                break;
            case 3:
                peek(queue,&front,&rear);
                break;
            case 4:
                display(queue,&front,&rear);
                break;
            case 5:
                free(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}
