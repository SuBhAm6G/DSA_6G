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
    while(curr->lthread==0){
        curr=curr->left;
    }
    return curr;
}

node *inordersuccesor(node *curr){
    if(curr->rthread==1) return curr->right;
    curr=curr->right;
    while(curr!=NULL && curr->lthread==0){
        curr=curr->left;
    }
    return curr;
}

void deleteTree(node *root){
    if(root==NULL) return;
    node *curr=leftmost(root);
    while(curr!=NULL){
        node *temp=inordersuccesor(curr);
        free(curr);
        curr=temp;
    }
}

int main() {
    
    
    return 0;
}
