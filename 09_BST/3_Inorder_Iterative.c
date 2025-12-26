#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* left,*right;
    int val;
}node;

typedef struct stack{
    node *arr[100];
    int top;
}stack;

void initStack(stack *s){
    s->top=-1;
}

int isEmpty(stack *s){
    return s->top==-1;
}

void push(stack *s, node *item){
    s->arr[++s->top]=item;
}

node* pop(stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return NULL;
    }
    return s->arr[s->top--];
}

void Inorder(node *root){
    if(root==NULL) return;
    stack *s=(stack*)malloc(sizeof(stack));
    initStack(s);
    
    node *curr=root;
    while(curr!=NULL || !isEmpty(s)){
        while(curr!=NULL){
            push(s,curr);
            curr=curr->left;
        }
        curr=pop(s);
        printf("%d ",curr->val);
        curr=curr->right;
    }
    free(s);
}
int main(){

    return 0;
}