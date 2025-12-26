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

node *Insertion(node *root, int key){
    node *newnode=createNode(key);
    if (root==NULL) return newnode;
    node *curr=root;
    node *parent=NULL;
    while(curr!=NULL){
        parent=curr;
        if (key<curr->val) curr=curr->left;
        else if(key>curr->val) curr=curr->right;
        else{
            printf("Duplicate Value");
            return root; //duplicate case
        }
    }
    if(key<parent->val) parent->left=newnode;
    else parent->right=newnode;
    return root;
}
//Function
int findSmallest(node *root){
    if (root==NULL){
        printf("Empty Tree");
        return 0;
    }
    node *curr=root;
    while(curr->left){
        curr=curr->left;
    }
    return curr->val;
}

node *largestnode(node *root){
    if (root==NULL){
        printf("Empty Tree");
        return NULL;
    }
    node *curr=root;
    while(curr->right){
        curr=curr->right;
    }
    return curr;
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
        root = Insertion(root,val);
    }
    int smallest = findSmallest(root);
    if(root!=NULL)
        printf("Smallest Node is: %d\n",smallest);
    
    node *largest = largestnode(root);
    if(largest!=NULL)
        printf("Largest Node is: %d\n",largest->val);
        
    return 0;
}
