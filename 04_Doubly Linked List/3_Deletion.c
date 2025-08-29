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

void delAtBegin(struct node **head, struct node **tail){
    if(isEmpty(*head)){
        printf("List is Empty\n");
        return;
    }
    else if(getLength(*head)==1){
        *head=*tail=NULL;
        return;
    }
    struct node *temp=*head;
    *head=temp->next;
    (*head)->prev=NULL;
    free(temp);
}

void delAtEnd(struct node **head, struct node **tail){
    if(isEmpty(*head)){
        printf("List is Empty\n");
        return;
    }
    else if(getLength(*head)==1){
        *head=*tail=NULL;
    }
    else{
        struct node *temp=*tail;
        (*tail)->prev->next=NULL;
        *tail=(*tail)->prev;
        free(temp);
    }
}

void delByVal(struct node **head, struct node **tail, int val){
    struct node *temp;
    for (temp=*head; temp!=NULL; temp=temp->next)
    {
        if(temp->val==val){
            break;
        }
    }
    if(temp==NULL){
        printf("Value not found\n");
        return;
    }
    if(temp==*head){
        delAtBegin(head, tail);
        return;
    }
    if(temp==*tail){
        delAtEnd(head, tail);
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void delByPos(struct node **head, struct node **tail, int pos){
    if(isEmpty(*head)){
        printf("List is Empty\n");
        return;
    }
    int len = getLength(*head);
    if(pos < 1 || pos > len){
        printf("Invalid position\n");
        return;
    }
    if(pos == 1){
        delAtBegin(head, tail);
        return;
    }
    if(pos == len){
        delAtEnd(head, tail);
        return;
    }
    struct node *temp = *head;
    for(int i = 1; i < pos; i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
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
    head = tail = NULL;
    int choice, val, pos;
    while (1) {
        printf("\n1.Create\n2.Delete at beginning\n3.Delete at end\n4.Delete by value\n5.Delete by position\n6.Display\n7.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(&head, &tail);
                    break;
            case 2: delAtBegin(&head, &tail);
                    if (head == NULL) tail = NULL;
                    break;
            case 3: delAtEnd(&head, &tail);
                    break;
            case 4: printf("Enter the value to delete: ");
                    scanf("%d", &val);
                    delByVal(&head, &tail, val);
                    break;
            case 5: printf("Enter the position to delete: ");
                    scanf("%d", &pos);
                    delByPos(&head, &tail, pos);
                    break;
            case 6: display(head);
                    break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}