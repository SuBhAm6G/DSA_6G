#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

void InsAtEnd(struct node **head){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));//memory is allocated, so the value stays even after end of function
    if(!newnode){
        printf("Memory allocation failed!\n");
        return; // Exit if malloc fails
    }
    printf("Enter the data(for insertion at end): ");
    if (scanf("%d", &newnode->val) != 1) {
        printf("Invalid input.\n");
        free(newnode); // Free the allocated node to prevent memory leak
        return;
    }
    newnode->next=NULL;

    // If the list is empty, the new node becomes the head.
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    // Otherwise, traverse to the end of the list.
    struct node *last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    // Link the last node to the new node.
    last->next = newnode;
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
    printf("Before Insertion:\n");
    display(head);
    printf("\n");

    InsAtEnd(head);//passing only copy of head, since we are inserting at the end, we don't need to change the head pointer
    printf("After Insertion:\n");
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