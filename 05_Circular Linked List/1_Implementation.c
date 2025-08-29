#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}n;

int isEmpty(n *head){
    if(head==NULL)
        return 1;
    else
        return 0;
}
void create(n **head){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter the new val: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;
    if(*head == NULL){
        *head=newnode;
        newnode->next=*head;
    }
    else{
        n *temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;
        temp->next=*head;
    }
    
}

void display(n *head){
    n *temp;
    if(isEmpty(head)){
        printf("List is Empty\n");
    }
    else{
        temp=head;
        do{
            printf("%d ", temp->val);
            temp=temp->next;
        }while(temp!=head);
        printf("\n");
    }

}
int main() {
    n *head=NULL;
    int choice;
    while(1){
        printf("1. Create\n2. Display\n3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(&head);
                break;
        case 2: display(head);
                break;
        case 3: exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}
