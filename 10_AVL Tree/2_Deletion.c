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

node *FindMin(node *root){
    node *current=root;
    while(current->left){
        current=current->left;
    }
    return current;
}

node *DeleteAVL(node *root, int key){
    if (root==NULL) return root;
    
    if (key<root->val) root->left=DeleteAVL(root->left, key);
    else if (key>root->val) root->right=DeleteAVL(root->right, key);
    else{
        //node with only one child or no child
        if((root->left==NULL)||(root->right==NULL)){
            node *temp=root->left?root->left:root->right;
            //no child case
            if(temp==NULL){
                temp=root;
                root=NULL;
            }
            else{
                //one child case
                *root=*temp;
            }
            free(temp);
        }
        else{
            //node with two children
            node *temp=FindMin(root->right);
            root->val=temp->val;
            root->right=DeleteAVL(root->right, temp->val);
        }
    }
    if (root==NULL) return root;

    //Height Update
    root->height=1+max(height(root->left), height(root->right));
    int bf=getBalance(root);
    if (bf>1 && getBalance(root->left)>=0){
        return rightRotate(root);
    }
    if (bf<-1 && getBalance(root->right)<=0){
        return leftRotate(root);
    }
    if (bf>1 && getBalance(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf<-1 && getBalance(root->right)>0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


int main() {
    
    
    return 0;
}
