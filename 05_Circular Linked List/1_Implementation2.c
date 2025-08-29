#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}n;

int isEmpty(n *tail){
    if(tail==NULL)
        return 1;
    else
        return 0;
}
void create(n **tail){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter the new val: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;
    if(*tail == NULL){
        *tail=newnode;
        newnode->next=*tail;
    }
    else{
        newnode->next=(*tail)->next;
        (*tail)->next=newnode;
        *tail=newnode;
    }
    
}

void display(n *tail){
    if(isEmpty(tail)){
        printf("List is Empty\n");
    }
    else{
        n *temp=tail->next;
        while(temp->next!=tail->next){
            printf("%d ", temp->val);
            temp=temp->next;
        }
        if(temp->next==tail->next){
            printf("%d ", temp->val);
        }
        printf("\n");
    }

}
int main() {
    n *tail=NULL;
    int choice;
    while(1){
        printf("1. Create\n2. Display\n3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(&tail);
                break;
        case 2: display(tail);
                break;
        case 3: exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}
