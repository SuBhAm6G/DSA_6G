// A. Write a menu driven c program to implement linear queue using array.
#include <stdio.h>
#include <stdlib.h>

int isFull(int *rear, int n){
    if(*rear==n-1)
        return 1;
    else
        return 0;
}

int isEmpty(int *front, int *rear){
    if(*rear==-1 && *front==-1)
        return 1;
    else    
        return 0;
}

void enqueue(int *queue,int *front, int *rear, int n, int val){
    if(isFull(rear, n)){
        printf("Queue is full\n");
    }
    else if(*rear==-1 && *front==-1){
        *rear=*front=0;
        queue[*rear]=val;
    }
    else{
        queue[++(*rear)]=val;
    }
}

void dequeue(int *queue,int *front, int *rear, int n){
    if(isEmpty(front,rear)){
        printf("Queue is empty\n");
    }
    else if(*front==*rear){
        printf("%d is dequeued", queue[*front]);
        *front=*rear=-1;
    }
    else{
        printf("%d is dequeued", queue[*front]);
        (*front)++;
    }
}

void peek(int *queue, int *front, int *rear){
    if(isEmpty(front,rear)){
        printf("Queue is Empty");
    }
    else{
        printf("The element at front is %d", queue[*front]);
    }
}

void display(int *queue, int *front, int *rear){
    if(isEmpty(front,rear)){
        printf("Queue is Empty");
    }
    else{
        for(int i=*front; i<=*rear; i++){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}
int main(){
    int *queue,n=5,val;
    int front=-1;
    int rear=-1;
    queue=(int*)malloc(n*sizeof(int));
    while(1){
    printf("*****Menu*****\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            enqueue(queue, &front, &rear, n, val);
            break;
        case 2:
            dequeue(queue, &front, &rear, n);
            break;
        case 3:
            peek(queue, &front, &rear);
            break;
        case 4:
            display(queue, &front, &rear);
            break;
        case 5:
            printf("Exiting the program....\n");
            free(queue);
            exit(0);
        default:
            printf("Invalid Choice");
            break;
    }
    }
    return 0;
}