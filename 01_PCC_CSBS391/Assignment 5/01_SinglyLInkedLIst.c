//Deploy functions for operations on singly linked list: create,display,insert,delete node by value,reversing,sorting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int val;
    struct node* next;
};
//Empty?
int isEmpty(struct node *head){
    if(head==NULL)
        return 1;
    else
        return 0;
}
//Display
void create(struct node **head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    pritnf("Enter value: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

//display
void display(struct node *head){
    if(isEmpty(head)){
        printf("List is Empty\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->val);
        temp=temp->next;
    }
    printf("NULL");
}
//insertion at any position


int main() {
    struct node *head=NULL;
    
    return 0;
}
