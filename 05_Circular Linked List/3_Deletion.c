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
    if(tail==NULL){
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

void DelAtBegin(n **tail){
    //Empty
    if(isEmpty(*tail)){
        printf("List is Empty\n");
        return;
    }
    //one node
    n *temp=(*tail)->next;
    if((*tail)->next==*tail){
        *tail=NULL;
        free(temp);
        return;
    }
    //general
    (*tail)->next=temp->next;
    free(temp);
}
void DelAtEnd(n **tail){
    //Empty
    if(isEmpty(*tail)){
        printf("List is Empty\n");
        return;
    }
    //one node
    n *temp=(*tail)->next;
    if((*tail)->next==*tail){
        *tail=NULL;
        free(temp);
        return;
    }
    while(temp->next!=(*tail)){
        temp=temp->next;
    }
    temp->next=(*tail)->next;
    n *next=*tail;
    *tail=temp;
    free(next);
}

void DelAtPos(n **tail, int pos){
    if(pos<1 || pos>getLength(*tail)){
        printf("Invalid Position\n");
    }
    else if(pos==1){
        DelAtBegin(tail);
    }
    else if(pos==getLength(*tail)){
        DelAtEnd(tail);
    }
    else{
        n *temp=(*tail)->next;
        for(int i=1; i<pos-1; i++){
            temp=temp->next;
        }
        n *next=temp->next;
        temp->next=next->next;
        free(next);
    }
}
void DelByVal(n **tail, int val){
    if(isEmpty(*tail)){
        printf("List is Empty\n");
        return;
    }

    n *current = (*tail)->next;
    n *prev = *tail;
    int found = 0;

    // Handle case where the list has only one node
    if (current == *tail && current->val == val) {
        free(current);
        *tail = NULL;
        printf("Node with value %d deleted.\n", val);
        return;
    }

    // Traverse the list to find the node
    do {
        if (current->val == val) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    } while (current != (*tail)->next);

    if (found) {
        // If the node to be deleted is the head
        if (current == (*tail)->next) {
            (*tail)->next = current->next;
        }
        // If the node to be deleted is the tail
        if (current == *tail) {
            *tail = prev;
        }
        prev->next = current->next;
        free(current);
        printf("Node with value %d deleted.\n", val);
    } else {
        printf("Node with value %d not found.\n", val);
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
    int choice, pos, val;
    while (1) {
        printf("\n--- Circular Linked List Deletion Menu ---\n");
        printf("1. Create (Insert at End)\n");
        printf("2. Display\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Delete at Position\n");
        printf("6. Delete by Value\n");
        printf("7. Exit\n");
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
                DelAtBegin(&tail);
                break;
            case 4:
                DelAtEnd(&tail);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                DelAtPos(&tail, pos);
                break;
            case 6:
                printf("Enter value: ");
                scanf("%d", &val);
                DelByVal(&tail, val);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
