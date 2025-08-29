#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
}n;

int isEmpty(struct node *head){
    if(head==NULL) 
        return 1;
    else
        return 0;
}

int getLength(struct node *head){
    int length=0;
    struct node *temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void create(struct node **head, struct node **tail){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next=newnode->prev=NULL;
    if(*head==NULL){
        *head=*tail=newnode;
    }
    else{
        (*tail)->next=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
}

void Reverse(n **head, n **tail){
    if(isEmpty(*head)){
        printf("Empty List\n");
        return;
    }
    n *current=*head, *next;
    while(current!=NULL){
        next=current->next;
        current->next=current->prev;
        current->prev=next;
        current=next;
    }
    current=*head;
    *head=*tail;
    *tail=current;
}

void display(struct node *head){
    if(isEmpty(head)){
        printf("List is Empty\n");
        return;
    }
    struct node *temp=head;
    printf("Doubly Linked List: ");
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
        if(temp!=NULL){
            printf("<-> ");
        }
    }
    printf("NULL\n");
}
int main() {
    struct node *head=NULL,*tail=NULL;
    int choice;
    while(1){
        printf("1. Create\n2. Reverse\n3. Display\n4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(&head,&tail);
                break;
        case 2: Reverse(&head,&tail);
                break;
        case 3: display(head);
                break;
        case 4: exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}

