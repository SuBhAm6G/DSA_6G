#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}n;

int isEmpty(n *top){
    if(top==NULL)
        return 1;
    else
        return 0;
}
void Push(n **top){
    n *newnode=(n*)malloc(sizeof(n));
    printf("Enter value to push: ");
    scanf("%d", &newnode->val);
    newnode->next=*top;
    *top=newnode;
}

void Pop(n **top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d is popped", (*top)->val);
    *top=(*top)->next;
}

void Display(n *top){ 
    if(isEmpty(top)){
        printf("Stack Underflow\n");
        return;
    }
    n *temp=top;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp=temp->next;
    }
    printf("\n");
}

void peek(n *top){ 
    if(isEmpty(top)){ 
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", top->val);
}
int main() {
    n *top=NULL;
    int choice;
    do
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Push(&top);
            break;
        case 2:
            Pop(&top);
            break;
        case 3:
            Display(top);
            break;
        case 4:
            peek(top);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
