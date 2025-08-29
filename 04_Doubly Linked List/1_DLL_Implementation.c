#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node *prev;
    struct node *next;
};
int isEmpty(struct node *head){
    if(head==NULL)
        return 1;
    else 
        return 0;
}
void create(struct node **head){
    struct node *newnode;
    struct node *temp=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value to add: ");
    scanf("%d", &newnode->val);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        temp=*head;
        //traverse temp until it reaches end
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void displayFor(struct node *head){
    if(isEmpty(head)){
        printf("List is empty!\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp=temp->next;
    }
}
int main() {
    struct node *head=NULL;
    while(1){
        int choice;
        printf("Do you want to add a node? (1/0): ");
        scanf("%d", &choice);
        if(choice==1){
            create(&head);
        }
        else{
            break;
        }
    }
    printf("Linked List: ");
    displayFor(head);
    return 0;
}
