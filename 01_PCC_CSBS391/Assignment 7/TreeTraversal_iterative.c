#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}n;

n* createnode(int data){
    n *newnode=(n*)malloc(sizeof(n));
    if(newnode==NULL){
        printf("Memory error\n");
        exit(1);
    }
    newnode->val=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void insertion(n **root,int data){
    n *newnode=createnode(data);
    if(*root==NULL){
        *root=newnode;
        return;
    }
    n *current=*root;
    n *prev=NULL;
    while(current!=NULL){
        prev=current;
        if(data<current->val){
            current=current->left;
        }
        else if(data>current->val){
            current=current->right;
        }
        else{
            printf("Duplicate data\n");
            free(newnode);
            return;
        }
    }
    if(data<prev->val){
        prev->left=newnode;
    }
    else{
        prev->right=newnode;
    }
}

void Inorder(n *root){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    n *stack[50];
    int top=-1;
    n *current=root;
    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;
        }
        current=stack[top--];
        printf("%d ", current->val);
        current=current->right;
    }
}

void Preorder(n *root){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    n *stack[50];
    int top=-1;
    stack[++top]=root;
    while(top!=-1){
        n *current=stack[top--];
        printf("%d ", current->val);
        if(current->right){
            stack[++top]=current->right;
        }
        if(current->left){
            stack[++top]=current->left;
        }
    }
}

void Postorder(n *root){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    n *stack1[50];
    n *stack2[50];
    int top1=-1;
    int top2=-1;
    stack1[++top1]=root;
    while(top1!=-1){
        n *current=stack1[top1--];
        stack2[++top2]=current;
        if(current->right){
            stack1[++top1]=current->right;
        }
        if(current->left){
            stack1[++top1]=current->left;
        }
    }
    while(top2!=-1){
        n *current=stack2[top2--];
        printf("%d ",current->val);
    }
}
int main() {
    n *root=NULL;
    int choice, data;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert a node\n");
        printf("2. Inorder Traversal (Iterative)\n");
        printf("3. Preorder Traversal (Iterative)\n");
        printf("4. Postorder Traversal (Iterative)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertion(&root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                Preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                Postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
