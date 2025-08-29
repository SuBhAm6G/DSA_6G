#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

void InsAtPos(struct node *head,int pos,int count){
    if(pos>count){
        printf("Invalid Position\n");
        return;
    }
    struct node *newnode;
    newnode = malloc(sizeof(struct node));//memory is allocated, so the value stays even after end of function
    if(!newnode){
        printf("Memory allocation failed!\n");
        return; // Exit if malloc fails
    }
    struct node *temp=head;
    int i=0;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    printf("Enter the data for insertion: ");
    if (scanf("%d", &newnode->val) != 1) {
        printf("Invalid input.\n");
        free(newnode); // Free the allocated node to prevent memory leak
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;

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
    printf("Before Insertion:\n");
    display(head);
    printf("\n");

    int pos;
    printf("Enter position to insert new node: ");
    scanf("%d", &pos);
    InsAtPos(head,pos,count);
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