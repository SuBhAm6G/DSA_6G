#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}node;

node* createNode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

//Queue
typedef struct QueueNode{
    node *treenode;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue{
    QueueNode *front,*rear;
}Queue;

Queue* createQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear=NULL;
    return q;
}

void Enqueue(Queue *Q, node* treenode){
    QueueNode *newnode=(QueueNode*)malloc(sizeof(QueueNode));
    newnode->treenode=treenode;
    newnode->next=NULL;

    if(Q->rear==NULL) {
        Q->front=Q->rear=newnode;
        return;
    }
    else{
        Q->rear->next=newnode;
        Q->rear=newnode;
    }
        
}

node* Dequeue(Queue *q){
    if(q->front==NULL)
        return NULL;
    QueueNode *temp=q->front;
    node *treenode=temp->treenode;
    q->front=q->front->next;
    if(q->front==NULL)
        q->rear=NULL;
        free(temp);
    return treenode;
}


node *insert(node *root, int val){
    node *newnode=createNode(val);
    if(root==NULL){
        root=newnode;
        return root;
    }
    else{
        Queue *q=createQueue();
        Enqueue(q,root);
        while(q->front!=NULL){
            node *temp=Dequeue(q);
            if(temp->left==NULL){
                temp->left=newnode;
                break;
            }
            else{
                Enqueue(q,temp->left);
            }
            if(temp->right==NULL){
                temp->right=newnode;
                break;
            }
            else{
                Enqueue(q,temp->right);
            }
        }
        free(q);
    }
    

    return root;
}

void inorder(node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    node *root=NULL;
    int n;
    printf("Enter how many nodes you want to enter: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter Node value of node %d: ",i+1);
        scanf("%d",&val);
        root=insert(root,val);
        printf("\n");
    }
    printf("Inorder Traversal: ");
    inorder(root);
    return 0;
}
