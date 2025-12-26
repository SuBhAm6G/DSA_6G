#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left,*right;
    int val;
}node;

node* CreateTree(){
    node* root=NULL;
    return root;
}

node* newNode(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

int count_external_nodes(node *root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL) return 1;
    return count_external_nodes(root->left)+count_external_nodes(root->right);
}
int main() {
    node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(12);
    root->right->right = newNode(18);
    root->left->left->left = newNode(1);
    root->left->left->right = newNode(4);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(8);
    root->right->left->left = newNode(11);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(17);
    root->right->right->right = newNode(20);

    printf("Number of external nodes in tree: %d\n", count_external_nodes(root));
    return 0;
}
