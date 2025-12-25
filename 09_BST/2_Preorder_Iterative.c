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

void preorder(node *root){
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }

    stack s;
    initStack(&s);
    push(&s, root);
    while(!isEmpty(&s)){
        node* x=pop(&s);
        printf("%d ",x->val);

        if(x->right) push(&s,x->right);
        if(x->left) push(&s,x->left);
    }
}
int main() {
    
    
    return 0;
}
