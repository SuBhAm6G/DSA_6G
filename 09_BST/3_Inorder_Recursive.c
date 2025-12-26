#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left,*right;
    int val;
}node;

void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}



int main() {
    
    
    return 0;
}
