#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insertion(n **root, int data){
    n *newnode=createnode(data);
    if(*root==NULL){
        *root=newnode;
        return;
    }
    if(data<(*root)->val){
        insertion(&((*root)->left), data);
    }
    else if(data>(*root)->val){
        insertion(&((*root)->right), data);
    }
    else{
        printf("Duplicates not allowed\n");
        return;
    }
}
void inorder(n *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(n *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(n *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}
int main() {
    n *root = NULL;
    int choice, data;

    do {
        printf("\n--- Binary Search Tree Menu (Recursive) ---\n");
        printf("1. Insert a node\n");
        printf("2. Inorder Traversal (Recursive)\n");
        printf("3. Preorder Traversal (Recursive)\n");
        printf("4. Postorder Traversal (Recursive)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertion(&root, data); // Using the provided insertion function
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
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
