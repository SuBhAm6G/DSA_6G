#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *next;
    struct node *prev;
}n;

int isEmpty(n *head){
    if(head==NULL)
        return 1;
    else
        return 0;
}
int getLength(n *head, n *tail){
    if(isEmpty(head))
        return 0;
    else{
        int count=1;
        n *temp=head;
        while(temp!=tail){
            count++;
            temp=temp->next;
        }
        return count;
    }
}
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
void InsAtBegin(n **head, n **tail){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    if(isEmpty(*head)){
        *head=*tail=newnode;
        newnode->next=newnode->prev=newnode;
        return;
    }
    newnode->next=*head;
    (*head)->prev=newnode;
    newnode->prev=*tail;
    (*tail)->next=newnode;
    *head=newnode;
}

void InsAtEnd(n **head, n **tail){
    if(isEmpty(*head)){
        InsAtBegin(head, tail);
        return;
    }
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    newnode->prev=*tail;
    newnode->next=*head;
    (*tail)->next=newnode;
    (*head)->prev=newnode;
    *tail=newnode;
}

void InsAtPos(n **head, n **tail){
    if(isEmpty(*head)){
        printf("List is Empty\n");
        return;
    }
    int pos;
    printf("Enter the position you want to enter: ");
    scanf("%d", &pos);
    int len=getLength(*head, *tail);
    if(pos<1 || pos>len+1){
        printf("Invalid Position\n");
        return;
    }
    if(pos==1){
        InsAtBegin(head, tail);
        return;
    }
    if(pos==len+1){
        InsAtEnd(head, tail);
        return;
    }
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    n *temp=*head;
    for (int i = 1; i < pos -1; i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp; 
}
void display(n *head, n *tail){
    if(isEmpty(head)){
        printf("List is Empty\n");
        return;
    }
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
        printf("1. Create\n2. Display\n3. Insert at Begin\n4. Insert at End\n5. Insert at Position\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: create(&head, &tail);
                break;
        case 2: display(head,tail);
                break;
        case 3: InsAtBegin(&head, &tail);
                break;
        case 4: InsAtEnd(&head, &tail);
                break;
        case 5: InsAtPos(&head, &tail);
                break;
        case 6: exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
