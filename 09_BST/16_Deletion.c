#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *right,*left;
    int val;
}node;

node *createNode(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->val=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* InsertBST(node *root,int val){
    if (root==NULL) return createNode(val);
    if (val<root->val) root->left=InsertBST(root->left,val);
    else if (val>root->val) root->right=InsertBST(root->right,val);
    return root;
}

node* findSmallest(node *root){
    if (root==NULL){
        printf("Empty Tree");
        return NULL;
    }
    node *curr=root;
    while(curr->left){
        curr=curr->left;
    }
    return curr;
}

//Function
node* DeleteNode(node *root, int key){
    if (root==NULL) return root;
    if (key<root->val) root->left=DeleteNode(root->left,key);
    else if(key>root->val) root->right=DeleteNode(root->right, key);
    else{
        if(root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp=root->left;
            free(root);
            return temp;
        }
        else{
            node *successor=findSmallest(root->right);
            root->val=successor->val;
            root->right=DeleteNode(root->right,successor->val);
        }
    }
    return root;
}
int main() {
    node *root=NULL;
    int n;
    printf("How many nodes, you want to enter: ");
    scanf("%d",&n);
    while(n--){
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        root = InsertBST(root,val);
    }
    return 0;
}
