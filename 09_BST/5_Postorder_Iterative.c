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

void Postorder(node *root){
    if(root==NULL) return;
    stack s1,s2;
    initStack(&s1);
    initStack(&s2);
    push(&s1, root);
    while(!isEmpty(&s1)){
        node *curr=pop(&s1);
        push(&s2,curr);
        if(curr->left) push(&s1,curr->left);
        if(curr->right) push(&s1,curr->right);
    }
    while(!isEmpty(&s2)){
        node *curr=pop(&s2);
        printf("%d ",curr->val);
    }
}
int main(){

    return 0;
}