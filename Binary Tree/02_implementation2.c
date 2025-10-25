#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}n;

n* createNode(int data){
    n *newnode=(n*)malloc(sizeof(n));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

typedef struct queueNode{
    n *tree;
    struct queueNode *next;
}qn;

typedef struct queue{
    qn *front,*rear;
}q;

q* createQ(){
    q *Q;
    Q->front=NULL;
    Q->rear=NULL;
    return Q;
}

void enqueue(q *Q, n* treenode){
    qn *temp;
    if(Q->front==NULL){
        temp=(qn*)malloc(sizeof(qn));
        temp->tree=treenode;
        temp->next=NULL;
        Q->front=temp;
        Q->rear=temp;
    }
    else{
        temp=(qn*)malloc(sizeof(qn));
        temp->tree=treenode;
        temp->next=NULL;
        Q->rear->next=temp;
        Q->rear=temp;
    }
}

void dequeue(q *Q){
    if(Q->front==NULL){
        printf("Queue is empty\n");
        return;
    }
    qn *temp=Q->front;
    Q->front=Q->front->next;
    free(temp);
}
int main() {
    
    
    return 0;
}
