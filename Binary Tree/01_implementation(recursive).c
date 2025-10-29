// 1. Write a program to implement insertion, deletion and traversal  of binary tree.
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;

node* createNode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* buildTree(){
    int data;
    printf("Enter data for the node (-1 for no node):");
    scanf("%d",&data);

    //Base Case
    if(data==-1) return NULL;

    node *newNode=createNode(data);

    printf("Left node of %d: ",data);
    newNode->left=buildTree();
    printf("Right node of %d: ",data);
    newNode->right=buildTree();

    return newNode;
}

void preorder(node *root){
    if(!root) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    node *root=NULL;
    root=buildTree();
    printf("\nPostorder: ");
    postorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    return 0;
}
