// 1. Write a program to implement insertion, deletion and traversal  of binary tree.
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

typedef struct queuenode{
    node *treenode;
    struct queuenode *next;
}queuenode;

typedef struct Queue{
    queuenode *front,*rear;
}Queue;

Queue *createQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=NULL;
    return q;
}

void enqueue(Queue *q,node *treenode){
    queuenode *newnode=(queuenode*)malloc(sizeof(queuenode));
    newnode->treenode=treenode;
    newnode->next=NULL;

    if(q->rear==NULL){
        q->front=q->rear=newnode;
        return;
    }

    q->rear->next=newnode;
    q->rear=newnode;
}

node* dequeue(Queue *q){
    if(q->front==NULL) return NULL;
    node *result=NULL;
    queuenode *temp=q->front;
    result=temp->treenode;

    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    return result;
}

void destroyQueue(Queue *q){
    while(q->front!=NULL){  
        dequeue(q);
    }
    free(q);
}

node *createnode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    if(!newnode){
        printf("Memory error\n");
        return NULL;
    }
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insertNode(node *root, int data){
    node *newNode=createnode(data);
    if(root==NULL){
        root=newNode;
        return root;
    }
    Queue* q=createQueue();
    enqueue(q,root);
    while(q->front !=NULL){
        node *temp=dequeue(q);
        if(temp->left==NULL){
            temp->left=newNode;
            destroyQueue(q);
            return root;
        }
        else{
            enqueue(q,temp->left);
        }
        if(temp->right==NULL){
            temp->right=newNode;
            destroyQueue(q);
            return root;
        }
        else{
            enqueue(q,temp->right);
        }
    }
    return root;
}

void preorder(node *root){
    if(!root) return ;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root){
    if(!root) return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(node *root){
    if(!root) return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void deletedeepest(node *root, node* nodetodelete){
    if(root==NULL || root==nodetodelete){
        if(root==nodetodelete){
            free(root);
            root=NULL;
        }
        return;
    }

    Queue *q=createQueue();
    enqueue(q,root);
    while(q->front!=NULL){
        node *temp=dequeue(q);
        if(temp->left!=NULL){
            if(temp->left==nodetodelete){
                temp->left=NULL;
                free(nodetodelete);
                destroyQueue(q);
                return;
            }
            else{
                enqueue(q,temp->left);
            }
        }
        if(temp->right!=NULL){
            if(temp->right==nodetodelete){
                temp->right=NULL;
                free(nodetodelete);
                destroyQueue(q);
                return;
            }
            else{
                enqueue(q,temp->right);
            }
        }
    }
    destroyQueue(q);
}

node *deletenode(node *root, int key){
    if(root==NULL){
        printf("Tree is empty\n");
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        if(root->data==key){
            free(root);
            root=NULL;
        }
        return root;
    }
    node *nodetoDel=NULL;
    node *deepestNode=NULL;
    Queue *q=createQueue();
    enqueue(q,root);
    while(q->front!=NULL){
        deepestNode=dequeue(q);
        if(deepestNode->data==key){
            nodetoDel=deepestNode;
        }
        if(deepestNode->left!=NULL){
            enqueue(q,deepestNode->left);
        }
        if(deepestNode->right!=NULL){
            enqueue(q,deepestNode->right);
        }
    }
    if(nodetoDel!=NULL){
        nodetoDel->data=deepestNode->data;
        deletedeepest(root,deepestNode);
    }
    else{
        printf("Node with value %d not found in the tree\n",key);
    }
    destroyQueue(q);
    return root;
}
int main() {
    node *root=NULL;
    int r;
    printf("Enter value of root node: ");
    scanf("%d",&r);
    int n;
    printf("How many nodes you want to enter: ");
    scanf("%d",&n);
    root=insertNode(root,r);
    for(int i=1;i<n;i++){
        int data;
        printf("Enter value of node %d: ",i+1);
        scanf("%d",&data);
        root=insertNode(root,data);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    printf("Enter key to delete: ");
    int key;
    scanf("%d",&key);
    root=deletenode(root,key);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
