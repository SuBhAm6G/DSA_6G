#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left,*right;
    int val;
    int lthread,rthread;
}node;

node *leftmost(node *root){
    if (root==NULL) return root;
    node *curr=root;
    while(curr->lthread==0){ //In a threaded tree, we cannot blindly go left — we must check lthread.
        curr=curr->left;
    }
    return curr;
}

void inorder(node *root){
    if(root==NULL) return;
    node *curr=leftmost(root);
    while(curr!=NULL){
        printf("%d ",curr->val);
        if(curr->rthread==1) curr=curr->right;
        else curr=leftmost(curr->right);
    }
}
int main() {
    
    
    return 0;
}
