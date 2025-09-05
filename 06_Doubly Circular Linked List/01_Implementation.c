#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *next;
    struct node *prev;
}n;

void create(n **head, n **tail){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    if(*head==0){
        *head=*tail=newnode;
        newnode->next=newnode->prev=*head;
    }
    else{
        (*tail)->next=newnode;
        newnode->prev=*tail;
        newnode->next=*head;
        *tail=newnode;
    }
}

void display(n *head, n *tail){
    n *temp=head;
    while(temp!=tail){
        printf("%d ", temp->val);
        temp=temp->next;
    }
    printf("%d\n",temp->val);
}
int main() {
    n *head=NULL,*tail=NULL;
    int choice;
    while(1){
        printf("1. Create\n2. Display\n3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(&head, &tail);
                break;
        case 2: display(head,tail);
                break;
        case 3: exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    
    return 0;
}
