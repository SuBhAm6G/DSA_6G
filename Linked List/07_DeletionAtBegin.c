#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

//fucntion to delete
void DelAtBegin(struct node **head){
    if(!(*head)){
        printf("List is already empty\n");
        return;
    }
    struct node *temp;
    temp=*head;
    *head=temp->next;
    free(temp);
}


//function to display
void display(struct node *head){
    printf("Linked List: ");
    struct node *temp=head;
    if(temp == NULL){
        printf("is empty.\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ->", temp->val);
        temp=temp->next;
        if (temp==NULL)
        {
            printf("NULL");
        }
        
    }
}
int main() {
    struct node *head, *newnode, *temp;
    head=0;// Initialize head to NULL
    
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
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
    
    //Displaying the linked list
    printf("Before Deletion:\n");
    display(head);
    printf("\n");

    DelAtBegin(&head);
    printf("After Deletion:\n");
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