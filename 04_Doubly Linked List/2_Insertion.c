#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
    struct node *prev;
};

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

void insAtBegin(struct node **head){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next=newnode->prev=NULL; 
    if(isEmpty(*head)){
        *head=newnode;
    }
    else{
        (*head)->prev=newnode;
        newnode->next=*head;
        *head=newnode;
    }
}
void insAtEnd(struct node **head, struct node **tail){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next=newnode->prev=NULL; 
    if(isEmpty(*head)){
        *head=newnode;
    }
    else{
        (*tail)->next=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
}
void insAtPos(struct node **head, int pos){
    if(pos<1 || pos > getLength(*head)){
        printf("Invalid Position\n");
    }
    else if(isEmpty(*head) || pos==1){
        insAtBegin(head);
    }
    else{
        struct node *newnode, *temp=*head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next=newnode->prev=NULL; 
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next->prev=newnode;
    }

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
    struct node *head, *tail;
    head=tail=NULL;
    int choice;
    int pos;
    while(1){
        printf("\n1.Create\n2.Insert at beginning\n3.Insert at end\n4.Insert at specific position\n5.Display\n6.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: create(&head, &tail);
                    break;
            case 2: insAtBegin(&head);
                    break;
            case 3: insAtEnd(&head, &tail);
                    break;
            case 4: 
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    insAtPos(&head, pos);
                    break;
            case 5: display(head);
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
