#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

int getLength(struct node *head){
    if(!(head)){
        printf("List is empty.\n");
    }
    struct node* temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

void display(struct node *head){
    printf("Linked List: ");
    if(head == NULL){
        printf("is empty.\n");
        return;
    }
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d", temp->val);
        temp=temp->next;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf(" -> NULL");
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
    
    printf("You entered %d nodes", getLength(head));
    
    return 0;
}
