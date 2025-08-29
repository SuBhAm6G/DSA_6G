//Iterative Method
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

void Reverse(struct node **head){
    struct node *prevnode, *currentnode, *nextnode;
    prevnode=NULL;
    currentnode=nextnode=*head;
    while (nextnode)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    *head=prevnode;
}

void display(struct node *head){
    if(!(head)){
        printf("List is empty!\n");
        return;
    }
    struct node *temp=head;
    while(temp){
        printf("%d ",temp->val);
        temp=temp->next;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL\n");
}
int main() {
    struct node *head, *newnode, *temp;
    head=0;
    
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        if(!newnode){
            printf("Memory allocation failed!\n");
            break;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->val);
        newnode->next=0;
        if(head==0){head=temp=newnode;}
        else{temp->next=newnode;temp=newnode;
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
    
    //Displaying the linked list
    printf("Linked List: ");
    temp=head;
    while(temp!=NULL){
        printf("%d ->", temp->val);
        temp=temp->next;
        if (temp==NULL)
        {
            printf("NULL");
        }
    }

    printf("List before reversing:\n");
    display(head);
    Reverse(&head);
    printf("\nList after reversing:\n");
    display(head);

    //Freeing the memory
    temp=head;
    while (temp!=NULL)
    {
        struct node *next=temp->next;
        free(temp);
        temp=next;
    } 
    return 0;
}