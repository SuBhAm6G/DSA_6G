#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *left,*right;
    int val;
}node;

void preorder(node* root){
    if (root==NULL) return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    
    
    return 0;
}
