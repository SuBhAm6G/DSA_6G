#include <stdio.h>
#include <stdlib.h>

#define M 3

typedef struct node{
    int keys[M-1];
    struct node *child[M];
    int n; //current number of keys
}node;

node *createNode(){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->n=0;

    for(int i=0; i<M; i++){
        newnode->child[i]=NULL;
    }
    return newnode;
}

int search(node *root, int key){
    if (root==NULL) return 0;
    int i=0;
    // Find first key >= given key
    while(i<root->n && key>root->keys[i]) i++;
    // If key found
    if(i<root->n && key==root->keys[i]) return 1;
    // Else descend to appropriate child
    return search(root->child[i], key);
}

void insertSimple(node *root, int key){
    if (root->n == M-1){
        printf("Node full, cannot insert\n");
        return;
    }

    int i = root->n - 1;

    while (i >= 0 && key < root->keys[i]){
        root->keys[i + 1] = root->keys[i];
        i--;
    }

    root->keys[i + 1] = key;
    root->n++;
}

int main() {
    
    
    return 0;
}
