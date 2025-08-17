//Using linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int val;
    struct node* next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int value){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val=value;
    newnode->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void display(){
    struct node* temp;
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    temp=front;
    while(temp!=NULL){
        printf("%d ",temp->val);
    temp=temp->next;
    }
    printf("\n");
}

void dequeue(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp;
    temp=front;
    printf("%d element is removed\n", temp->val);
    front=front->next;
    // if queue becomes empty, set rear to NULL too
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void peek(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("%d is the front element\n", front->val);
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
