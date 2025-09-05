// A) Implement Doubly Linked List and perform insertion and deletion from front and end, display and reverse in C.
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *prev;
    struct node *next;
}n;

int isEmpty(n *head){
    return head == NULL;
}

void create(n **head, n **tail){
    n *newnode = (n*)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    newnode->prev = newnode->next = NULL;
    if(isEmpty(*head)){
        *head = *tail = newnode;
        return;
    }
    (*tail)->next = newnode;
    newnode->prev = *tail;
    *tail = newnode;
}

void display(n *head){
    if(isEmpty(head)){
        printf("List is empty\n");
        return;
    }
    n *temp = head;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void InsAtFront(n **head, n **tail){
    n *newnode = (n*)malloc(sizeof(n));
    printf("Enter value: ");
    scanf("%d", &newnode->val);
    newnode->prev = NULL;
    newnode->next = *head;
    if(isEmpty(*head)){
        *head = *tail = newnode;
        return;
    }
    (*head)->prev = newnode;
    *head = newnode;
}

void insAtEnd(struct node **head, struct node **tail){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->val);
    newnode->next=newnode->prev=NULL; 
    if(isEmpty(*head)){
        *head=newnode;
        *tail=newnode;
    }
    else{
        (*tail)->next=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
}

void deleteFront(n **head, n **tail){
    if(isEmpty(*head)){
        printf("List is empty\n");
        return;
    }
    n *temp = *head;
    if(*head == *tail){
        *head = *tail = NULL;
    } 
    else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteEnd(n **head, n **tail){
    if(isEmpty(*tail)){
        printf("List is empty\n");
        return;
    }
    n *temp = *tail;
    if(*head == *tail){
        *head = *tail = NULL;
    } else {
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }
    free(temp);
}

void Reverse(n **head, n **tail){
    if(isEmpty(*head)){
        printf("Empty List\n");
        return;
    }
    n *current=*head, *next;
    while(current!=NULL){
        next=current->next;
        current->next=current->prev;
        current->prev=next;
        current=next;
    }
    current=*head;
    *head=*tail;
    *tail=current;
}

int main() {
    n *head = NULL, *tail = NULL;
    int choice;
    while(1){
        printf("\nMenu:\n");
        printf("1. Create | 2. Display | 3. Delete from Front | 4. Delete from End | 5. Insert at Front | 6. Insert At End | 7. Reverse | 8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create(&head, &tail);
                break;
            case 2:
                printf("The new list is: ");
                display(head);
                break;
            case 3:
                deleteFront(&head, &tail);
                printf("The new list is: ");
                display(head);
                break;
            case 4:
                deleteEnd(&head, &tail);
                printf("The new list is: ");
                display(head);
                break;
            case 5:
                InsAtFront(&head, &tail);
                printf("The new list is: ");
                display(head);
                break;
            case 6:
                insAtEnd(&head, &tail);
                printf("The new list is: ");
                display(head);
                break;
            case 7:
                Reverse(&head, &tail);
                printf("The new list is: ");
                display(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    };
    return 0;
}

