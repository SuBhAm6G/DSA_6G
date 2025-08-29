#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

void DelAtPos(struct node **head, int pos, int count){
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if(pos>count || pos<1){
        printf("Invalid Position\n");
        return;
    }
    //For deleting position 1(head)
    struct node *temp=*head;
    if(pos==1){
        *head=temp->next;
        free(temp);
    }
    struct node *nextnode=NULL;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
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
    int count=0;
    int choice=1;
    while(choice){
        count++;
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

    int pos;
    printf("Enter position to delete node: ");
    scanf("%d", &pos);
    DelAtPos(&head,pos,count);
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