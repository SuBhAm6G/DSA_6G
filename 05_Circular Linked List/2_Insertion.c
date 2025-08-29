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
int getLength(n *tail){
    if(isEmpty(tail)){
        return 0;
    }
    int count=1;
    n *temp=tail->next;
    while(temp->next!=tail->next){
        count++;
        temp=temp->next;
    }
    return count;
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

void InsAtBegin(n **tail){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter data: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;
    if(isEmpty(*tail)){
        *tail=newnode;
        newnode->next=*tail;
    }
    else{
        newnode->next=(*tail)->next;
        (*tail)->next=newnode;
    }
}
void InsAtEnd(n **tail){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter data: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;
    if(isEmpty(*tail)){
        *tail=newnode;
        newnode->next=*tail;
    }
    else{
        newnode->next=(*tail)->next;
        (*tail)->next=newnode;
        *tail=newnode;
    }
}
void InsAtPos(n **tail, int pos){
    if(pos<1 || pos>getLength(*tail)+1){
        printf("Invalid Position\n");
    }
    else if(pos==1){
        InsAtBegin(tail);
    }
    else if(pos==getLength(*tail)+1){
        InsAtEnd(tail);
    }
    else{
        n *newnode=(n*)malloc(sizeof(n));
        printf("Enter data: ");
        scanf("%d", &newnode->val);
        newnode->next=NULL;
        n *temp=(*tail)->next;
        for (int i = 1; i < pos-1; i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
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
    n *tail = NULL;
    int choice, pos;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create (Insert at End)\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create(&tail);
                break;
            case 2:
                display(tail);
                break;
            case 3:
                InsAtBegin(&tail);
                break;
            case 4:
                InsAtEnd(&tail);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                InsAtPos(&tail, pos);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
