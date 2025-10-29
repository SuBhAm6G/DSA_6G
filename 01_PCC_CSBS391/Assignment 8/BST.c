#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;

node* createnode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insertNode(node *root,int data){
    node *newnode=createnode(data);
    if(root==NULL){
        root=newnode;
        return root;
    }
    node *curr=root;
    node *prev=NULL;
    while(curr!=NULL){
        prev=curr;
        if(data<curr->data){
            curr=curr->left;
        }
        else if(data>curr->data){
            curr=curr->right;
        }
        else{
            printf("Duplicate value %d not inserted.\n", data);
            free(newnode);
            return root;
        }
    }
    if(data>prev->data){
        prev->right=newnode;
    }
    else{
        prev->left=newnode;
    }
    return root;
}

void inorder(node *root){
    if(root==NULL){
        printf("Tree is empty.\n");
        return;
    }
    node* stack[100];
    int top=-1;
    node *curr=root;
    while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            stack[++top]=curr;
            curr=curr->left;
        }
        curr=stack[top--];
        printf("%d ",curr->data);
        curr=curr->right;
    }
}

void preorder(node *root){
    if(root==NULL){
        printf("Tree is empty.\n");
        return;
    }
    node *stack[100];
    int top=-1;
    stack[++top]=root;
    node *curr=NULL;
    while(top!=-1){
        curr=stack[top--];
        printf("%d ",curr->data);
        if(curr->right){
            stack[++top]=curr->right;
        }
        if(curr->left){
            stack[++top]=curr->left;
        }
    }
}

void postorder(node *root){
    if(root==NULL){
        printf("Tree is empty.\n");
        return;
    }
    node *stack1[100];
    node *stack2[100];
    int top1=-1;
    int top2=-1;
    stack1[++top1]=root;
    node *curr=NULL;
    while(top1!=-1){
        curr=stack1[top1--];
        stack2[++top2]=curr;
        if(curr->right){
            stack1[++top1]=curr->right;
        }
        if(curr->left){
            stack1[++top1]=curr->left;
        }
    }
    while(top2!=-1){
        curr=stack2[top2--];
        printf("%d ",curr->data);
    }
}
int main() {
    
    
    return 0;
}
