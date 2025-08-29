//Deploy functions for operations on singly linked list: create,display,insert,delete node by value,reversing,sorting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int val;
    struct node* next;
};
//Empty?
int isEmpty(struct node *head){
    if(head==NULL)
        return 1;
    else
        return 0;
}
//getLength
int getLength(struct node *head){
    if(!(head)){
        return 0;
    }
    struct node* temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
//Display
void create(struct node **head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

//display
void display(struct node *head){
    if(isEmpty(head)){
        printf("List is Empty\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->val);
        temp=temp->next;
    }
    printf("NULL\n");
}
//insertion at any position
void insert(struct node **head,int pos){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    newnode->next=NULL;

    int len = getLength(*head);
    if(pos<1||pos>len+1){ // allow insert at end
        printf("Invalid Position\n");
        free(newnode);
        return;
    }
    if(pos==1){
        newnode->next=*head;
        *head=newnode;
        printf("%d is inserted at position %d\n",newnode->val,pos);
        return;
    }
    struct node *temp=*head;
    for (int i = 1; i < pos -1; i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("%d is inserted at position %d\n",newnode->val,pos);
}

//delete node by value
void delete(struct node **head){
    if(isEmpty(*head)){
        printf("List is empty\n");
        return;
    }
    struct node *temp=NULL;
    struct node *prev=NULL;
    int val;
    printf("Please enter the value you want to delete: "); // fixed prompt
    scanf("%d", &val);
    temp = *head; // Initialize temp to head
    if(temp != NULL && temp->val == val){ // Check if head itself holds the value
        *head=(*head)->next;
        free(temp);
        printf("Value %d deleted from the list.\n", val);
        return;
    }
    //value searching
    while(temp!=NULL && temp->val!=val){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Value %d not found in the list.\n", val);
        return;
    }
    prev->next=temp->next;
    free(temp);
    printf("Value %d deleted from the list.\n", val);
}
//reverse
void reverse(struct node **head){
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct node *first = *head;
    struct node *rest = first->next;
    reverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *head = rest;
}
//sort with bubble sort in ascending order
void sort(struct node **head){
    if(isEmpty(*head) || (*head)->next==NULL){
        printf("It's already sorted or empty\n");
        return;
    }
    struct node *i;
    int swapped;
    // Optimized bubble sort with early termination
    do {
        swapped = 0;
        for(i = *head; i->next != NULL; i = i->next){
            if(i->val > i->next->val){
                // Swap values
                int temp = i->val;
                i->val = i->next->val;
                i->next->val = temp;
                swapped = 1;
            }
        }
    } while(swapped);
}


int main() {
    struct node *head=NULL;
    int choice, val, pos;

    do {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create Node\n");
        printf("2. Display List\n");
        printf("3. Insert Node at Position\n");
        printf("4. Delete Node by Value\n");
        printf("5. Reverse List\n");
        printf("6. Sort List (Ascending)\n");
        printf("7. Get Length of List\n");
        printf("8. Check if List is Empty\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(&head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert(&head, pos);
                break;
            case 4:
                delete(&head);
                break;
            case 5:
                reverse(&head);
                printf("List reversed.\n");
                break;
            case 6:
                sort(&head);
                printf("List sorted.\n");
                break;
            case 7:
                printf("Length of the list: %d\n", getLength(head));
                break;
            case 8:
                if (isEmpty(head))
                    printf("List is empty.\n");
                else
                    printf("List is not empty.\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}
