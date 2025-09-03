// Circular Linked List implementation in C with insertion, deletion, and display functions
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} n;

int isEmpty(n *tail) {
    return (tail == NULL);
}

void create(n **tail){
    n *newnode = (n*)malloc(sizeof(n));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter value of newnode:");
    scanf("%d", &newnode->val);
    if(isEmpty(*tail)){
        *tail = newnode;
        newnode->next = newnode;
        return;
    }
    newnode->next = (*tail)->next;
    (*tail)->next = newnode;
    *tail = newnode;
}

void InsAtEnd(n **tail, int value) {
    n *newnode = (n *)malloc(sizeof(n));
    newnode->val = value;
    if (isEmpty(*tail)) {
        *tail = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = (*tail)->next;
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

void InsAtBegin(n **tail, int value) {
    n *newnode = (n *)malloc(sizeof(n));
    newnode->val = value;
    if (isEmpty(*tail)) {
        *tail = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = (*tail)->next;
        (*tail)->next = newnode;
    }
}

void InsAtPos(n **tail, int value, int pos) {
    if (pos <= 1 || isEmpty(*tail)) {
        InsAtBegin(tail, value);
        return;
    }
    n *temp = (*tail)->next;
    int i = 1;
    while (i < pos - 1 && temp != *tail) {
        temp = temp->next;
        i++;
    }
    n *newnode = (n *)malloc(sizeof(n));
    newnode->val = value;
    newnode->next = temp->next;
    temp->next = newnode;
    if (temp == *tail)
        *tail = newnode;
}

void DelAtBegin(n **tail) {
    if (isEmpty(*tail)) {
        printf("List is Empty\n");
        return;
    }
    n *head = (*tail)->next;
    if (head == *tail) {
        free(head);
        *tail = NULL;
    } else {
        (*tail)->next = head->next;
        free(head);
    }
    printf("Deleted from beginning\n");
}

void DelAtEnd(n **tail) {
    if (isEmpty(*tail)) {
        printf("List is Empty\n");
        return;
    }
    n *curr = (*tail)->next, *prev = *tail;
    if (curr == *tail) {
        free(*tail);
        *tail = NULL;
    } else {
        while (curr != *tail) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = (*tail)->next;
        free(*tail);
        *tail = prev;
    }
    printf("Deleted from end\n");
}

void DelAtPos(n **tail, int pos) {
    if (isEmpty(*tail)) {
        printf("List is Empty\n");
        return;
    }
    if (pos <= 1) {
        DelAtBegin(tail);
        return;
    }
    n *curr = (*tail)->next, *prev = *tail;
    int i = 1;
    while (i < pos && curr != *tail) {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (i == pos) {
        prev->next = curr->next;
        if (curr == *tail)
            *tail = prev;
        free(curr);
        printf("Deleted at position %d\n", pos);
    } else {
        printf("Position not found\n");
    }
}

void display(n *tail) {
    if (isEmpty(tail)) {
        printf("List is Empty\n");
        return;
    }
    n *temp = tail->next;
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main() {
    n *tail = NULL;
    int choice, value, pos;
    while (1) {
        printf("\n0. Create | 1. Insert at End | 2. Insert at Begin | 3. Insert at Position | ");
        printf("4. Delete at End | 5. Delete at Begin | 6. Delete at Position | ");
        printf("7. Display | 8. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                create(&tail);
                break;
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                InsAtEnd(&tail, value);
                printf("The list is: ");
                display(tail);
                break;
            case 2:
                printf("Enter value to insert at begin: ");
                scanf("%d", &value);
                InsAtBegin(&tail, value);
                printf("The list is: ");
                display(tail);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d%d", &value, &pos);
                InsAtPos(&tail, value, pos);
                printf("The list is: ");
                display(tail);
                break;
            case 4:
                DelAtEnd(&tail);
                printf("The list is: ");
                display(tail);
                break;
            case 5:
                DelAtBegin(&tail);
                printf("The list is: ");
                display(tail);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                DelAtPos(&tail, pos);
                printf("The list is: ");
                display(tail);
                break;
            case 7:
                display(tail);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
