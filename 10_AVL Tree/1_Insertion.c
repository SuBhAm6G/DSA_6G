#include <stdio.h>
#include <stdlib.h>

typedef struct avlnode{
    struct avlnode* left,*right;
    int val;
    int height;
}node;

int height(node *n){
    if(n==NULL) return -1;
    return n->height;
}

int getBalance(node *n){
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}

int max(int a, int b){
    return a>b?a:b;
}
node* rightRotate(node *n3){
    node *n2=n3->left;
    node *temp=n2->right;
    //Rotation
    n2->right=n3;
    n3->left=temp;
    //update heights
    n3->height=1+max(height(n3->left),height(n3->right));
    n2->height=1+max(height(n2->left),height(n2->right));

    //new root
    return n2;
}

node* leftRotate(node *n1){
    node *n2=n1->right;
    node *temp=n2->left;

    //Rotations
    n2->left=n1;
    n1->right=temp;

    //update heights
    n1->height=1+max(height(n1->left),height(n1->right));
    n2->height=1+max(height(n2->left),height(n2->right));

    //new root
    return n2;
}

node *createnode(int key){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->val=key;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=0;
    return newnode;
}

node *InsertAVL(node *root, int key){
    if (root==NULL) return createnode(key);
    if(key<root->val) root->left=InsertAVL(root->left,key);
    else if(key>root->val) root->right=InsertAVL(root->right, key);
    else{
        printf("Duplicate Node\n");
        return root;
    }
    //update height of ancestor node
    root->height=1+max(height(root->left),height(root->right));
    int bf=getBalance(root);

    if (bf>1 && key<root->left->val){
        return rightRotate(root);
    }
    if (bf<-1 && key>root->right->val){
        return leftRotate(root);
    }
    if (bf>1 && key>root->left->val){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf<-1 && key<root->right->val){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main() {
    
    
    return 0;
}
