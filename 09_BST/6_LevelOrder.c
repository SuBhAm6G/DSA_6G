#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left,*right;
    int val;
}node;

typedef struct qnode {
    node *data;
    struct qnode *next;
} qnode;

typedef struct queue {
    qnode *front;
    qnode *rear;
} queue;

void initQueue(queue *q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(queue *q) {
    return q->front == NULL;
}

void enqueue(queue *q, node *item) {
    qnode *temp = (qnode*)malloc(sizeof(qnode));
    temp->data = item;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

node* dequeue(queue *q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }

    qnode *temp = q->front;
    node *item = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return item;
}

void LeveOrder(node *root){
    if (root==NULL) return;
    queue *Q=(queue*)malloc(sizeof(queue));
    initQueue(Q);
    enqueue(Q,root);
    while(!isQueueEmpty(Q)){
        node *curr=dequeue(Q);
        printf("%d ",curr->val);
        if(curr->left) enqueue(Q,curr->left);
        if(curr->right) enqueue(Q,curr->right);
    }
    free(Q);
}

int main() {
    
    
    return 0;
}
