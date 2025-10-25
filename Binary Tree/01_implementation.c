#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

//to create newnode
node *createNode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
node* buildTree(){
    int data;
    printf(" Enter data (-1 for no node): ");
    scanf("%d",&data);
    if(data==-1)
        return NULL;
    node *newnode=createNode(data);
    printf("Left child of %d:",data);
    newnode->left=buildTree();
    printf("Right child of %d:",data);
    newnode->right=buildTree();
    return newnode;
}
int main() {
    node *root=buildTree();
    printf("--------------------------------------------------------\n");
    if(root==NULL) {
        printf("\nThe tree is empty.\n");
        return 0;
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    return 0;
}
